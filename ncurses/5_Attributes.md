# Attributes

The functions related to attributes are: `attron()`, `attroff()`, `attrset()`, `attrget()` etc.

The functions `attron()` and `attroff()` take a bitmask of attributes and
switch them on or off, respectively. The following video attributes are defined
in `<curses.h>` and can be passed into these functions:

```
    A_NORMAL        Normal display (no highlight)
    A_STANDOUT      Best highlighting mode of the terminal.
    A_UNDERLINE     Underlining
    A_REVERSE       Reverse video
    A_BLINK         Blinking
    A_DIM           Half bright
    A_BOLD          Extra bright or bold
    A_PROTECT       Protected mode
    A_INVIS         Invisible or blank mode
    A_ALTCHARSET    Alternate character set
    A_CHARTEXT      Bit−mask to extract a character
    COLOR_PAIR(n)   Color−pair number n 
```

We can OR (|) any number of these to get a combined effect.
For example, to get reverse video with blinking characters:

```c
attron(A_REVERSE | A_BLINK);
```

# What's the difference between `attron()` and `attrset()`?

`attrset()` fully overwrites whatever attributes the window previously had and
sets it to the new attributes(s). 

Whereas, `attron()` and `attroff()` turns on or off the attribute(s).

We can use `standend()` (which is equivalent to `attrset(A_NORMAL)`) to turn
off all attributes and bring us back to normal mode.

**After forced killing or unexpected crash, sometimes the terminal can get wonky. To fix it, run: `stty sane`**

