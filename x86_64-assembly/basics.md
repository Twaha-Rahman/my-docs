Source: `https://github.com/mschwartz/assembly-tutorial?tab=readme-ov-file`

# Number Systems and Their Representations

*word* = 2 bytes grouped together (16-bits)

x86 also has `DWORD` and `QWORD`.

*DWORD* = 2 words grouped together
*QWORD* = 2 DWORDs grouped together

*Nibble* = 4 bits

## Binary

In assembly, binary is expressed by appending a `0` in front of it and
terminating it with a `b`.

For example: The binary the number `10110011` will be represented using
`010110011b` in assembly.

## HEX

In assembly, HEX numbers can be expressed in various ways. We can express the
HEX number `a5` in the following ways:

1) `0xa5`
2) `0a5h`
3) `$a5`

## Conversion Technique (Binary -> HEX)

Write the binary numbers using one or more nybbles. Then, convert those nibbles
to HEX digits.


For example:

`11100110` -> `1110 0110` -> `E 6` -> `E6`

**This same technique can be used for 16, 32, 64 bits as well!**

