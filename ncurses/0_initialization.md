# Initialization

We can customize our curses session by calling several functions after calling `initscr()`.

## Control input buffer using `raw()` and `cbreak()`

Normally the terminal driver buffers the characters a user types until a new
line or carriage return is encountered. The above two functions are used to
disable line buffering. 

The main difference between them is in the way they handle control characters
like suspend (CTRL-Z), interrupt and quit (CTRL-C) when they are passed to the
program. 

In `raw()` mode, these characters are directly passed to the program without
generating a signal. 

In `cbreak()` mode, they are interpreted as any other by the terminal driver.

Use `raw()` to have more control.

## `echo()` and `noecho()`

These functions control the echoing of characters typed by the user to the terminal.

`noecho()` switches off echoing. Most interactive programs call no echo at
initialization to have more control over the echoing of characters in a
controlled manner.

## `keypad()`

This enables the reading of function keys like F1, F2, ..., F12, arrow keys etc.

Since arrow keys are essential for a TUI, most TUIs enable it.

To enable it in `stdscr`: `keypad(stdscr, TRUE);`

## `halfdelay(X)`

This is used to enable *half-delay mode*, which is similar to the `cbreak()`
mode. However, it waits **X tenths** of second for input and then returns ERR,
if no input is available. 

This can be used, for example, to implement a timeout based password prompt.

## Others...

There are more functions which are called at initialization to customize curses
behavior. However, as they aren't used that often, they won't covered here.
