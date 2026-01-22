# Windows Terminal

# Verification

To check whether you're running `cmd.exe` or `Powershell` in Windows, run the
following:
```ps1
(dir 2>&1 *`|echo CMD);&<# rem #>echo PowerShell
```

We can only issue the commands within the *Windows Path*. To view the path
variable, run: `set`.

```cmd.exe
set
```

# Basics

To see the OS version:
```cmd.exe
ver
```

To see various informations about the system:
```cmd.exe
systeminfo
```

We can pipe the output like we do in Linux:
```cmd.exe
driverquery | more
```

In the above command, the command `more` is similar to the `less` command in
Linux. Only difference is that you can't use the Vim motions. You can quit it
using `q` or `<C-c>` just like we do with `less`. You can press `Enter` to move
by one line or press `Spacebar` to move by one page.

We can also use `help` to get more info about a command and `cls` to clear the
screen: 
```cmd.exe
help driverquery

cls
```

# Basic Network Troubleshooting

You can check the network informations using:
```cmd.exe
ipconfig
```

This will show the following:
```
Windows IP Configuration

Ethernet adapter Ethernet:

   Connection-specific DNS Suffix  . : ap-south-1.compute.internal
   Link-local IPv6 Address . . . . . : fe80::ea73:da43:10f3:c5a2%5
   IPv4 Address. . . . . . . . . . . : 10.49.161.190
   Subnet Mask . . . . . . . . . . . : 255.255.192.0
   Default Gateway . . . . . . . . . : 10.49.128.1
```

To view more info about your network configuration:
```cmd.exe
ipconfig /all
```

We can use `ping` and `tracert` (*trace route*) to check our connection:
```cmd.exe
ping example.com

tracert example.com
```

The command `tracert target_name` traces the network route traversed to reach the
target. Without getting into more details, it expects the routers on the path
to notify us if they drop a packet because its time-to-live (TTL) has reached
zero.

The command `nslookup` can be used to look up a host or domain and return its
IP address.
```cmd.exe
nslookup example.com                # This looks up using *default name server*
nslookup example.com 1.1.1.1        # This looks up using one.one.one.one name server
```

The `netstat` command displays the current network connections and listening
ports. The basic `netstat` command with no arguments will show you established
connections. As shown below:

```
Active Connections

  Proto  Local Address          Foreign Address        State
  TCP    10.10.230.237:22       ip-10-11-81-126:53486  ESTABLISHED
```

The `netstat` command supports the following flags:

-h ====> Show help page
-a ====> Show all established connections and listening ports
-b ====> Show the program associated with each connection
-o ====> Show the PID associated with the connection
-n ====> Show the numerical form for the addresses and port numbers

# File and Disk Management

Here are the commands that will be covered in this section:

```sh
cd
cd <folder>
cd ..
dir
dir /a
dir /s
tree

mkdir <folder>
rmdir <folder>
type <file.txt>
copy test.txt test2.txt
move test2.txt ..
del test.txt
erase poem.txt
```

`cd` without any argument is like `pwd`.
`cd <folder>` and `cd ..` is the same as in Linux.

`dir` is similar to `ls -l`. (Shows additional infos)
`dir /a` is similar to `ls -a`. (Shows hidden files)
`dir /b` is similar to `ls`. (Shows without the additional infos)
`dir /q` ===> Displays the owner of the file(s)
`dir /r` ===> Displays the ADS (Alternate Data Stream) of the file(s)

**NOTE:** In Linux, we can combine multiple flags together to a single flag.
This does not work in Windows (at least in `cmd.exe`)

## Bonus: Uninstall an app

Find the app name using `winget` and uninstall it using that name:

```cmd.exe
winget list | find "<app_name>"

winget uninstall <app_name>
```

