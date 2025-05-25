# Component Breakdown

Broadly speaking, we need be aware of 3 components here:

- Buffer
- Window
- Tab Page

## Buffer Related Things (Not under this chapter)

To list out all the buffers active, use `:ls`.

To delete a buffer, use the `:bdelete <buffer_name>` or `:bdelete <buffer_num>` or in short `:bd <buffer_name_or_num>`.

## Tab Page Related Things (Not under this chapter)

To create a new tab, use `:tabnew`.
To close a tab, use `:tabclose` or `:tabc`.

To cycle between the tab pages, use `gt`. This is only useful when there is only 2 tab pages.

If there's more than 2 tab pages, you can use `<tab_count>gt` to switch to the specific tab page.
For example: `3gt` will switch you to tab page 3.

# Managing Windows

## Closing Windows
The `:close` or `:clo` command closes a window. It prevents accidentally quiting Vim when closing a window unlike `:q`. 

The `:only` or `:on` command closes all windows, except for the current one.  If any of the other windows has changes,
you will get an error message and that window won't be closed.

## Opening Windows

To open a window on a new, empty file, use `:new`.

The horizontal and vertical splitting of the windows can be confusing at first. You can think of running a knife
horizontally along the screen for horizontal splits and the other way around for vertical splits. This helped me.

### Horizontal Splits

To create a horizontal split for the same file (buffer), use the `:split` or `:sp` command.
To create a horizontal split for a different file (buffer), use `:sp <filename>` command. (Example: `:sp two.c`)

### Vertical Splits

Prepend `v` to the commands that create new windows and you'll get a vertical split.


## Resizing Windows

The split command can be preceded by a number to tell the height of the split window. For example: `:15sp two.c` will
create a horizontal split window of size 15 line height.

To maximize a window's height, use the command: `<C-w>_`. (Yup, it's an underscore)
To resize a window to a specific height, specify the size/height of the window before the command: `35<C-w>_`


## Moving Between Windows

`<C-w>h`	move to the window on the left
`<C-w>j`	move to the window below
`<C-w>k`	move to the window above
`<C-w>l`	move to the window on the right

`<C-w>t`	move to the TOP window
`<C-w>b`	move to the BOTTOM window

## Commands for all windows

Normal Vim window related commands also works for multi-windows:

`:qall` -> Quit all windows
`:wall` -> Write all windows
`:wqall` -> Write and quit all windows
`:qall!` -> Quit all windows without writing them

To make Vim open a window for each file with a vertical split, start Vim it with the "-O" argument: >

```vim
vim -O one.txt two.txt three.txt
```

You can put ":tab" before any Ex command that opens a window.  The window will
be opened in a new tab page. For example: `:tab help gt`
