The following are some of the motions that I've learned:

```
$ -> Goes to the end of the line
_ -> Goes to the beginning of the line (excluding whitespaces)
0 -> Goes to the beginning of the line (includig whitespaces)
```

To find the previous or the next match when using f/t motions:

Press `;` to go to the next occurence.

Press `,` to go the previous occurence.

Going back and forward: Press <ctrl-o> to go back and <ctrl-i> to go in.

Press <ctrl-g> to get your location in the file and file status.

Jumping between matching braces/brackets can be done by using the `%` command.

NOTE: It's very useful in debugging missing parentheses.

The substitute command:

`:s` only operates in the line the cursor is on. `%s` operates on the whole
file.

`:s/sour/sweet` will change the first occurence of "sour" (in the line) to
"sweet". To change the occurences in the whole line, one needs to use the `/g`
flag like so -> `:s/sour/sweet/g`

`%s/sour/sweet` will change the first occurences of "sour" (in each line of the
whole file) to "sweet". To change the occurences in the whole line (in each line
of the whole file), one needs to use the `/g` flag like so -> `:s/sour/sweet/g`

To get a confirmation prompt on each occurence, use the `/c` flag like so ->
`:s/sour/sweet/gc`

---- END of Chapter 4 -----

============== Lesson 5 =====================

Enter `:!<shell-command>` to run any shell command. For example: `:!ls`.

You can select some text and then run `:w <FILENAME>` to save the selected text
in the file. For example: `'<,'>w meh` will save the selected text in the file
named "meh".

You can paste the contents of the file (retrieve it) by running the command
`:r <FILENAME>` which will put the contents of the file below the cursor.

You can even put the messages printed to the stdout when running an external
command by running the command `:r !<shell-command>`. For example: `:r !ls`. (Of
course, the messages will be pasted after the cursor)

================== Lesson 7 ====================

When entering a command in the command mode, press <ctrl-d> to show
auto-completions and press <TAB> for the closest auto-completion.

Press <Ctrl-w><Ctrl-w> to jump between the windows.

TODO: Learn all the commands/motions realted to the windows,panes and tabs.
These are prefixed by the <Ctrl-w> ofc.
