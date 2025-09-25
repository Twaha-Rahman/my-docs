# Searching back and forth

This chapter covers a lot about searching in Vim. Refer to it when you need it.
Only the things I think will be really useful are noted here.

The `/<str>` can be used to search for `<str>`.

To jump to the next occurence, press `n`.
To jump to the previous occurence, press `N`.

## Exactly matching only a single word

If you type `/the` it will also match "there".  To only find words that end
in "the" use the `>` character (escape it ofc):

	/the\>

The "\>" item is a special marker that only matches at the end of a word.
Similarly "\<" only matches at the beginning of a word.  Thus to search for
the word "the" only: >

	/\<the\>

# Moving horizontally by searching for characters in a line

The `f<char>` and `t<char>` commands can be used to search for `<char>` in the
line (to the right from current position).

The `F<char>` and `T<char>` commands can be used to search for `<char>` in the
line (to the left from current position).

The `;` key can be used to search for the next occurence.
The `,` key can be used to search for the previous occurence.

# Moving to the start or end of a line

Use the `^` to move to the first non-whitespace character in the line.
Use `0` to move to the first character in the line.

Use the `$` do move to the end of the line.

# Using marks

The *double backtick* command `` can be used to jump back and forth between two
points.

The `<C-o>` and `<C-i>` commands are used to jump back to older and newer
positions respectively.

The `:jumps` command gives a list of positions you jumped to. The entry which
you used last is marked with a ">".

## Named marks

Vim enables you to place your own marks in the text. The command "ma" marks the
place under the cursor as mark a.  You can place 26 marks (a through z) in your
text.

```vimdoc
To go a mark, use the `<mark> command.

For example: to go to the mark a, use `a command.
```

The command "'mark" (single quotation mark, or apostrophe) moves you to the
beginning of the line containing the mark.  This differs from the "`mark"
command, which also moves you to the marked column.

The `:marks` command can be used to see the list of marks.

You will notice a few special marks. These include:

```vim
'	The cursor position before doing a jump
"	The cursor position when last editing the file
[	Start of the last change
]	End of the last change
```


