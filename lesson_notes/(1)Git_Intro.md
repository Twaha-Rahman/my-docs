# Intro to Git

Git is a VCS (version control system). It may also be called a source contol
system.

Short intro from GPT uncle: Git is a tool that helps you keep track of changes
to your files, especially when working on projects like coding or writing. Think
of it as a time machine for your work—you can save different versions, go back
to earlier ones if needed, and even share your work with others. It’s especially
useful when working in a team because everyone can work on the same project
without overwriting each other’s changes. With Git, you can easily experiment,
fix mistakes, and stay organized. No need to worry about losing your work or
keeping track of file versions manually!

Git was created by Linus Torvalds for the development of the Linux kernel. It,
just like Linux, became extremely popular over time. Now a days, it is the de
facto standard for version control systems. Almost 99% of the industry uses Git
to manade their source code.

N.B.: Git has no special meaning. The name does not stand for anything profound.
According to Linus Torvalds, the creator of Git, you can call it whatever you
want. He jokingly called it the _version control system from hell_

# Concepts/terms/ideas related to Git

## What are working tree, staging area and commits?

In Git, when we initialize a _repo_ (repository) with `git init`, the directory
where we run the command will be considered as the working tree. Any files and
directories nested within that directory will also be considered within the
working tree.

As for the _staging area_, it's a concept used by Git to tell that a particular
file has been selected for commiting. Note that when we add a file to the
_staging area_ using `git add` command, we add that file(s) and its contents in
that particular moment to the _staging area_. If we modify the contents of the
file(s) added to the _staging area_, we'll see that it'll show up in Git as
modified changes in the _working tree_ when we run the `git status` command.
(Try it out for yourself and verify it is true or not)

Lastly, the _commits_ in Git is seen a particular save point in Git. We can
later on come back to this save point if screw up something in the future. (To
be honest, that's a pretty simple explanation of _commits_. In reality,
_commits_ are much more powerful than that.)

## Why commit periodically

The more frequently you commit, the more frequent snapshots/backups/save points
of your code is available to revert back to later on if you screw something up
in the future. It's better to have multiple smaller commits because if you screw
up a small commit somewhere, it's much more easier to find it rather than
finding it in a huge commit. (We can even automate the process of finding a
particular bug in Git using the `bisect` command)

## General idea about how Git works internally (it's basically one big linked list)

In Git, the commits are represented as a linked list under-the-hood. The
**HEAD** is a special pointer in Git that points to the latest commit in the
current branch you're on.

## Why and how to write good commit messages?

Don't write commit messages that _only_ explain what you did. A few example of
bad commit messages are given below:

```
"Added main.cpp"

"Deleted main.cpp"
```

Rather than doing that, explain the purpose of your commit.

```
"Added the random number generator feature"

"Fixed the integer overflow bug"
```

## What is the `index`?

The term _index_ is often used instead of the term _staging area_. They are the
same thing.

# Commands covered in this lesson

- init
- add
- commit (-m, with VIM, -am)
- status
- log
- restore (-- staged)
- (optional) reset
- .gitignore

# init

The `init` command is used to initialize a Git _repo_ (repository) in the
present working directory (`pwd`).

```shell
git init
```

# add

The `add` command is used to add files to the staging area from the working
tree.

```shell
git add main.txt            # To add a single file

git add notes.txt book.md   # To add multiple files

git add *.cpp               # To add one or more files using patterns

git add .                   # To add all the files and directories (that are not in .gitignore)
```

# commit

The `commit` command is used to commit the things in the _staging area_.

```shell
git commit

git commit -m "Added a few files"

git commit -am "Fixed typo in notes.txt"
```

Once a file has been commited, Git will track the changes in that file moving
forward.

# status

The `status` command is used to show the current status of the Git repo
(repository). It'll show the untracked file(s) and file(s) in the staging area.
It'll also show other relevant information.

```shell
git status
```

# log

The `log` command will show the history of all the commits so far.

```shell
git log
```

The `log` command will show the output in the terminal in scrollable manner. To
scroll down press `j`, to scroll up press `k`, and to quit press `q`.

To view the output of the command in `stdout` and limit the output info to the
last **N** number of commits, run the following command:

```shell
git log -5

git log -3
```

# restore

The `restore` command can be used to restore files in the working tree. It can
also be used to restore files in the _staging area_.

## Restoring the file(s) in the working tree

The file(s) in the working tree can be restored to the file(s) in the staging
area with the `restore` command: `git restore <file(s)>`

For example: If we accidentally made a change (or a lot of changes) in the
`master` branch accidentally, we can undo them by running the following-

```zsh
git restore .
```

## Restoring the file(s) in the staging area

The file(s) in the index can be restored to the file(s) in the HEAD with the
`restore` command with the `--staged` flag: `git restore --staged <file(s)>`

For example: If we accidentally added a change (or a lot of changes) to the
staging area accidentally, we can undo them by running the following-

```zsh
git restore --staged .
```

# reset

The `reset` command was used back in the days to do the same things that we did
with the `restore` command above. But, it could also do a lot more things beside
those two tasks. As such, it was a place of confusion for Git users. That's why
the `restore` command was create as a replacement for the `reset` command.

Users are encouraged to use the new `restore` command over the old `reset`.

(We've just mentioned the `reset` command here so that you know that a command
named `reset` exists and what it could do. This is important there are many
old/outdated YT videos, StackOverflow answers, blogs etc. that tell you to use
`reset`.)

# .gitignore

The `.gitignore` is not a command; rather it's a file that's used to tell Git
which files in the working tree to ignore. Git won't track those files and Git
will prevent you from accidentally committing them.

The `.gitignore` file uses a lot of patterns to exclude/ignore files and
directories. A few of the most common and useful pattern are shown below:

- Blank lines are ignored
- Lines starting with # are ignored. As such they are used for comments.
- Standard glob patterns work, and will be applied recursively throughout the
  entire working tree
- A pattern can be negated by starting it with an exclamation mark (!)
- A pattern can start with forward slash (/) to avoid recursivity
- A pattern can end with forward slash (/) to specify a directory

Glob patterns are like simplified regular expressions that shells use. An
asterisk (\*) matches zero or more characters; [abc] matches any character
inside the brackets (in this case a, b, or c); a question mark (?) matches a
single character; and brackets enclosing characters separated by a hyphen ([0-
9]) matches any character between them (in this case 0 through 9). You can also
use two asterisks to match nested directories; a/\*\*/z would match a/z, a/b/z,
a/b/c/z, and so on.

**GitHub maintains a fairly comprehensive list of good `.gitignore` file
examples for dozens of projects and languages at
https://github.com/github/gitignore if you want a starting point for your
project.**
