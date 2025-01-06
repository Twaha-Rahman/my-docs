# cat

`cat` copies each file or `-` (stdin) to stdout.

The `-b` flag can be used to print the number before each nonempty line
beginning with 1.

The `-E` option can be used to display a `$` symbol after the end of each line.
The `\r\n` combination is shown as `^M$`.

The `-s` option can be used to suppress repeated adjacent blank lines. This will
print just one empty line instead of several.

The `-T` option can be used to show the **TAB** characters as `^I`.

```fish
cat README.md

cat -b steps.md

cat -E windows.txt
```

# tac (The reversed version of `cat`)

_This command is not covered here. If you want to look into it, feel free to
search it up in the internet._

# base64 (To encode or decode to or from a file)

We can encode a file to Base64 by using the `base64` command:

```fish
base64 notes.md > notes_base64.txt
```

We can decode it using the same command with the `-d` flag:

```fish
base64 -d notes_base64.txt > notes_decoded.md
```

# basenc (Same as `base64` except this one is generalized to work with other encoding algos)

```fish
basenc --base64url notes.md > based.txt     # to encode the file

basenc --base64url -d based.txt             # to decode the file
```

Supported encodings:

`--base64`, `--base64url` (file-and-url-safe base64) etc. (These two encodings
are the most important ones)
