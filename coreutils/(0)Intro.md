# Nota Bene

In general, we're trying to give a quick overview of the basics of GNU Coreutils
and Unix related stuffs. So we won't be going too deep into a specific command
right now.

This means we won't be showing any flags/options _yet_ (unless specified
otherwise). This also means that we won't be pedantic with the terms used here
(especially if we can use a term to make the learner understand the thing better
even though that's not the correct term).

# Concepts

Concepts covered in here:

- The Unix philosophy
- "Everything is a file"
- Shell
- LGTM

## The Unix philosophy

The core ideas of the Unix philosophy is-

1. Make each program do one thing well. To do a new job, build a new tool rather
   than complicate old programs by adding new _features_.
2. Expect the output of every program to become the input to another (yet
   unknown) program.
3. Design and build software to tried early (ideally within weeks). Don't
   hesitate to throw away the clumsy parts and rebuild them.
4. Use tools to simplify programming tasks, even if you need to create and
   discard them afterward.

## "Everything is a file"

In Unix derivatives (Linux, BSD, MacOS), every devices is represented as a file.

## Shell

Unix shells are command-line interfaces (CLIs) used to interact with the Unix
operating system and its derivatives (e.g., Linux, macOS). A shell provides
users with an environment to execute commands, run scripts, and manage system
resources. It serves as both a user interface and a scripting language
interpreter, enabling users to automate tasks and control the operating system.

Some popular shells:

- sh (The _old-scholl_ shell)
- bash (Usually the default shell in all Linux distributions)
- zsh (Same as the `bash` shell, but with better auto-comletion. It's the
  default shell in MacOS)
- fish (The most user-friendly shell. But, it isn't POSIX complaint)

# Commands

Commands covered in here:

- echo
- pwd
- cd
- ls
- touch
- cp
- rm
- mv
- mkdir
- rmdir

## echo

`echo` is used to print things. It prints them to the `stdout`.

```sh
echo "Hello, world"
```

You can also use single quotes to provide the string argument.

## pwd

`pwd` is used to print out the path of the presently visited directory.

```sh
pwd
```

## cd

`cd` is used to change the presently visited directory.

```sh
cd ~

cd projects/cpp/electricityBillCalculator
```

_N.B.:_ The tilde `~` used here expands to the current user's home directory.
For example, if the current user is _bob_, then the `~` will be replaced wtih
`/home/bob`.

## ls

`ls` is used to print the files and _folder_ within the present working
directory. (In Unix derivatives, we usually call a _folder_ a _directory_)

```sh
ls
```

# touch

`touch` is mainly user for 2 purposes:

1. To create a new file
2. To update the file's last modified time/date

For example, if we wanted to create a new file name **strawberry.txt**, we can
do so using the `touch` command:

```sh
touch strawberry.txt
```

Let's say that we have another file named **mango.txt** that has been last
modified 10 days ago. But, you want to update the file's last modified date so
that it looks as if the file was last modified just now. You can do so using the
following command:

```sh
touch mango.txt
```

So, to wrap up, the `touch` command will create a new file with the provided
name if there is no file with that name. However, if there is a file with that
provided name, then it'll update the file's last modified date to the current
date and time.

# cp

The `cp` command is used to copy files and folders (directories).

```sh
cp original_file.txt copied_file.txt

cp mango.txt myFavouriteFruit.txt

cp mango.txt ~/fruits/myFavouriteFruit.txt
```

To copy whole folders, you'll need to use the `-r` flag. (We'll go over _flags_
in more details later on. For now, think of it as a switch to send a signal.)

```sh
cp -r homeworks ~/myHomeworks
```

# rm

The `rm` command is used to delete files and folders (directories).

**BE CAREFUL: Files or folders (directories) deleted with `rm` cannot be
recovered. Once deleted, they're gone forever. So be very careful whenever
you're using the `rm` command.**

To delete files:

```sh
rm notes.txt

rm ./a.out

rm ./a.exe
```

To delete folders (directories):

```sh
rm -r ~/fruits
```

## mv

The `mv` command is used to move a file/folder (directory) from one folder
(directory) to another.

```sh
mv syllabus.pdf ~/books/syllabus.pdf
```

The `mv` command can also be used to rename a file or folder:

```sh
mv ju_cse_syllabus_latest.pdf syllabus.pdf
```

## mkdir

The `mkdir` command is used to make (create) a directory.

```sh
mkdir fruits

mkdir ~/books
```

To make nested directories, we need to use the `-p` flag:

```sh
mkdir -p ~/books/1st_Year/2nd_Semester
```

## rmdir

The `rmdir` command is used to remove (delete) a directory.

```sh
rmdir fruits

rmdir ~/certificates
```
