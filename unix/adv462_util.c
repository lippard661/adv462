/*
 * adv462_util.c -- the "site-supplied" routines that Gary Palter's
 * Adventure expects (see the comments near the top of the main program),
 * for gfortran on Unix.  The Multics versions are in
 * ../Multics/adv462_io_.pl1 (and addr, size, getime).
 *
 * The game keeps its whole state in eleven common blocks.  At startup it
 * calls addr and size to record where each block is and how long it is,
 * then:
 *   ldcomn(.true., ...)        loads the "system" image (the database
 *                              already read in), if one exists;
 *   ldcomn(.false., name, ...) loads a game saved by SUSPEND (RESTORE);
 *   svcomn(.false., name, ...) saves the current game (SUSPEND);
 *   svcomn(.true., ...)        saves a new system image (wizard's
 *                              maintenance mode).
 *
 * The program is compiled with -fdefault-integer-8, so every Fortran
 * INTEGER and LOGICAL is 8 bytes.  A saved image is simply the bytes of
 * the eleven blocks, one after another; a file whose length doesn't match
 * the current program's blocks is rejected.
 *
 * Files:
 *   database:      $ADV462_DATA (default ADV462_DIR/adventure.data)
 *   system image:  $ADV462_DIR/adventure.newgame
 *                  (default /usr/local/share/adv462/adventure.newgame)
 *   saved games:   $ADV462_SAVEDIR/<name>.adv462
 *                  (default $HOME/.adv462/<name>.adv462; name defaults to "game")
 */

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define NBLOCKS 11
#define NAMECHARS 10

typedef int64_t fint;           /* Fortran INTEGER with -fdefault-integer-8 */

#ifndef ADV462_DIR
#define ADV462_DIR "/usr/local/share/adv462"
#endif

/*
 * call advdat(path): the default database path, $(ADV462_DIR)/adventure.data,
 * blank-padded into a Fortran CHARACTER variable (gfortran passes its length
 * as a hidden trailing argument).
 */
void
advdat_(char *buf, size_t len)
{
	char path[1024];
	size_t n;

	snprintf(path, sizeof(path), "%s/adventure.data", ADV462_DIR);
	n = strlen(path);
	if (n > len)
		n = len;
	memcpy(buf, path, n);
	memset(buf + n, ' ', len - n);
}

/* call addr(x, cmadrs(1,n)): store the address of x in the first word. */
void
addr_(void *x, fint *where)
{
	where[0] = (fint)(intptr_t)x;
}

/* size(first, last): number of words from first through last inclusive. */
fint
size_(void *first, void *last)
{
	return (fint)(((char *)last - (char *)first) / (long)sizeof(fint)) + 1;
}

/*
 * Build the file name.  fname holds ten characters in Fortran A1 format:
 * one character in the first byte of each 8-byte word.
 */
static int
image_path(fint system, const fint *fname, char *path, size_t len)
{
	const char *dir;
	char name[NAMECHARS + 1];
	int i, n = 0;

	if (system) {
		dir = getenv("ADV462_DIR");
		if (dir == NULL || *dir == '\0')
			dir = ADV462_DIR;
		return snprintf(path, len, "%s/adventure.newgame", dir) <
		    (int)len ? 0 : -1;
	}

	for (i = 0; i < NAMECHARS; i++) {
		unsigned char c = *(const unsigned char *)&fname[i];

		if (c == ' ' || c == '\0')
			break;
		if (c == '/' || c == '.')	/* keep saves in the save dir */
			c = '_';
		name[n++] = (char)c;
	}
	name[n] = '\0';
	if (n == 0)
		snprintf(name, sizeof(name), "game");

	dir = getenv("ADV462_SAVEDIR");
	if (dir != NULL && *dir != '\0')
		return snprintf(path, len, "%s/%s.adv462", dir, name) <
		    (int)len ? 0 : -1;

	dir = getenv("HOME");
	if (dir == NULL || *dir == '\0')
		dir = ".";
	/* make $HOME/.adv462 if needed; ignore failure, fopen will report */
	{
		char d[1024];

		if (snprintf(d, sizeof(d), "%s/.adv462", dir) < (int)sizeof(d))
			(void)mkdir(d, 0700);
	}
	return snprintf(path, len, "%s/.adv462/%s.adv462", dir, name) <
	    (int)len ? 0 : -1;
}

static long
total_bytes(const fint *cmszes)
{
	long total = 0;
	int i;

	for (i = 0; i < NBLOCKS; i++)
		total += (long)cmszes[i] * (long)sizeof(fint);
	return total;
}

/*
 * ldcomn(l, fname, cmadrs, cmszes).  On any failure the common blocks are
 * left untouched, so the player simply continues in a fresh game (as the
 * RESTORE comment in the main program says).
 */
void
ldcomn_(fint *l, fint *fname, fint *cmadrs, fint *cmszes)
{
	char path[1100];
	FILE *fp;
	char *buf, *p;
	long want, got;
	int i;

	if (image_path(*l, fname, path, sizeof(path)) != 0)
		return;
	if ((fp = fopen(path, "rb")) == NULL) {
		if (!*l)
			printf(" (no saved game %s)\n", path);
		return;
	}
	want = total_bytes(cmszes);
	if ((buf = malloc(want + 1)) == NULL) {
		fclose(fp);
		return;
	}
	got = (long)fread(buf, 1, want + 1, fp);
	fclose(fp);
	if (got != want) {
		printf(" (%s is not a saved game for this version)\n", path);
		free(buf);
		return;
	}
	for (i = 0, p = buf; i < NBLOCKS; i++) {
		size_t n = (size_t)cmszes[i] * sizeof(fint);

		memcpy((void *)(intptr_t)cmadrs[4 * i], p, n);
		p += n;
	}
	free(buf);
}

/* svcomn(l, fname, cmadrs, cmszes). */
void
svcomn_(fint *l, fint *fname, fint *cmadrs, fint *cmszes)
{
	char path[1100];
	FILE *fp;
	int i, ok = 1;

	if (image_path(*l, fname, path, sizeof(path)) != 0 ||
	    (fp = fopen(path, "wb")) == NULL) {
		printf(" I am sorry, but I can't create or find your file.\n");
		return;
	}
	for (i = 0; i < NBLOCKS; i++) {
		size_t n = (size_t)cmszes[i] * sizeof(fint);

		if (fwrite((void *)(intptr_t)cmadrs[4 * i], 1, n, fp) != n)
			ok = 0;
	}
	if (fclose(fp) != 0)
		ok = 0;
	if (!ok)
		printf(" I am sorry, but I couldn't save your game.\n");
}
