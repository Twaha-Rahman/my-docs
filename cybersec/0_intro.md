# Offensive Security

One of the tools they use is called `dirb`.

It is used to scan for available webpages for a particular website.

# Defensive Security

Organisation don't rely on a single tool or method to stay secure. They take a
layered approach to defense. This is called *Defence in Depth*. This guarantees
that even if one layer is compromised, there are other layers to rely/fallback
on.

Examples of these defensive measures include:

1) Employee Training: Training employees to be proactive in detecting common security attacks like phishing.

2) Intrusion Detection System (IDS): They monitor and alert when suspicious behaviour or activity is detected across the network or systems.

3) Firewalls: These monitor and determine what traffic is allowed to enter the network, or should be rejected.

4) Security Policies: These help organisations ensure that their systems are used correctly. They can reduce risk by blocking access to dangerous websites or requiring strong passwords, making it harder for attackers to guess login details.

## Security Operations Centre (SOC)

This is the defensive security centre for an oragnisation's technology.

## SIEMs (Security Information and Event Management)

This is the central place for all data and information collected from security
devices, wrokstations, servers, and more within an org. They offer insight into
what is happening within the org's IT.

# Search Skills

There are various types of search engines that search for various different
things. The search engines we use day to day are called *Internet Search
Engine*. Besides these, there are other specialized search engines too.

## Internet Search Engine

Google supports the following search features:

- "exact phrase" searching --------> `"passive reconnaissance"` This will search for the exact match

- site: searching -----------------> `site:freecodecamp.org Twaha` This will search for *Twaha* in `freecodecamp.org` webpages

- The minus (-) sign searching ----> `-tourism pyramids` This will search for pyramids except the website that are related to tourism

- filetype: searching -------------> `filetype:pdf Operating Systems Three Easy Pieces` This will search for PDF files

## Specialized Search Engines

Here are some of the specialized search engines:

### Shodan

Shodan is a search engine for devices connected to the internet. It allows us
to search for specific types and versions of servers, networking equipment,
industrial control systems, and IoT devices.

For example: If we wanted to see how many servers still used `apache 2.4.1`, we
would search for it and get the list of servers with the string `apache 2.4.1`
in their headers.

See [Shodan Search Query Examples](https://www.shodan.io/search/examples) for more examples.

### Censys

At first glance Censys might seem similar to Shodan, but that's not the case.

Shodan focuses on internet-connected devices and systems (servers, routers,
webcams, IoT devices etc.). On the other hand, Censys focuses on
internet-connected hosts, websites, certificates, and other internet assests.

Some of the uses of Censys include enumerating domains in use, auditing open
ports and services, and discovering rogue assets within a network.

See [Censys Introductory Use Cases](https://docs.censys.com/docs/ls-introductory-use-cases#/) for example usage.

### VirusTotal

[VirusTotal](https://www.virustotal.com/) provides a virus-scanning service for
files using multiple antivirus engines. It allows users to upload files or
provide URLs to scan them agains numerous antivirus engines and website
scanners in a single operation. They can even take input file hashes to check
the results of previously uploaded files.

Furthermore, one can check the community's comments for more insights.
Occasionally, a file might be flagged as a virus or a Trojan; however, this
might not be accurate for various reasons, and that's when community members
can provide a more in-depth explanation.

### Have I Been Pwned (HIBP)

HIBP tells whether our email address has appeared in a leaked data breach.

# CVE (Common Vulnerability and Exploits)

This program can be thought as a dictionary of vulnerabilities. It provides
standardized identifiers for each vulnerabilities.

The MITRE Corporation maintains the CVE system. Visit the site ---> [CVE site](https://www.cve.org/).

Alternatively, visit the [National Vulnerability Database (NVD) website](https://nvd.nist.gov/).

Sometimes, we might need to use an exploit as a member of red team. We can get
the code for the exploit from the following sources:

## Exploit Database

We can use this site to get exploit codes from different authors. Sometimes, they are also verified.

## Github

We can also get the code for an exploit from Github by searching the CVE ID.

# Technical Docs

Sometimes, we might need to lookup technical documentations. Some of them are given below:

## Linux Man(ual) Pages

We can see man pages for commands, syscalls, library functions, and even some config files using the `man` command.

## Windows Docs

Microsoft provides official [Technical Documentation](https://learn.microsoft.com/) for its products.
