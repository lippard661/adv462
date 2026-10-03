# adv462

**Adventure 1.2 (462 points)**, the version of Colossal Cave Adventure that ran on Honeywell's Phoenix
Multics system in 1980.

This repository preserves the surviving listings of that game as transcribed artifacts, and makes the game
playable again on Multics and on Unix (with an OpenBSD port), following the pattern of
[adv550](https://github.com/lippard661/adv550).

No other copy of this version is known to exist.

## What this version is

- **Base:** Don Woods' 350-point Fortran Adventure (1977), after Will Crowther's original (1976). Woods' data
  and code are recognizable throughout.
- **Engine:** Gary Palter's MIT-Multics Fortran port of Woods. Palter's hallmarks are all present:
  - the common blocks (`/msccom/`, `/ioscom/`, `/mtdcom/`);
  - five-character words packed with `code1`/`code2`;
  - the `scrmbl` vocabulary hash;
  - common-block save and restore through `svcomn`/`ldcomn`;
  - Palter named as a developer in the game's opening message.

  Palter's port itself doesn't survive, but a descendant does: a SEL-32 port printed in March 1979 and
  transcribed by Arthur O'Dwyer (HORV0350). About three quarters of this program's executable lines match
  it, in the same order.
- **Additions:** Dave Platt material related to his 550-point game: rooms 141–217, objects 65–98, messages
  202–270 and new vocabulary. The new creatures and puzzles (the slime, ogre, djinn, basilisks, PHUGGG) are
  coded by hand in Fortran inside Palter's engine, not written in Platt's later A-code. Who wrote that code is
  an open question; see [Lineage](#lineage).
  - **"Platt 1984":** the only surviving source of Platt's game is his A-code database dated 18 September
    1984 (preserved by Mike Arnautov and in the IF Archive). "Platt 1984" in these notes means that file. The
    game itself was released in 1979.
  - **What this copy shows:** the rooms here are often word for word the 1984 text, but differ from it in
    ways that look like an earlier stage of Platt's work, not a cut-down copy of it:
    - the ice tunnels are "under construction";
    - there is no safe puzzle;
    - the wheat-stone bridge is permanent;
    - the fog rooms are separate numbered rooms;
    - there are rooms (the marble corridor, 143–147) that Platt 1984 doesn't have;
    - the mithril ring is only a treasure, without the powers it gains later (see [Lineage](#lineage));
    - the singing sword just "sings quietly to itself", with none of its later repertoire.
  - **The marble corridor and crystal medallion** are not in the 1984 source. They look more like earlier Platt
    material that was later cut than like Multics additions, though that isn't certain:
    - The corridor's rooms (143–147) and motion words (78 STAIRS, 79 GARDEN) are numbered inside the Platt
      block, before rooms and words that are in the 1984 source, rather than appended after it.
    - The medallion lies in the corridor's garden.
    - The corridor is entered by going north from Woods' Y2 (room 33), whose description was not changed to
      mention a north passage.
  - **The bulletin board** is the one Platt-range item that may be local. It displays the May 1980 news, and
    Platt 1984 has a NEWS command instead.
- **New verbs**, all implemented here in Palter's engine:
  - **From Platt:** FAST and FULL, STOP (as QUIT), and the magic words PHUGGG and MELENKURION. All are in the
    1984 source with the same meanings, so they probably came with the Platt material. The May 1980 news still
    announces FAST and FULL as new commands, since they were new to players of this game.
  - **From Palter:** SLAY (as KILL) is already in Palter's port as preserved in HORV0350. It is not in Woods,
    and it is also in Platt 1984, appended to the same list (`KILL, ATTACK, FIGHT, HIT, STRIKE, SLAY`).
  - **"." for the version** follows a Multics convention. The "." request of Multics subsystems (most notably
    those built with `ssu_`, the subsystem utility written by Gary Palter) identifies the subsystem and its
    version. It is not in Palter's portable Adventure as preserved in HORV0350, or in Platt 1984, so it was
    probably added on Multics in that tradition.
  - **Not in Platt 1984, possibly local:** LISTEN and TURNS.
- **Local changes:**
  - named SUSPEND/RESTORE;
  - a news message dated May 1980, announcing about 50 new rooms;
  - a maximum score of 462.

  Maintained by Jim Lippard (`jjl.sct`, `Lippard.Scouting@PCO-Multics`) as part of the Scouting project
  (Explorer Post 414) on the Phoenix Multics system. It ran from `>udd>MED>Kaiser>Lippard`, with storage
  quota courtesy of Garry Kaiser of Honeywell. Jim's own 1980 changes were small: his name in the game, an
  unfinished TAKE/DROP ALL inked on the listing, and a note on packing text in base 90 so it could be in mixed
  case. He is confident he did not write the code for the slime, ogre, djinn, basilisks or PHUGGG, and doubts
  that he added the new rooms.
- **Source file name:** `adventure_.fortran`. On Multics, a trailing underscore marks a subroutine rather
  than a command. The Multics Fortran compiler of 1980 names a main program's entry point `main_`, so
  `adventure_` could not be typed as a command at all. It must have been run by a small `adventure` command
  calling `adventure_$main_`, probably written in PL/I along with the routines missing from the listing
  (`addr`, `size`, `ldcomn`, `svcomn`, `getime`). None of these survive; [`Multics/`](Multics/) has new ones,
  with the command named `adv462`.

## Lineage

| Date | Event | Source |
|---|---|---|
| 1976 | Will Crowther's original Adventure, in Fortran on the PDP-10 | |
| 1977 | Don Woods' 350-point version, also Fortran on the PDP-10 | |
| by November 1977 | Gary Palter's port on MIT-Multics, written to be portable and sent out with a "conversion guide" | Comments in HORV0350; Dick Reynolds' derived "HCSD version 01.112777" |
| 21 March 1979 | SEL-32 descendant of Palter's port printed (Reynolds, then Ned Horvath and C. Norwood, 1978) | HORV0350 |
| 1978–79 | Dave Platt, at Honeywell's Los Angeles Development Center, starts from "a FORTRAN IV implementation of the original Crowther/Woods code" that reached LADC on a Honeywell user-group source tape, and "might actually have passed through Multics on its way to us" | Platt, email to Eric Swenson, 12 September 2026 |
| 1 December 1979 | Platt's release notice for his 550-point Adventure on CP-V (Xerox Sigma-9). It is already his own design: a small executive written in Fortran, running game logic written in his A-code | Ken Wellsch's C version, posted to net.sources.games 7 July 1986 (Wellsch rewrote the Sigma-9 version, keeping the executive and A-code design) |
| 12 May 1980 | `adventure_.fortran` and `adventure.data` (this game) printed on Phoenix Multics; the game's news is dated May 1980 | Printer headers, [`artifacts/`](artifacts/) |
| after 1979 | Platt reimplements the executive in PL-6 for CP-6 | Platt, 2026 |
| 18 January 1983 | Platt, writing from CP-6 at LADC to Jim Lippard on Phoenix Multics, lists the sources of his material and notes differences between versions of his game | Platt, email to Jim Lippard (Jim's papers; not reproduced) |
| 15 July 1983 | The separate GCOS port of Woods 350 printed on Phoenix Multics | [`artifacts/gcos/`](artifacts/gcos/) |
| 18 September 1984 | Date of Platt's surviving A-code source ("Platt 1984"), preserved in the IF Archive together with the PL-6 munger and executive | Mike Arnautov's README, 2003 |
| mid-1980s | Prime FORTRAN 77 version of Platt's executive and munger in circulation, "converted to Prime F77 by Anon, on an unknown date" | Header of the F77 executive |
| 29 March 1989 | Arnautov's version 09.02 at Glaxo, optimised for Prime and with his own additions | Header of the F77 executive |
| 26 January 2003 | Arnautov reconstructs the mid-1980s F77 sources by stripping his later additions from the Glaxo 1989 versions, found in a private archive. He writes: "I am unaware of any other significant differences from Dave Platt's original code." These sources are the basis of [adv550](https://github.com/lippard661/adv550). | Arnautov's README |
| 2026 | This game transcribed and revived | This repository |

### What the evidence says about Platt and this game

In his own words, Platt started from "a FORTRAN IV implementation of the original Crowther/Woods code - it came
to Honeywell LADC on one of the Honeywell user-group source distribution tapes, and might actually have passed
through Multics on its way to us." He then developed "the A-code system" and made "changes … to the cave
structure/database." His "original FORTRAN release" was followed by "the later PL-6 re-implementation for CP-6".

- **Platt's released game ran on his own engine.** The 1979 CP-V release was already an executive running
  A-code, not a modified Woods program. Wellsch rewrote it from the Sigma-9, where PL-6 did not run, and kept
  that design. The surviving FORTRAN 77 executive is a table-driven A-code interpreter, and none of Woods' or
  Palter's routines or data structures appear in it. It descends from the CP-V Fortran by way of the Prime
  conversion, not from PL-6:
  - Platt recognizes it as his original Fortran code, and Arnautov knew of no significant differences from it.
  - Its style (hundreds of GOTOs, arithmetic IFs, almost no block IFs) is that of the older Fortran, not of a
    translation from structured PL-6.

  What carried over from Woods and Palter were features rather than code. The executive's system-dependent
  routines are HOURS, NEWS and SVAR, and Arnautov recalls that the game as played in the 1980s enforced a delay
  before a saved game could be restored. Opening hours and a restore latency are Woods' and Palter's; this game
  has them too, along with its news.
- **Before A-code, his starting point was probably Palter's port.** Palter's was the Multics Fortran Adventure,
  built to be ported and sent out with a conversion guide, and Platt says his copy may have come through
  Multics. The vocabulary supports this. SLAY is Palter's addition to Woods' vocabulary. Platt kept it in his
  A-code, as the last word of the same list (`KILL, ATTACK, FIGHT, HIT, STRIKE, SLAY`), so his vocabulary came
  from Palter's database rather than Woods' own. On its own, SLAY is a natural synonym that two people could
  have added independently.
- **This game looks like the stage in between.** It has Palter's engine and Palter's version of the Woods
  database, with Platt's material coded by hand in Fortran rather than in A-code. The listing was printed five
  months after Platt's December 1979 release, but its Platt rooms show an earlier stage of his work (see above).
  Two readings fit:
  1. Platt first added his material directly to Palter's port, before writing A-code. A copy of that stage
     reached Phoenix Multics and was still being played and extended there in 1980.
  2. Someone at Honeywell took material from Platt's 1979 release and coded it into Palter's engine by hand.
     This would more likely have produced faithful copies of the 550 rooms and messages than the earlier-looking
     versions found here.

  The first reading fits the evidence better.
- **Platt's 1983 email shows the game changing in stages.** Writing to Jim in January 1983, Platt listed the
  books, stories, radio and television that his material borrows from, and mentioned features that differed
  between versions:
  - **The mithril ring** gets you across the wheat-stone bridge, and in the CP-6 version it also deflects the
    dwarves' knives four times out of five. Platt 1984 has both powers, with the knife defence at exactly
    those odds. In this game the ring has neither: it is only a treasure the ogre leaves behind, and nothing in
    the program or the travel table uses it. So the ring marks three stages: this game, the CP-V game, and the
    CP-6 game.
  - **The singing sword's repertoire** included, by 1983, a joke that Platt said might not be in the version
    Jim knew: the sword whistling Edgard Varèse's *Ionisation*, a piece for thirteen percussionists. It is not
    in Platt 1984 or in any other surviving version. So the 1984 A-code is not a complete record of everything
    Platt put into the game, and in 1983 differing versions were in circulation. In this game the sword has no
    repertoire at all.
  - **Of the sources Platt credits, about half are already in this game:** the mithril ring, the singing sword
    destroying the ogre, MELENKURION, peelgrunt, the Valley of the Stone Faces, the gooseberry goblins, the
    statue's clue and the minotaur, the London Dry djinn, the Ruby Yacht of Omar Khayyam, the mushroom wearing
    off (word for word as in 1984), the Mountain King and his audience hall, and the Sorcerer's Lair. The rest
    appear only in Platt 1984: THURB and the ice tunnels (here still "under construction"), the Fourier
    passage, the safe and Rover, Darwin the tortoise, the pirate's beach with its two moons, and the crystal
    sculpture.
  - **The crystal sculpture** in Platt 1984 changes into a series of animals (a pig, an eel, an emu, an elf, a
    mouse and so on), each the name of a CP-V or CP-6 program or module. The last is not: it ends as "a crude
    sculpture of a very bedraggled phoenix". Platt described the phoenix as a dig at a group of software
    developers he declined to name. Jim, who became a Multics developer later in 1983, takes it as aimed at
    Honeywell's Multics developers in Phoenix: Multics, like CP-6, was a minority operating system at Honeywell
    alongside GCOS. This game has no sculpture.
- **What would settle it:**
  - **Platt's memory of the stage before A-code.** Did his material first live in the Woods program he started
    from, and did a copy of it go anywhere, such as Phoenix?
  - **His fan-fold listing of the original CP-V FORTRAN release.** Since that release was already A-code, the
    listing will probably show his own executive, not Palter's engine. Any leftovers would still count: Palter's
    word packing (`code1`/`code2`), `scrmbl`, or save and restore through `ldcomn`/`svcomn`. Four-character word
    packing like the GCOS port's would point to GCOS instead.

### Other Honeywell Adventures

- **GCOS:** a separate port of Woods 350, found with these listings and transcribed in
  [`artifacts/gcos/`](artifacts/gcos/). It is not an ancestor of this game.
- **Multics PL/I:** a PL/I translation of Woods, written (by "BRD") for Stanford University's IBM 360 under
  WYLBUR, and later ported to Multics by Charles Anthony ("CAC"). It is unrelated to Palter's port and to this
  game. Its IBM origin shows in the code Anthony commented out, such as a terminal-read routine declared
  `options (asm inter)`.

## Status

| Step | State |
|---|---|
| 1. Artifacts: transcriptions and notes | done, see [`artifacts/`](artifacts/) |
| 2. Working Multics version: bugs fixed, TAKE/DROP ALL finished, mixed-case text supported and the database converted to mixed case, PL/I wrapper and missing routines supplied | done, see [`Multics/`](Multics/); compiles, binds and runs on MR12.8 (DPS8M) |
| 3. Unix / gfortran port and OpenBSD package, reading the same data file | done, see [`unix/`](unix/) and [`openbsd/`](openbsd/); play-tested on Linux, packaged on OpenBSD 7.9 (amd64) |

Signed OpenBSD packages for OpenBSD 7.9 on amd64 are in [`openbsd/`](openbsd/) as `adv462-`*version*`.tgz`; use the newest.
It can be verified with the signify public key
https://www.discord.org/lippard/software/discord.org-2026-pkg.pub

[`Multics/CHANGES.md`](Multics/CHANGES.md) lists every change from the 1980 listings. Among them, the working copy
finishes both of Jim's 1980 experiments on the listing: TAKE/DROP ALL, and packing text in base 90 instead of 64,
which lets the database be in mixed case.

### Porting to Unix

The port was feasible with little change, so it is a generated copy rather than a fork:

- `unix/mkunix.py` makes `unix/adv462.f` from the Multics source by replacing a few machine-dependent routines;
- a small C file supplies the save and restore routines;
- gfortran compiles the 1970s Fortran with `-std=legacy` and 64-bit integers, since the program packs five
  characters into each 36-bit word. They are now packed in base 90 rather than six bits apiece, which is what
  makes mixed-case text possible (see [`Multics/CHANGES.md`](Multics/CHANGES.md)).

Every fix is made once, in the Multics source, and both versions read the same `adventure.data`.

## Directory structure

```text
adv462/
├── README.md                 # This file
├── LICENSE                   # BSD license for Jim Lippard's contributions
├── artifacts/                # Transcriptions of the listings (1980; GCOS 1983), uncorrected
│   ├── README.md             # What each file is, and transcription conventions
│   ├── Multics/              # This game: adventure_.fortran, adventure.data, notes
│   │   └── transcription-source/   # Tab-separated source and render script for adventure.data
│   └── gcos/                 # Related artifact: the separate GCOS port of Woods 350
├── Multics/                  # The working game for Multics (the master copy)
│   ├── README.md             # How to build and run it
│   ├── CHANGES.md            # Every change from the listings
│   ├── adventure_.fortran    # The game, corrected
│   ├── adventure.data        # The database, corrected
│   ├── adv462.pl1            # The "adv462" command
│   ├── adv462_io_.pl1        # Save/restore and database attachment
│   ├── addr.pl1, size.pl1, getime.pl1   # Other site routines
│   ├── bound_adv462_.bind    # Bindfile
│   └── build.ec              # Builds and binds bound_adv462_
├── unix/                     # gfortran port
│   ├── mkunix.py             # Generates adv462.f from ../Multics/adventure_.fortran
│   ├── adv462.f              # Generated source
│   ├── adv462_util.c         # Site routines in C
│   ├── Makefile, adv462.6, README.md
└── openbsd/                  # OpenBSD port (Makefile, distinfo, pkg/DESCR, pkg/PLIST)
    └── adv462-*.tgz          # Signed packages for OpenBSD 7.9 amd64
```

## Licensing and credits

The BSD license covers Jim Lippard's contributions: the transcriptions, notes, fixes and porting work.
Will Crowther and Don Woods retain whatever rights they hold in Adventure, Gary Palter in his Multics port,
and Dave Platt in his game content.

Platt's 1979 release notice gave permission "to all users to possess, use, copy, distribute, and modify (but
not to sell)" his programs and files. In September 2026 he confirmed that he has never wanted to limit the use
of his A-code system or of his changes to the cave and its database, and asked only for attribution.

Transcription, analysis, fixes and porting by Jim Lippard, with assistance from Claude (Anthropic), September 2026.
