# Useful GCC flags

## The -o flag

This flag sets the output filename (with destination if you want to):

```sh
gcc -o program program.c
gcc -o build/program program.c
```

## The -Wall flag

This flag enables all the warnings:

```sh
gcc -Wall program.c
```

## The -Werror flag

This flag converts all warnings into errors:

```sh
gcc -Werror main.c
```

This flag when used in conjuction with the `-Wall` flag can be quite useful.

## The -l flag

This flag allows for linking with the shared libraries:

```sh
gcc main.c -o Hello -lpthread
```

In this example, we linked it with the `pthread` shared library.

## The -L flag

This flag allows for linking with external libraries:

```sh
gcc main.c -o Hello -L/home/user/LHB
```

In this example, we linked it with the `LHB` externa library.

## The -E flag

This flag shows the output of the preprocessor:

```sh
gcc -E main.c
```

## The -S flag

This flag shows the assembly generated:

```sh
gcc -S main.c
```

## The -C flag

This flag produces only the compiled code:

```sh
gcc -C main.c
```

## The -save-temps flag

This flag produces the preprocessor file, assembly file and the compiled only
file of the provided source code:

```sh
gcc -save-temps main.c
```

# Applying GCC flags using a file

First, create a file that'll be used for saving all the flags. For example, we
create a file called `CompilerFlags`. We then save all the flags we want to pass
to the compiler separated with a space.

```txt
-Wall -Werror
```

Lastly, you'll have to pass this file to the compiler by specifying it's name
with a preceding `@` symbol:

```sh
gcc main.c @CompilerFlags
```
