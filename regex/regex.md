# Regex

Learning from regex from: https:??www.regular-expressions.info

# Vocabulary

**Metacharacter**: There are twelve characters in regex that have special meaning.
These characters are called Metacharacter. They are: \ ^ $ . | ? * + ( ) [ ] {

If you want to use any of these Metacharacters as a literal in the regex, you'll need to escape it like so: 1\+1=2

**Non-Printable Characters**: One can use the following character sequences in their regex to match agains non-printable characters:

\t -> matches a tab
\r -> matches a carriage return
\n -> matches a line feed

~~I've omitted some less used non-printable characters~~

**Character Classes** or **Character Sets**: A character class mathces only one out of several characters. For example: `gr[ea]y`
One can use a hyphen inside a character class to specify a range of characters. For example: `[0-9]` will match any digit in that range
One can even use more than one range. For example: `[0-9A-Za-z]` will match any alphanumeric character.
One can even mix ranges with single characters: `[0-9A-Fx]` will match the two ranges and the letter x

Putting a caret (^) after the opening square bracket negates the character set: `[^1-9]`

**Shorthand Character Classes**: Thre are some shorthands for some frequently used character classes:

\d -> matches any single digit
\w -> matches a word character (alphanumeric characters plus underscore)
\s -> matches a whitespace character (includes tabs and line breaks)

**Dot**: Matches a single character except line break characters. 

Use the dot sparingly. Often, a character class or negated character class is faster and more precise.

**Anchors**: Anchors don't match any character; they the match position.

`^` and `$` matches the beginning and the end of the string respectively.
If the multi-line flag is enabled, they match that start and end of each line.

`\b` matches at the word boundaries (start and the end of the word). `\B` matches everywhere `\b` cannot.

`\A` and `\Z` matches the start and the end of the string. But, the latter can match multiple times at the end of the string if there are more than
one new line characters. If you only want to match the end of the string regardless of the number of new line characters at the end of the string
use `\z` instead.


**Alternation**: Alternation is the regex equivalent of the *or* operator.

Example: `(cat|dog) food` will match "cat food" or "dog food", whichever it encounters.

**Quantifiers**: The following tokens control the repretition in regexes.

`?` matches the preceding character zero or one time. (Makes it optional)
`*` matches the preceding character zero or more times.
`+` matches the preceding character one or more times.

Use curly braces to specify the amount of repretition: `[0-9]{11}`

*Quantifiers* can be divided into two classes:

1) Greedy Quantifiers: All the quantifiers used alone are greedy quantifiers.

Example: `<.+>` is greedy.

2) Lazy Quantifiers: Any quantifier followed by `?` is a lazy quantifier.

Example: `<.+?>` is lazy.
