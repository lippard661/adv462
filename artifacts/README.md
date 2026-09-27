# Artifacts

This directory holds transcriptions of three 1980 line-printer listings. They were found together among Jim
Lippard's papers from Honeywell's Phoenix Multics site. The files here are the digitized artifacts, kept
exactly as printed, errors included. Corrections belong in the working copies elsewhere in this repository.
The errata lists in the notes files record every known error.

Photographs of the printouts are not included (about 90 photos, over 100 MB). They are kept separately.

## multics/: Adventure 1.2 (462 points), Multics, May 1980

The game this repository is about: Don Woods' 350-point Adventure, taken from Gary Palter's MIT-Multics Fortran
port and extended with early Dave Platt material.

| File | What it is |
|---|---|
| `adventure_.fortran` | Transcription of the Fortran source listing (40 program units). Columns follow the paper: `c` in column 1, statements in column 7, `&` continuations in column 6. |
| `adventure_.fortran-NOTES.md` | Page-by-page notes, comparison with Woods and Palter (via the SEL-32 transcription HORV0350), a completeness check, and the list of bugs to fix. |
| `adventure_.fortran-handwritten-notes.md` | Jim Lippard's handwritten ink annotations on the listing. The main one is an unfinished implementation of TAKE ALL / DROP ALL. |
| `adventure.data` | Transcription of the game database (2,699 lines), laid out as printed. The first field is right-justified in 8 columns and text starts in column 9, matching the program's `i8`/`70a1` reads. |
| `adventure.data-NOTES.md` | Page-by-page notes, comparison with Woods 350 and Platt 1984, and the ERRATA list. |
| `transcription-source/` | `adventure.src`, the same database in Woods-style tab-separated form, which is easier to diff. `render.py` regenerates `adventure.data` from it byte for byte. |

## gcos/: GCOS Adventure, c. 1980 (related artifact)

A separate port of Woods 350 to Honeywell GCOS, labeled "GCOS version" in Jim's hand on the cover sheet.
It is **not** an ancestor of the Multics game. The two ports solve the same problems independently:

- **Word storage:** 4-character words versus 5-character packed words.
- **Data file format:** different in each.
- **Save:** a core-image dump versus a common-block save.
- **Comment wording:** different variants of Woods' comments.

It is included because it was found and printed alongside the Multics listing, and it documents the other
Honeywell Adventure in use in 1980.

| File | What it is |
|---|---|
| `adv.fortran` | Transcription of the GCOS source listing (2,942 lines = 49 sheets of 60 lines plus 2). The listing is lowercase, though the running GCOS version was uppercase. Tab stops are every 7 columns. Some statement labels are marked with `#`. |
| `adv.fortran-NOTES.md` | Page-by-page notes, differences from Woods (including a wizard-mode backdoor), and a review list. |

The GCOS game's own data file (`/adv.data`, `i4` layout) was not among the printouts.

## Transcription conventions

- Text is transcribed character for character, including original typos, misspellings and odd spacing.
  Anything uncertain is flagged in the notes.
- Column positions were measured from the photographs where it mattered: labels, continuation text and
  tab-expanded comments.
- Nothing in these files has been corrected. See the ERRATA and fix lists in the notes.
