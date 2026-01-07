# A brief overview of object files in the ELF format

These are the elements that are included in the file:

- ELF Header
- .text
- .data
- .rodata
- ... (and many more)
- Section Headers

Explanation of the elements are given below:

## ELF Header

It includes info about the target OS, ELF file type, target ISA, and the
position and size of two header tables found in ELF files. These are *program
headers table* and *section headers table*. 

The *program headers table* isn't present in object files.


