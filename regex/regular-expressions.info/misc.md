# Non-Capturing Group

As we know, you can use parenthesis to create a capture group:

```regex
(bc)at
```

But, what if you want to group together a patter without capturing it? You can
use the `?:` right after the beginning parenthesis to convert a capture group
into a non-capture group. For example:

```regex
(?:(\.?\w+)+)
```

The above will create a capture group of domains and subdomains of a URL without
capturing the individual domains/subdomains.

# Non-Greedy (Lazy) Quantifiers

TODO: Write it down...
