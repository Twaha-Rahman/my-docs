# Permissions in Linux

This doc will go over the things that I found interesting from the Arch Wiki's
page on *Users and Groups*.

# Permissions and Ownership

To view the permissions of a file/directory, run the `ls -l` command like so:

```sh
ls -l /boot
```

That should give you the following output:

```sh
total 231708
-rwxr-xr-x 1 root root     81920 Mar 13 17:34 amd-ucode.img
drwxr-xr-x 3 root root      4096 Jan 30 02:57 EFI
drwxr-xr-x 6 root root      4096 Apr  1 10:35 grub
-rwxr-xr-x 1 root root 126657583 Mar 30 08:12 initramfs-linux-fallback.img
-rwxr-xr-x 1 root root  97593010 Mar 30 08:12 initramfs-linux.img
-rwxr-xr-x 1 root root  12919296 Mar 30 08:12 vmlinuz-linux
```

The first line (row) tells us the total number of filesystem blocks that are
used by the things in the directory. In the above example, the line `total
231708` means that the `/boot` directory uses 231708 blocks.

By default, in most linux systems, **1 Block** = **1KiB (1024 bytes)**

So, 231708 blocks is approximately 231708 KiB.

We can see the total size of the things in the directory **in bytes** instead using the following command:
```bash
ls -l --block-size=1
```

**WARNING:** This might not match with file sizes. This is because a 1 byte
file still consumes at least one block. For accurate disk usage, use `du`
instead. For example:
```bash
du -sh .
```

There are 9 columns in total.

The first character in the first column tells us what type of file it is:

`-` -> File
`d` -> Directory
`l` -> Symbolic link (symlink)
`c` -> Character file (Special file that gives unbuffered, direct access to hardware devices)

Then, every 3 characters after that tells us the permissions of the `user`,
`user group`, and `others` have over that file respectively.

For the **EFI** directory:

`rwx` -> User has Read, Write, and Execute permissions
`r-x` -> User group has Read and Execute permissions
`r-x` -> Others has Read and Execute permissions

The second column shows the **number of hard-links** the file has.

The third and fourth column shows the name of the `user` and the `user group`
respectively.

The fifth column shows the **file size**.

The sixth, seventh and eighth shows the date and time of the file **created/last
modified**.

The last column shows the name of the particular file/directory.

## Using `stat` to find the owner of a file

It's possible to see a file/directory's owner user, group or even it's access rights using `stat` like so:

```sh
$ stat -c %U /boot
root

$ stat -c %G /boot
root

$ stat -c %A /boot
drwxr-xr-x
```

## Using `find` to find files owned by a user/group

It's possible to find files owned by a specific user/group by using the following command:

```sh
find /boot -group root
find /usr -user twaha
```

## Changing ownership or access permissions of a file

`chown` -> Changes owner of file
`chmod` -> Changes *access permissions* of file

### Changing ownership using `chown`

Permission of the `/media/Backup` directory *before changing ownership*:
`drwxr-xr-x 5 root root 4096 Jul 6 16:01 Backup`

```sh
sudo chown twaha /media/Backup
```

Permission of the `/media/Backup` directory *after changing ownership*:
`drwxr-xr-x 5 root root 4096 Jul 6 16:01 Backup`

### Changing access permissions of a file using `chmod`

`chmod` can be used in 2 ways:

- Test method
- Numeric method

#### Text method

The general structure of the command is:
```
chmod who=permissions filename
```

Here, *who* can be:

u ---> User who owns the file
g ---> User group that the file belongs to
o ---> Other users (i.e. everyone else)
a ---> All of the above

Example usage:
```sh
sudo chmod u=rw ~/cloned/paru/PKGBUILD
sudo chmod g=r ~/cloned/paru/PKGBUILD
```

To remove all the permissions from the user, group and others:
```sh
sudo chmod a= ~/cloned/paru/PKGBUILD
```

**NOTE: This method rewrites the permissions with the provided permissions. It does NOT append the permission(s).**

To append the permission(s), use:

