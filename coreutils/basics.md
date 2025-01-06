# Options and operands

## The ordering of options and operands

Normally option and opearands can appear in any order. Programs act as if all
the options appear before any operands. For example, running
`sort -r passwd -t :` is the same as `sort -r -t : passwd`. This is because of
the reason provided above and the fact that **:** is an option-argument of `-t`
option.

However, if the `POSIXLY_CORRECT` environment variable is set, options must
appear before operands.

A few programs can usefully have trailing operands with leading `-`. In these
cases, the options must precede operands even if `POSIXLY_CORRECT` is not set.
For example: the `env` commands's options must appear before its operands
because in some cases the operands specify a command that itself contains
options.

## Delimit options and operands using `--`

If the arguments to a command is delimited using `--`, then arguments that come
after the `--` will be treated as operands even if they start with `-`. For
example:

```fish
touch -- -r     # this will touch a file named `-r` in the directory
cat -- -r       # this will print the content of the file named `-r`
```

## The file operand `-`

A single `-` operand is not really an option. It stands for a file operand, and
some tools treat it as `stdin` or as `stdout` if it is clear from the context.
For example: `sort -` reads from the `stdin`.

## Last operand treated as a directory

The `cp`, `install`, `ln`, and `mv` commands normally treat thre last operand
(specially when it is a directory or a symbolic link) as a directory. For
example: `cp source dest` is equivalent to `cp source dest/source` if _dest_ is
a directory.

## Exit status

Nearly every command invocation will yield an integral _exit status_. For the
vast majority of commands, an exit status of zero indicates success. Failure is
denoted by nonzero values (typically 1).

Here are some of the exceptions:: `chroot`, `env`, `ls`, `sort`, `timeout`,
`tty`.

## Floating point numbers

Commands that accept or produce floating point numbers, (on most systems) use
the IEEE-754 standard and they rely on the standard C functions `strtod()` and
`strtold()` for the conversion. As such, they understand case-insensitive `inf`,
`infinity`, and `NaN`.
