# Undoing the changes in a line

There's a special version of the undo command, the "U" (undo line) command.
The undo line command undoes all the changes made on the last line that was
edited.  Typing this command twice cancels the preceding "U".

```vim
A very intelligent turtle
  xxxx				        Delete very

A intelligent turtle
	          xxxxxx		Delete turtle

A intelligent
				            Restore line with "U"
A very intelligent turtle
				            Undo "U" with "u"
A intelligent
```

The `U` command is a change by itself, which the `u` command undoes and `<C-r>` command redoes.

# Save and quit

I (and others) usually use `:wq` to save and exit from Vim/NeoVim.

But, the command `ZZ` can do the same thing.

# Reload the buffer from the file in the disk

The `:e!` reloads the contents in the buffer from the file in the disk.

# Help command (`:h`)

The usage of the help command is explained in detail in this (user-manual chapter 2) chapter.
Refer to it if you ever need to.
