# The Basics

The dot (.) metacharacter matches all characters except the line breaks (by
default). It can be made to match line breaks too if wanted to.

For compatability, you can use `[\s\S]` instead of `.` for matching everything
including line breaks.

**P.S.: Use the dot operator sparingly. Use negated character classes instead.**

Usage of negated character class instead of dot:

```regex
".*"

"[^"\r\n]"
```

Both of the Regex will match double quoted string.
