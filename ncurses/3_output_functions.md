# Output Functions

There are 3 classes of function for outputting to the screen:

1) `addch()` class --> Print single character with attribute
2) `printw()` class -> Print formatted output similar to `printf()`
3) `addstr()` class -> Print strings

These functions can be used interchangeably.

# `addch()` class of fucntions

These functions put a single character into the current cursor location and
advance the position of the cursor. They are usually used to print a character
with some attribute(s).

There's 2 ways to combine a character and atrribute(s):

1) By OR'ing a single character with the desired attribute macros. (These
attribute macros could be found in the header file `ncurses.h`)
For example:

```c
addch(ch | A_BOLD | A_UNDERLINE);
```

2) By using functions like `attrset()`, `attron()`, `attroff()`. For example:

```c
attron(A_BOLD);
printw("%c", ch);
attroff(A_BOLD);
```

**Additionally, `curses` provides some special characters for character-based
graphics. We can draw tables, horizontal or vertical lines etc. All available
characters can be found in the header file `ncurses.h`. Just look for macros
beginning with `ACS_` in the header file.**

This class also has: `mvaddch()`, `waddch()`, `mvwaddch()` functions.

# `printw()` class of functions

This similar to `printf()`.

This class also includes: `mvprintw()`, `wprintw()`, `mvwprintw()`.

*`vwprintw()` can be used to print variable number of arguments.*

# `addstr()` class of functions

This is used to put a character string into a given window.

This class also has: `mvaddstr()`, `mvwaddstr()`, `waddstr()`.
