# adv462

**Adventure 1.2 (462 points)**, the version of Colossal Cave Adventure that ran on Honeywell's Phoenix
Multics system in 1980.

This repository preserves the surviving listings of that game as transcribed artifacts. It is also working
toward a playable version on Multics and, if feasible, on OpenBSD, following the pattern of
[adv550](https://github.com/lippard661/adv550).

## What this version is

- **Base:** Don Woods' 350-point Fortran Adventure (1977), after Will Crowther's original. Woods' data and
  code are recognizable throughout.
- **Engine:** Gary Palter's MIT-Multics Fortran port of Woods. Palter's hallmarks are all present:
  - the common blocks (`/msccom/`, `/ioscom/`, `/mtdcom/`);
  - five-character words packed with `code1`/`code2`;
  - the `scrmbl` vocabulary hash;
  - common-block save and restore through `svcomn`/`ldcomn`;
  - Palter named as a developer in the game's opening message.
- **Additions:** early Dave Platt material from before the 1984 A-code release of his 550-point game:
  rooms 141–217, objects 65–98, messages 202–270 and new vocabulary. The code implements it inside Palter's
  engine; it is not Platt's own code. The rooms are often word for word Platt's 1984 text, but show an earlier
  state:
  - the ice tunnels are "under construction";
  - there is no safe puzzle;
  - the wheat-stone bridge is permanent;
  - the fog rooms are separate numbered rooms;
  - there are rooms (the marble corridor, 143–147) that Platt 1984 doesn't have.
- **Local changes:**
  - new verbs (FAST, FULL, LISTEN, TURNS, SLAY, STOP, "." for the version);
  - named SUSPEND/RESTORE;
  - a news message dated May 1980;
  - a maximum score of 462.
  Maintained by Jim Lippard (`jjl.sct`, `lippard.scouting@pco-multics`) as part of the Scouting project
  (Explorer Post 414) on the Phoenix Multics system. It ran from `>udd>MED>Kaiser>Lippard`, with storage
  quota courtesy of Wendell Garry Kaiser of Honeywell.
- **Source file name:** `adventure_.fortran`. On Multics, a trailing underscore marks a subroutine rather
  than a command. The Fortran program was presumably invoked from a small PL/I `adventure` command, which
  would also have supplied the routines missing from the listing (`addr`, `size`, `ldcomn`, `svcomn`,
  `getime`). That wrapper does not survive.

No other copy of this version is known to exist.

## Status

| Step | State |
|---|---|
| 1. Artifacts: transcriptions and notes | done, see [`artifacts/`](artifacts/) |
| 2. Working Multics version: bugs fixed, TAKE/DROP ALL finished, PL/I wrapper and missing routines supplied | in progress |
| 3. OpenBSD / gfortran port and package, reading the same data file | planned |

## Directory structure

```text
adv462/
├── README.md                 # This file
├── LICENSE                   # BSD license for Jim Lippard's contributions
└── artifacts/                # Transcriptions of the 1980 listings, uncorrected
    ├── README.md             # What each file is, and transcription conventions
    ├── multics/              # This game: adventure_.fortran, adventure.data, notes
    │   └── transcription-source/   # Tab-separated source and render script for adventure.data
    └── gcos/                 # Related artifact: the separate GCOS port of Woods 350
```

## Licensing and credits

The BSD license covers Jim Lippard's contributions: the transcriptions, notes, fixes and porting work.
Will Crowther and Don Woods retain whatever rights they hold in Adventure, Gary Palter in his Multics port,
and Dave Platt in his game content.

Transcription and analysis by Jim Lippard, with assistance from Claude (Anthropic), September 2026.
