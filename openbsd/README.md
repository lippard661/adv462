# OpenBSD port

A port of `games/adv462` that builds `../unix/` with gfortran from `lang/gcc/15`, as adv550 does.

Signed packages built from this port for OpenBSD 7.9 on amd64 are here as `adv462-`*version*`.tgz` (use the newest). They can be
verified with the signify public key https://www.discord.org/lippard/software/discord.org-2026-pkg.pub.
It needs `lang/gcc/15`'s runtime libraries, which `pkg_add` installs as a dependency.

To build:

1. Copy this directory to `/usr/ports/mystuff/games/adv462`.
2. Tag the repository `v${V}` on GitHub, where V is set in the Makefile (1.1 added unveil and pledge; 1.2 moved the game directory to /var/games/adv462; 1.3 falls back to the installed image when the game directory's copy is unusable).
3. Run `make makesum` to create `distinfo`, then `make package`.

It installs:

- `bin/adv462`;
- the man page;
- `share/adv462/adventure.data`;
- `share/adv462/adventure.newgame`, made during the build by running the game once in magic mode;
- the writable game directory `/var/games/adv462` (root:games, mode 775). The game prefers files there to the
  ones in `share/adv462`, and magic mode saves its new `adventure.newgame` there. Run magic mode as root or a
  member of `games`, with a umask that leaves the file readable by others (e.g. 022). If the copy there can't
  be read, or was made by a different build, the game falls back to the installed one. The directory is kept when the
  package is removed.

No patches are needed: the portable source is generated from the Multics source by `../unix/mkunix.py` and
kept in the repository.
