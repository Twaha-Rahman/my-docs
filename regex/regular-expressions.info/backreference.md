# The Basics

Backreferences can be used to match the same text as previously matched by a
capturing group. For example:

```regex
<([a-z][a-z0-9]*)></\1>
```

The above Regex will match HTML tags that have no attributes and no children.
Things like: <h1></h1>

Most Regex flavors support upto 99 capturing groups and double-digit
backreferences. So, `\99` is a valid backreference in most Regex flavors.

# Repetition and Overwritten Backreferences

If one or more backreferences were found after a capture group match, the
backreference will be overwritten.

# Backreferences and Character Classes

Backreferences can't be used inside character classes.