```sh
sudo chmod u+x ~/cloned/paru/PKGBUILD # Adds the executable permission to the user who owns the file
sudo chmod u-x ~/cloned/paru/PKGBUILD # Removes the executable permission from the user who owns the file
```

# User Management

To list all existing user accounts including their properties, run `sudo passwd -Sa`. The output will be:

```sh
root P 2024-01-30 -1 -1 -1 -1
bin L 2024-01-29 -1 -1 -1 -1
daemon L 2024-01-29 -1 -1 -1 -1
mail L 2024-01-29 -1 -1 -1 -1
ftp L 2024-01-29 -1 -1 -1 -1
http L 2024-01-29 -1 -1 -1 -1
nobody L 2024-01-29 -1 -1 -1 -1
dbus L 2024-01-29 -1 -1 -1 -1
systemd-coredump L 2024-01-29 -1 -1 -1 -1
systemd-network L 2024-01-29 -1 -1 -1 -1
systemd-oom L 2024-01-29 -1 -1 -1 -1
systemd-journal-remote L 2024-01-29 -1 -1 -1 -1
systemd-resolve L 2024-01-29 -1 -1 -1 -1
systemd-timesync L 2024-01-29 -1 -1 -1 -1
tss L 2024-01-29 -1 -1 -1 -1
uuidd L 2024-01-29 -1 -1 -1 -1
polkitd L 2024-01-29 -1 -1 -1 -1
twaha P 2024-01-30 0 99999 7 -1
avahi L 2024-01-30 -1 -1 -1 -1
cups L 2024-01-30 -1 -1 -1 -1
nvidia-persistenced L 2024-01-30 -1 -1 -1 -1
git L 2024-01-30 -1 -1 -1 -1
usbmux L 2024-01-30 -1 -1 -1 -1
geoclue L 2024-01-30 -1 -1 -1 -1
rtkit L 2024-01-30 -1 -1 -1 -1
flatpak L 2024-01-31 -1 -1 -1 -1
```
The output consists of seven columns.

Each of the columns represent username, *password status*, last password change date, minimum age, maximum age, warning period,
and inactivity period. (The ages are represented in days) 

Meaning of *password status:*

L ---> Locked Password
NP --> No Password
P ---> (Usable) Password

Meaning of the other values:

Minimum age ------> Minimum number of days before password can be changed
Maximum age ------> Maximum number of days a password remains valid
Warning period ---> Number of days before password expiration that the user is warned
Inactive period --> Number of days after password expiration before the account is disabled

To view only the details of a specific user, run the command as that user:

```sh
❯ sudo passwd -S
root P 2024-01-30 -1 -1 -1 -1

❯ passwd -S
twaha P 2024-01-30 0 99999 7 -1
```

## Add new user

Use `useradd` to add users, run these two commands:

```sh
sudo useradd -m -G <group1,group2> -s <login_shell> brad
sudo passwd brad
```

The `-m` flag creates the new user's home directory as `/home/<username>` (for the above example, it'll
be `/home/brad`). The `-G` adds the user to the groups specified (comma separated groups). The `-s` flag
sets the shell binary for the new user's shell. *All of these flags are optional*

Setting the new user's password can be done using the `passwd <username>` command. (This step is optional)

## Change user's login name, home directory, login shell

### Changing user's home directory

To change a user's home directory, run:

```sh
sudo usermod -d /my/new/home -m <username>
```

The `-m` option automatically creates the new directory and moves the content there.

**Tip: You can create a link form the user's former home directory to the new one. Doing so will allow programs
to find files that have hardcoded paths. To do so, run the following command: **

```sh
sudo ls -s /my/new/home /my/old/home
```

### Changing login name

To change a user's login name, first make sure that you're not loged in as that user. Log in as `root` in TTY
for example. Then run from the TTY:

```sh
sudo usermod -l <newname> <oldname>
```

### Changing login shell

To change a user's login shell, run:

```sh
sudo usermod -s /urs/bin/bash <username>
```

## Remove user(s)

User account(s) can be deleted using the `userdel` command:

```sh
sudo userdel -r <username>
```
