# Windows FSes

The fs used in modern versions of Windows is called NTFS(New Technology File
System). NTFS is known as a journaling fs. In case of failure, the fs can
automatically repair the folders/files on disk using information stored in a
log file. This is not possible in FAT (File Allocation Table).

Before NTFS, there was FAT16/FAT32 (File Allocation Table) and HPFS (High
Performance File System). FAT is still used in pendrives, MicroSD cards etc.

NTFS solves many of the limitations of the previous filesystems:

- Supports files larger than 4GB
- Suppors setting specific permissions on folders and files
- Folder and file compression
- Encryption

On NTFS volumes, you can set permissions that grant or deny access to files and
folders. The permissions are:

- Full Control
- Modify
- Read & Execute
- List Folder Contents
- Read
- Write

To read what each of those permissions entail, click [here](https://docs.microsoft.com/en-us/previous-versions/windows/it-pro/windows-2000-server/bb727008(v=technet.10)?redirectedfrom=MSDN).

The permissions for a file or folder can be viewed by:

- Opening the `property` of it
- Going to the `security` tab
- Looking at the list named `Group or user names`

Another feature of NTFS is ADS (Alternate Data Stream). Every file has at least
one data stream ($DATA), and ADS allows files to contain more than one stream
of data. Natively Window Explorer doesn't display ADS to the user. There are
3rd party executables that can be used to view this data, PowerShell also gives
you the ability to view ADS for files. We will cover how you can use PowerShell
to view any ADS for any files in the Windows PowerShell room.

From a security perspective, malware writers have used ADS to hide data. Not
all its uses are malicious. For example, when you download a file from the
Internet, there are identifiers written to ADS to identify that the file was
downloaded from the Internet.

To learn more about ADS, refer to the following link from MalwareBytes
[here](https://blog.malwarebytes.com/101/2015/07/introduction-to-alternate-data-streams/). 

Bonus: If you wish to interact hands-on with ADS, I suggest exploring Day 21
of  [Advent of Cyber 2](https://tryhackme.com/room/adventofcyber2).

# Windows Folders and Environment Variables

The `C:\Windows` is traditionally know as the *Windows folder* and it contains
the Windows OS. Technically speaking, the *Windows folder* can reside in other
drives and in other folders. The environment variable `%windir%` stores the
path to the *Windows folder*.

The `C:\Windows\System32` folder holds the important files that are critical
for the Windows OS. 

# Windows Accounts, Profiles, and Permissions

User accounts can be of one of two types:

- Administrator
- Standard User

To view the users on a system:

## Method 1 (Searching for it)
*Start* > "Other users" > (Settings > Other users)

An administrator can add users here. They can also view, modify account type,
and remove other users here.

## Method 2 (Using Run)

Press `<WinBtn> + r` to open `Run`. Then, type `lusrmgr.msc` and hit enter. You
can view users and groups here. 

# UAC (User Account Control)

UAC was first introduced in Windows Vista. When a user of account type
`Administrator` tries to perform an operation that requires *elevated
permissions*, the UAC prompt the user to confirm if they permit the operation.

**NOTE:** UAC, by default, does not apply for the built-in local administrator
account.

A shield icon will be present on top of the icon of a program, if the program
requires administrator's elevated permissions.

The UAC prompt will disappear after some time, if the password is not entered
or it has not been interacted with.

# Task Manager and Windows Processes

To learn more about Task Manager, refer to this [blog
post](https://www.howtogeek.com/405806/windows-task-manager-the-complete-guide/).

If you wish to learn more about the core Windows processes and what each
process is responsible for, visit the [Core Windows Processes
room](https://tryhackme.com/jr/btwindowsinternals). 

