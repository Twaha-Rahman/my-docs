# Git related knowledges that I found useful

Synonymous terms:

_index_ == _staging area_

# status

Run `git status -s` to get the status of the repo in the following short form -

```sh
A  dummy.txt
M  file1.txt
MM Makefile ?? a.out
```

There are two columns of letters before the name of each file. The left and
right column indicate the status of the staging area and working tree
respectively.

The letters indicate the following:

```
A  -> File that has been added
M  -> File that has been modified
?? -> File that haven't been tracked
```

# .gitignore

The patterns that can be used inside `.gitignore` file is:

- Blank lines or lines starting with # are ignored
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

_GitHub maintains a fairly comprehensive list of good `.gitignore` file examples
for dozens of projects and languages at https://github.com/github/gitignore if
you want a starting point for your project._

# diff

Running `git diff` compares the working directory with the staging area. Running
`git diff --staged` or `git diff --cached` compares the staging area with the
last commit. (_--staged_ and _--cached_ are synonymous)

# commit

The editor that gets automatically opened when you run `git commit` can be
changed by changing the `EDITOR` environment variable. (By default it's `vim`
ofcourse). You can also change it by running: `git config --global core.editor`

You can use the `-a` flag alongside `git commit -m` to commit a file or files
directly rather than staging them first. Be warned though, it'll only work with
already tracked files.

# rm

Use `git rm <FILENAME>` to remove a file from being tracked. The command will
untrack the file (and add it to the staging area) and delete it from your
working directory.

Use `git rm --cached <FILENAME>` to remove a file from the staging area.

(`git rm` does support glob patterns)

# log

One can limit the git log output to the last n commits by running the following
command: `git log -n` (where _n_ is a number).

One can use the `-p` (patch) flag to see the changes introduced in each commit.
Example:

```sh
git log -p -2
```

One can also use the `--stat` flag to see the summary of the changes introduced
in each commit. For example:

```sh
> git log -2 --stat
```

The `--oneline` flag is extremely useful to see the titiles of all the logs in a
short space (this won't show the subsequent lines in the commit message).

For example: `git log -3 --oneline`

We can also specify `git` exactly how we want to format the log output using the
`--pretty=format:"<<format string here>>"` flag like so:

```zsh
git log --pretty=format:"%h - %an: %s"
```

The specifiers for the `git log --pretty=format` can be looked up online if you
need it.

We can use the `--graph` flag with the `log` command to see the ASCII graph of
the branch and merge history beside the log output.

```fish
git log --oneline --graph
```

We can also use the `--relative-date` flag with the `log` command to see the
date of the commits in the relative date format (For example: "2 weeks ago").

We can also limit the output of the `log` command by specifying the time period
using the `--since` flag or `--until` flag or both.

```fish
git log --since=2.weeks
git log --since=10.days

git log --since="15 days"
```

One of the most useful ways to use these commands for diagnostics is using the
following custom-made command:

```fish
git log --since=12.days --pretty=format:"%h | %an | %ar | %s"
```

The above command will find the commits made in the last 12 days and print the
info about these commits in the following order:

```
<<Short Commit Hash>> | <<Author Name>> | <<Commit relative time>> | <<Commit Message>>
```

When using the `log` command to see the commit history, if you don't want to see
the merge commits, you can use the `--no-merges` flag.

```fish
git log --no-merges --oneline
```

# Amending/fixing the last commit

If you've realized that you accidentally forgot to add or remove something from
the last commit or you've screwed up the commit message, you can use the
`--amend` flag with the `commit` command to fix the last commit.

```fish
git commit --amend
```

When you're using `--amend`, you're actually not _fixing_ the last commit.
You're actually _replacing_ the last commit with the newly corrected commit.

**N.B.:** Don't do this if you've already pushed the changes to remote. That'll
require a force push and will cause problems for your contributors.

# Restoring file(s) [Undoing changes in the working tree and in the staging area]

The file(s) in the working tree can be restored to the file(s) in the staging
area with the `restore` command: `git restore <file(s)>`

For example: If we accidentally made a change (or a lot of changes) in the
`master` branch accidentally, we can undo them by running the following-

```zsh
git restore .
```

The file(s) in the index can be restored to the file(s) in the HEAD with the
`restore` command with the `--staged` flag: `git restore --staged <file(s)>`

For example: If we accidentally added a change (or a lot of changes) to the
staging area accidentally, we can undo them by running the following-

```zsh
git restore --staged .
```
