# Types of docs

Vim has 2 types of documentation:

- User manual (for explaining how to use a feature to the user) 
  (Use `:help user-manual` or `:h user-manual` command to see)

- Reference manual (for detailed technical explanation of a feature).

# Basic Vim Documentation Navigation

Press `<C-]>` on a highlighted word(s) to jump to the corresponding tag.

Press `<C-t>` to go back to the previous *tag* in history.
Press `<C-o>` to go back to the previous entry in the jump list.

The difference between these two is pretty simple. `<C-o>` will go back to each
individual jumps (even if they are within the same *tag*. Whereas `C-t` will go
back to previous *tag* in history)


