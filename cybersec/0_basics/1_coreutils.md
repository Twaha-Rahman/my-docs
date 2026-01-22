# find

Find files by extension:
`find <dir> -name '*.pdf'`

Find file matching multiple path/name patterns:
`find <dir> -path '*/config/*.json' -or -name '*_config.json'`

Find directories matching a given name (case-insensitive):
`find <dir> -type d -iname '*config*'`

Find files with specific pattern of name (excluding specific paths):
`find <dir> -name '*ncurses*' -not -path '*/config/*'`

Find files within a given file size range:
`find <dir> -type f -size +512M -size -1G`

Find files using a max recursive depth length:
`find <dir> -maxdepth 1 -type f -iname '*game*'`

**NOTE:** The *maxdepth* flag must appear before any other flags.

Find files and execute commands using the names of those files:
`find <dir> -type f -iname '*.md' -exec wc -l {} \;`

**NOTE:** The *exec* flag followed by the command to use must be terminated
using `\;`.

## Good to know

Use regex to search:
```bash
find ~ -regex '.+/Downloads/.+\.pdf$'    # Case sensitive

find ~ -iregex '.+/Downloads/.+\.pdf$'   # Case insensitive
```

**NOTE:** By default, `find` uses `emacs` flavor regex. However, we are more
familiar with `egrep` flavor. 

The `egrep` flavor allows us to use EREs (Extended Regular Expressions), which
allows us to use metacharacters like `+`, `?`, `|`, and `{}` without needing to
escape them.

So, use that flavor for non-trivial regex patterns. For example:

```bash
find ~ -type f -regextype "egrep" -regex ".+\.(png|jpg|jpeg|webp)$"
```

## Valid options for `-type` flag

```
d -------> Directory
f -------> Regular File
s -------> Socket
```

## Valid options for `-size` flag

```
c -------> Bytes
k -------> Kilobytes
M -------> Megabytes
G -------> Gigabytes
```

# grep

Search using EREs (Extended Regular Expressions) that supports `?`, `+`, `{}`, `()`, and `|`:
```bash
grep -E "^\.(git|idea)" path/to/file
```

Search within given files with/without Regex:
```bash
# Search using Regex
grep "port" ~/.config/avocado/config.json ~/.config/mango/config.json

# Without regex (direct string search)
grep --fixed-strings "port" ~/.config/avocado/config.json ~/.config/mango/config.json
grep -F "port" ~/.config/avocado/config.json ~/.config/mango/config.json
```

Show line numbers where matches are found:
```bash
grep -n "cursor" ~/.config/hypr/hyprland.conf
```

Show only the matching part of the pattern:
```sh
grep -o -E "picoCTF{.+}" <file>
```

Search case-insensitively:
```bash
grep -i "pOrT" ~/.config/avocado/config.json ~/.config/mango/config.json
```

Search for a pattern in all files recursively in a directory (excluding binary files):
```bash
grep --recursive --binary-files=without-match "^port" ~/.config

grep -r --binary-files=without-match "^port" ~/.config
```

Flags can be combined together:
```bash
grep -rin "cUrSoR" ~/.config/hypr
```

Search for a pattern recursively in a directory while excluding directories with the specified pattern:
```bash
grep -r --binary-files=without-match --exclude-dir="\/\.git/" "twaha" .
```

