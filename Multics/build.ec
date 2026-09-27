&version 2
&-
&- build.ec -- compile Adventure 1.2 (462 points) on Multics.
&-
&- Run it in a directory holding this directory's files:
&-      exec_com build
&- and then play with:
&-      adventure
&- (the directory must be in your search rules, as the working directory
&- normally is).  adventure.data must be in the same directory as the
&- object segments; see README.md.
&-
&trace &command on
fortran adventure_
pl1 adventure
pl1 adv462_io_
pl1 addr
pl1 size
pl1 getime
add_name adventure adv462
add_name adv462_io_ ldcomn svcomn advatt advdet
&print Built.  Type "adventure" to play.
