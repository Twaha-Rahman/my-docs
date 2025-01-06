# sha256sum

`sha256sum` will compute the _sha256_ checksum for the provided file(s) as
follows:

```fish
sha256sum <filename1> <filename2> .....

sha256sum vimium.md
```

You can store the output of the `sha256sum` to a file, which can later be used
to verify the checksum of that file(s):

```fish
sha256sum vimium.md > SHA256_CHECKSUM

sha256sum -c SHA256_CHECKSUM
```

You can even do it for multiple files:

```fish
sha256sum *.md > CHECKSUM_FILE

sha256sum -c CHECKSUM_FILE
```

# cksum

We can use `cksum` just like the above the `sha256sum` but `cksum` is more
generalized, as such supports a lot of digesting algorithms rather than being
limited to only one algorithm.

We need to specify the algorithm we want to use when we invoke `cksum` with the
`-a` flag.

If we don't specify the algorithm we want to use, `cksum` will use the _crc_
algorithm by default. (The _crc_ algorithm is a legacy checksum that does not
support `-c` flag for checking/verifying checksums)

The supported modern digesting algorithms are-

- **md5** -> can also be used with the `md5sum` command
- **sha1** -> can also be used with the `sha1sum` command
- **sha224** -> can also be used with the `sha224sum` command
- **sha256** -> can also be used with the `sha256sum` command
- **sha384** -> can also be used with the `sha384sum` command
- **sha512** -> can also be used with the `sha512sum` command
- **blake2b** -> can also be used with the `b2sum` command
- **sm3** -> can only be used this way using the `cksum` command

```fish
cksum -a sha512 *.md > CHECKSUM_FILE

cksum -c CHECKSUM_FILE
```

NOTE: We only need to specify the algorithm when we're calculating the checksum.
We don't need to specify the digesting algorithm when verifying the checksum
using the `-c` flag because the algorithm used to generate the checksum is
already written in the file.
