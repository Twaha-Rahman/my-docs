# Scope of the tldr doc

This markdown doc will cover how to use gdb effectively from scratch.

Please do note that, due to time constraints this doc won't cover _everything
that might be considered useful_, but rather it'll cover things that _seems to
be useful to me_. I believe this opinionated approach to this doc is it's
biggest strength in face of all the generic tutorial/guides on the internet.
When I tried to learn how to use gdb, I couldn't find any good resources that
covered more things than the basics; besides the doc ofcourse. That's why I
started reading the doc and making this small doc here for my own reference and
for anybody who finds this useful.

So, if you wanted a detailed explanation on all the features of gdb, please head
over to the [gdb doc](https://sourceware.org/gdb/documentation/). It might be a
little dry, but it's a really good material if not the best when it comes to
learing gdb.

Also, this markdown doc won't be extremely pedantic (it'll pedantic to some
extent though 🙃). Sometimes, I might describe somethings in a different way
than what actually happens; but that's ok in my eye if I can make the reader
understand the thing that I'm trying to explain.

If you want pedantic wording/explanation, please head over to the
[gdb doc](https://sourceware.org/gdb/documentation/). It's much more pedantic
and details the small details that were skimmed through in this markdown doc.

With all of that out of the way, let's dive in!

# Prerequisite knowledge

A prior experience with a debugger is preferred. If not, a general understanding
of a debugger will suffice.

# Starting gdb

Normally if you want to debug your program with gdb, you'd want to compile your
code with the following flags:

```sh
gcc ./main.c -O0 -g3
```

The `-g3` flag tells the compiler to include debugging info about the macros
(`#define FOO...`) used in your code.

The `-O0` flag sets the
[optimization level](https://www.rapidtables.com/code/linux/gcc/gcc-o.html#optimization)
for the compiler. (_Please don't confuse the `-o` flag with the `-O` flag as the
former is for naming the output binary file while the latter is for setting the
optimization level of the compiler_)

The binary file (the file you've compiled) for debugging with gdb is called
`inferior` in gdb terminology.

The first argument passed to gdb is the inferior (the binary file you've
compiled) and (optionally) the second argument is the _core_ file.

```sh
gdb ./a.out
gdb a.exe
gdb ./a.out core.2374
```

Please do note that if the second argument starts with a number then gdb will
try to attach to it as a process; if it fails, then it will use it as a _core_
file. You can avoid this by prefacing the second argument with `./` or something
equivalent.

_gdb can be used to debug a running process too. But that won't be covered here.
Please refer to the [gdb doc](https://sourceware.org/gdb/documentation/) for
more information._

```sh
# Rather than doing this
gdb ./a.out 3433
# Do this
gdb ./a.out ./3433
```

In the above example the core file is named `3433` and inside the directory from
where gdb is being executed from. _(The lines preceded by the # symbol are
comments)_

The lines displayed by gdb on startup about licensing can be suppressed with the
`-q` flag (_q stands for quite_):

```sh
gdb ./a.out -q
```

You might want to **alias** it if you get tired of it.

If you want to pass argument(s) to your binary, then use the `--args` flag
followed by the name of the binary and the argument(s) you want to pass to it.
Please do keep in mind that, this option stops argument processing for gdb.

```sh
gdb -q --args ./a.out arg1 arg2
```

You can also run gdb with the Text User Interface (TUI) by passing the `--tui`
flag to gdb. It'll show you the source code side-by-side while executing the
code and show breakpoints and current line the debugger is at.

Upon startup gdb will try to load and execute commands store in the following
directories in the following order:

- 1. $HOME/.config/gdb/gdbinit
- 2. ./.gdbinit

Please do note that comments in these config files start with a `#` symbol.

If you don't want to execute _any_ commands found in any init files, then run
gdb with the `-nx` flag.

# Running commands in gdb

When you're inside gdb, you can execute commands to debug your code. One of the
simple yet useful command is `print`. We can use it to print a value:

```sh
print "Hello, world!"
```

It'll print the string. But we can use a shortcut here. Rather than typing whole
word _print_, we just type _p_ and command will still work:

```sh
p "Hello, world!"
```

This shortcut is not specific to the print statement, in fact almost all
commands in gdb can be substituted with it's first character. There's just one
exception to this rule, and that is, if there can be any confusion surrounding
the shortcut, then it won't work. _Basically_, if there are multiple commands
that start with the same letter, then this shortcut won't work because then gdb
won't know which command to execute.

# Running gdb from a script

WIP (Work in progress)

describe the usage of the following flags: x, ix and similar ones and their
execution order. Also, the batch flag, batch-silent flag, return-child-result
flag

WIP (Work in progress)

# The various commands of gdb

We can set breakpoints in a specific line of our source code by using the
`break` command:

```sh
break 20
```

Here, we've added a breakpoint on line 20 of our source code (basically line 20
in our code).
