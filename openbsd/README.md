# OpenBSD port

A port of `games/adv462` that builds `../unix/` with gfortran from `lang/gcc` (the `fortran` module).

To build:

1. Copy this directory to `/usr/ports/mystuff/games/adv462`.
2. Tag the repository `v1.0` on GitHub.
3. Run `make makesum` to create `distinfo`, then `make package`.

It installs:

- `bin/adv462`;
- the man page;
- `share/adv462/adventure.data`;
- `share/adv462/adventure.newgame`, made during the build by running the game once in magic mode;
- the writable game directory `/usr/games/adv462` (root:games, mode 775). The game prefers files there to the
  ones in `share/adv462`, and magic mode saves its new `adventure.newgame` there. The directory is kept when the
  package is removed.

No patches are needed: the portable source is generated from the Multics source by `../unix/mkunix.py` and
kept in the repository.
