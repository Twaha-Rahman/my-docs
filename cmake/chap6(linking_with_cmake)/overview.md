# Basic overview of linking

The compiler will create an *object file* for each translation unit (for every
`.cpp` file). These will be used to create an in-memory image of our program.

Object files can be structured in many different ways:

1) ELF (Executable and Linkable Format) -> Used by Unix-like systems
2) PE (Portable Executable) -> Used by Windows
3) Mach-O (Mach Object) -> Used by Apple (MacOS, iOS, watchOS, tvOS)

# Building different library types

We create libraries using the `add_library()` command. We can then use
`target_link_libraries()` command to link with that library.

We can create 3 types of libraries:

## Static Libraries

Static libraries get built into the executable directly. This increases the
size of the executable but offers more reliability due to the tight coupling.

```cmake
add_library(lib-guava-static STATIC guava-lib.cpp)
```

## Shared Libraries

Shared libraries are separate from the built executable. This decreases the
size of the executable but it is less reliable. If there are multiple
executables that rely on the same shared library, then they can all re-use it.
As a result, there is small memory overhead compared to static libraries.

However, when these shared libraries have version collisions, it can lead to
dependency hell.

```cmake
add_library(lib-guava-shared SHARED guava-lib.cpp)
```
## Shared Modules

Shared modules are a version of shared libraries that is intended to be used as
a plugin loaded during runtime, rather than something that is linked during
compile-time.

A shared module isn't loaded automatically with the start of the program, it is
loaded only when it is explicitly requested by making a syscall.

In Unix-like systems, it's the `dlopen()` or `dlsym()` syscall. In Windows,
it's the `LoadLibrary` syscall.

```cmake
add_library(lib-guava-static MODULE guava-lib.cpp)
```

# When you need Position Independent Code (PIC) compilation flag (-fPIC)

Shared libraries and shared modules will have the **POSITION_INDEPENDENT_CODE**
property automatically set to `ON` by CMake.

However, it is important to turn this PIC property `ON` for any destination
target that will be linked with these shared libraries.

For example: If we had a shared library called `lib-guava-shared` that will
link with the executable target `guava-cli`, then we'll need to set the PIC
property for the `guava-cli` target to `ON`.

```cmake
set_target_properties(guava-cli PROPERTIES
                                POSITION_INDEPENDENT_CODE ON)
```

# Unresolved symbols and the order of linking

The order in which the libraries are linked using `target_link_libraries()`
command does matter.

We usually want to link against the *outer* libraries before linking against
*nested* libraries. This is because the linker keeps track of the unresolved
symbols and checks if all the symbols were resolved after going through all
the object files. For example:

```cmake
target_link_libraries(guava-cli lib-outer lib-nested)
```

If we want to resolve cyclic references, we need to repeat the library:

```cmake
target_link_libraries(guava-cli lib-nested lib-outer lib-nested)
```

# Separating `main()` for testing

We can extract all the logic inside the `main()` function to a separate
library. We can then call that library from the `main()` function (and pass
argc and argv if we need to). This way, we can get a normal executable.

We can also create another executable target for testing, that'll have it's own
`main()` function that'll have custom logic/code to test the code in the
extracted library file.

(This is a pretty simple testing setup. Testing will be covered in more depth later on...)
