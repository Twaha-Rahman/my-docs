# OSI Model

The OSI (Open Systems Interconnection) model was developed by ISO
(International Organization for Standardization). Although this model is
theoretical, it is vital to learn and undestand as it helps grasp networking
concepts on a deeper level.

The OSI model has 7 layers:

7) Application Layer
6) Presentation Layer
5) Session Layer
4) Transport Layer
3) Network Layer
2) Data Link Layer
1) Physical Layer

## Layer 1: Physical Layer

The physical layer deals with the physical connection between devices. This
includes things like:

1) The Medium (Electrical, optical wire or wireless)
2) The data cable or antenna depending on our medium
3) The definition of the binary digits 0 and 1

## Layer 2: Data Link Layer

The DLL describes the agreement between the different systems on the same
*network segment* on how to communicate.

*Network Segment* ---> A group of networked devices using a shared medium or
                       channel for information transfer.
                       Example: 10 computers connected to a network switch in
                                an office.

Examples of DLLs are:

1) Ethernet (802.3)
2) WiFi (802.11)

Ethernet and WiFi addresees are 6 bytes and they are called MAC (Media Access
Control) address. They are usually expressed in hexadecimal format with a color
separating each two hexadecimal digits (one byte). For example:
```
a4:c3:f0:85:ac:2d
```

In the above example, the first 3 hex digits (`a4:c3:f0`) represent the
*vendor* (who build the network interface) and the last 3 hex digits represent
the **unique address** of the *network interface*.

In real network communication (be it ethernet or WiFi), we expect 2 MAC addressess in each frame. 
They are:

1) The destination data-link address (MAC address)
2) The source data-link address (MAC address)

## Layer 3: Network Layer

While the previous layer (DLL) focused on sending data between two nodes in the
same *network segment*, the Network Layer focuses on sending data between
different networks. In more technical terms, the NL handles logical addressing
and routing (i.e. finding a path to transfer the network packets between the
dirverse networks).

Example scenario:
A company with many offices in different cities. The NL is responsible for
connecting the different offieces together.

Examples of NL:

1) IP (Internet Protocol)
2) ICMP (Internet Control Message Protocol) ---> `ping` uses this protocol
3) VPNs (Virtual Private Network) such as IPSec and SSL/TLS VPN

## Layer 4: Transport Layer

The transport layer enables end-to-end communication between running
applications on different hosts. For example: our websert connecting to a
website's web server.

Examples of TL:

1) TCP (Transmission Control Protocol)
2) UDP (User Datagram Protocol)

## Layer 5: Session Layer

The session layer is responsible for establishing, maintaining, and
synchronising communication between applications running on different hosts.
Establishing a session means initiating communication between applications and
negotiating the necessary parameters for the session. Data synchronisation
ensures that data is transmitted in the correct order and provides mechanisms
for recovery in case of transmission failures.

Examples of SL:

1) Network File System (NFS)
2) Remote Procedure Call (RPC).

## Layer 6: Presentation Layer

The PL ensures the data is delivered in a form the application layer can
understand. This layer handles dta encoding, compression, and encryption. For
example: Character encoding (ASCII and Unicode).

Various standards are used in the PL.

## Layer 7: Application Layer

The application layer provides network services directly to end-user
applications.

Examples of AL:

1) HTTP(S)
2) FTP
3) DNS
4) POP3
5) SMTP
6) IMAP

# TCP/IP Model

The TCP/IP model has 4 layers:

- Application Layer (In OSI: Layer 7 + 6 + 5)
- Transport Layer   (In OSI: Layer 4)
- Internet Layer    (In OSI: Layer 3)
- Link Layer        (In OSI: Layer 2)

In some modern books, the TCP/IP model is has 5 layers:

- Application
- Transport
- Network
- Link
- Physical

# IP Addresses and Subnets

Every host on the network needs a unique indentifier for the other hosts to be
able to communicate with it. That why, we need to assign an IP address for each
device connected to the network when using the TCP/IP protocol.

IP addresses can be divided into 2 categories:

- IPv4
- IPv6

## IPv4

It consists of 4 octets. Each octet has 8 bits. So, the values of an octet can
range from 0 to 255. Since there are 32 bits in total, therefore, we have
approximately 2^32 unique IPv4 addressess.

**Note:** The reason why it is approximately 2^32 is because the values 0 and
255 are reserved in the last octet for all possible combinations for the
network and broadcast addresses.
```
X.X.X.0     # Reserved for network
X.X.X.255   # Reserved for broadcast
```

## Looking up network config

In Windows, run: `ipconfig`.

In Linux, run:
```sh
ifconfig

ip address show
ip a s
```

## Subnet Mask

A subnet mask of `255.255.255.0` can also be written as `/24`. The `/24` means
that the lefmost 24 bits within the IP address don't change across the network,
i.e., the subnet.

In other words, the leftmost 3 octets are the same across the whole subnet.
Therefore, for example, we can expect IP address from `192.168.66.1` to
`192.168.66.254`. The `192.168.66.0` and `192.168.66.255` IP addresses are
reserved for the network and broadcast purposes as explained above.

## Private Addresses

IP addresses can be divided into 2 categories:

1) Public IP addresses
2) Private IP addresses

RFC 1918 defines the following 3 ranges of private IP addresses:

1) `10.0.0.0` to `10.255.255.255.`      (Subnet Mask: 10/8)
2) `172.16.0.0` to `172.31.255.255`     (Subnet Mask: 172.16/12)
3) `192.168.0.0` to `192.168.255.255`   (Subnet Mask: 192.168/16)

**IMPORTANT:** Remembering the ranges for the private IP addresses is *really*
important. Otherwise, you might try to do stupid things like trying to access
it from a public IP address.

## Routing

A router forwards data packets to the proper network. Usually, a data packet
passes through multiple routers before it reaches its final destination. The
router functions at layer 3, inspecting the IP address and forwarding the
packet to the best network (router) so the packet gets closer to its
destination.
