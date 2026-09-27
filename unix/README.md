# adv462 on Unix

A port of the Multics game to gfortran, reading the same `../Multics/adventure.data`.

| File | What it is |
|---|---|
| `mkunix.py` | Generates `adv462.f` from `../Multics/adventure_.fortran`. The Multics source is the master copy; every fix is made there. |
| `adv462.f` | The generated source (checked in, so Python is needed only to regenerate it) |
| `adv462_util.c` | The site routines in C: `addr`, `size`, `ldcomn`, `svcomn`, and `advdat` (the default data path) |
| `Makefile` | Builds `adv462` and `adventure.newgame` (the database read in and saved in magic mode), and installs both with the man page |
| `adv462.6` | Man page |

## Building

Needs gfortran 10 or later and a C compiler:

```sh
make
make install      # PREFIX=/usr/local by default
```

To play without installing:

```sh
ADV462_DIR=. ./adv462
```

`mkunix.py` changes very little: the list is at its top and in [`../Multics/CHANGES.md`](../Multics/CHANGES.md).
The program runs with 64-bit integers (`-fdefault-integer-8`), since it was written for 36-bit words and packs
five six-bit characters into one.

Suspended games go in `~/.adv462/` (or `$ADV462_SAVEDIR`). They are raw images of the common blocks, so they
only load into a build of the same version on the same kind of machine. A file of the wrong length is refused.
