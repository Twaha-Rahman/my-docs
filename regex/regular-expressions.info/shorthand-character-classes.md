# The Basics

There are some shortcuts for some more commonly used character classes:

```
\d -> Matches a single digit [0-9]

\w -> Matches a single word character [A-Za-z0-9_]

\s -> Matches a sigle whitespace character [ \t\r\n\f]
```

*N.B.: Here's some caveats-*

- All the Regex flavors that support Unicode will match all the digits from any
scripts for `\d`. However, Java, JS, and PCRE limit themselves to only ASCII.

- Notice that `\w` includes underscore in it. Again, Unicode supporting flavors
will match characters from outside of ASCII. But, there's a lot of
inconsistency surrounding that. As usual, Java, JS, and PCRE limit themselves
to only ASCII. 

- All Regex flavors include a space, a tab, a carriage return, a line feed, and
a form feed inside their character classes for `\s`. Most Regex flavors also
include the vertical tab. The Unicode supporting flaovors also include all the
characters from the Unicode *separator* catagory. Again, Java and PCRE are the
exceptions. JS, however, does match all Unicode whitespace properly.

# Negated Shorthands

The capital letters for those Shorthands simply negate them:

```
\d -> Matches a single digit [^0-9]

\w -> Matches a single word character [^A-Za-z0-9_]

\s -> Matches a sigle whitespace character [^ \t\r\n\f]
```

# More Shorthands

There are more shorthands that are less used and less supported. Thus, they
won't be covered here. Since they are rarely needed, if you ever need them,
you'll have search them up anyway because you'll forget about them anyway.
