# Require specific compiler features

The `target_compile_features()` command can be used to require a compiler with
specific features to compile the specified target.

# Add sources to a target

The `target_sources()` command can be used to add sources to an already defined
target.

This command can be used to conditionally add source files. 

For example: To add platform dependant source files conditionally.

```cmake
cmake_minimum_required(VERSION 3.20)

add_executable(main main.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_sources(main PRIVATE gui_linux.cpp)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_sources(main PRIVATE gui_windows.cpp)
endif()
```

# Add header include directories

The `target_include_directories()` command can be used to set up the
preprocessor include paths.

The command signature:
```cmake
target_include_directories(<target_name> [SYSTEM]
    <INTERFACE|PUBLIC|PRIVATE> [item1....]
    [<INTERFACE|PUBLIC|PRIVATE> [item1....]])
```

The optional `SYSTEM` is only used for external headers from other dependencies
outside of our project. Using it will suppress warnings that are from that
header. This is usually the desired outcome as we don't want to clutter our
logs with external library header file warnings.

Making the directory being included `PUBLIC` is usually what you'd want. This
way, the destination target will be able to use the headers from the source
target. Otherwise, you'd need to add another `target_include_directories()`
command for it too.

For example: To add the header files in the `./our-includes` directory.

```cmake
cmake_minimum_required(VERSION 3.20)

add_executable(main main.cpp)

target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/our-includes)
```

# Pass variables/info from CMake to source code

The `target_compile_definitions()` can be used to pass info/variables from
CMake to source files (C/C++ etc).

In C/C++, this usually uses the `-D` flag to pass the preprocessor macros to
the preprocessor. 

For example:

```cmake
set(VAR_TO_PASS 123)

# In two separate commands
target_compile_definitions(bank_gui PRIVATE ABC)
target_compile_definitions(bank_gui PRIVATE "DEF=${VAR_TO_PASS}")

# In a single command
target_compile_definitions(bank_gui PRIVATE ABC "DEF=${VAR_TO_PASS}")
```

The above CMake command will create the preprocessor macros for `ABC` (without
any values) and `DEF` with the value set to the values of the CMake variable
`VAR_TO_PASS` (which is 123 in this case).

These values can then be accessed in C/C++ source code just like any other 
object-like macros.

```cpp
#if defined(ABC)
std::cout << "ABC is defined!!!" << std::endl;
#endif

#if defined(DEF)
std::cout << "\nDEF is defined with the value: " << DEF << std::endl;
#endif
```

# Passing compiler specific options to the command line

The `target_compile_options()` command can be used to specify compiler-specific
options for the command line.

# Optimize the compilation of external headers

The `target_precompile_headers()` command can be used for that.

