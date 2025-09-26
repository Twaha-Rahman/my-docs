# The Basics

To match a letter at any position of a given text, just use the letter directly
in the Regex. However, if you want to match it in the beginning of a word or at
the beginning of the given text, you'll have to use a word boundary for that.

```regex
cat

\bcat
```

The first will match the word `cat` at any point in the given string. The
second one will match `cat` at the beginning of a word.

# Special Characters

Special characters in Regex are called *metacharacters*. They are:
```md
\ backslash
^ caret
$ dollar sign
. dot
| pipe symbol
? question mark
* asterisk
+ plus

( opening parenthesis
) closing parenthesis

[ opening square brackets
] closing square brackets

{ opening curly braces
```

To use them literally in a pattern, you'll need to escape them using a
backslash.

# Special Escape Sequence

Some Regex flavors support using `\Q...\E` as an escape sequence, where
everything inside the `\Q` and `\E` are escaped.

This is useful for some complex escaping like:

```regex
\Q*\d+*\E
```

The above escape sequence escapes `*\d+*`.
