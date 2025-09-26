# The Basics

A character class matches only one character out of several characters.
For example:

```regex
[abc]
[a-z]
[a-zA-Z0-9]
[xyz0-9a]
```

The first will match either a or b or c.

The second will match any letter between a to z.

The third will match any letter between a to z, or any letter A to Z, or any
digit between 0 to 9.

The fourth will match either x or y or z, or any digit between 0 to 9, or a.

To negate a character class, we add a caret after the opening square bracket. Like:

```regex
[^abc]
[^a-z]
[^a-zA-Z0-9]
```

*N.B.: The negative character classes matches invisible line break characters.
Unlike the dot(.). If you don't want to match it, include it in the negated
character class.*

# Metacharacters Inside Character Classes

Except the metacharacters ] \ ^ - all other metacharacters are considered
normal characters inside a character class and don't need to be escaped.

*N.B.: Escaping metacharacters inside character classes will still work.*

