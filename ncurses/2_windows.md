# A Word About Windows

When curses is initialized, it creates a default window named `stdscr` which represents your screen.

We can also create additional windows and work on those windows specifically
using the same functions with an appended `w-` prefix as we used for the
`stdscr` window. For example:

```c
printw("For the `stdscr` window...");
refresh();

wprintw(win ,"For the `win` window...");
wrefresh();
```

Functions with a `mv-` prefix will move the cursor to the (y, x) co-ordinates
before doing what it was supposed to do.

For `mvw-` prefix, the cursor will be moved to the (y, x) co-ordinates of the
specified window and the function will do its task on that window.

For example:

```c
printw(string);                 /* Print on stdscr at present cursor position */
mvprintw(y, x, string);         /* Move to (y, x) then print string     */
wprintw(win, string);           /* Print on window win at present cursor position */
                                /* in the window */
mvwprintw(win, y, x, string);   /* Move to (y, x) relative to window */
                                /* co−ordinates and then print         */
```
