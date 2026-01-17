# The Basic APIs

`initscr()` -> Initializes the terminal in the curses mode. Might fail in rare cases where there isn't enough memory.

`printw()` -> Prints data on a window called the stdscr (standard screen) at the current cursor co-ordinates.

`refresh()` -> Flushes the output buffer. (It does a diff and only updates the things that changed.)

`endwin()` -> Ends the curses mode and frees the resources it used.

========================================================================================================================

`getyx()` ====> Get the current y,x position of the cursor
Example usage: `getyx(stdscr, row, col);`

`getmaxyx()` => Get the max rows and columns of a given window.
Example usage: `getmaxyx(stdscr, row, col);`
