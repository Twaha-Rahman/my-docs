# Targets

If you have ever used **GNU Make**, you will have already seen the concept of a
target. Essentially, it's a _recipe_ that a buildsystem uses to compile a list
of files into another file. It can be a `.cpp` implementation file compiled into
an `.o` object file, a group of .o files packaged into an .a static library, and
many other combinations.

In CMake, we can create a target using one of the three commands:

1. `add_executable()`
2. `add_library()`
3. `add_custom_target()`

We already know what the first two commands do at a high level; we'll look them
in more details in the next chapter (Chapter 5: Compiling C++ Sources with
CMake).

As for the `add_custom_target()` command, it can be used to specify our own
command line that will be executed _without checking whether the produced output
is up to date_. It can be used to do the following:

1. Calculate the checksum of other binaries
2. Run the code-sanitizer and collect the results
3. Send a compilation report to the data processing pipeline

One good use case for custom targets might be the need to remove specific files
on every build - for example, make sure that code-coverage reports don't contain
stale data. All we need to do is define custom target like so:

```cmake
add_custom_target(clean_stale_coverage_files
          COMMAND find . -name "*.gcda" -type f -delete)
```

The preceding command will search for all files with a .gcda extension and
remove them. There is one catch though; unlike executable and library targets,
custom targets won't be built until they are added to a dependency graph.

# Dependency Graph

Mature applications are often built from many components, and I don't mean
external dependencies here. Specifically, I'm talking about internal libraries.
Adding them to the project is useful from a structural perspective, as related
things are packaged together in a single logical entity. And they can be linked
with other targets – another library or an executable. This is especially
convenient when multiple targets are using the same library.

Take a look at the following project:

```
+--------------------------------------+
|                 1                    |
| +------------------+ +-------------+ |
| |    Calculations  | | Drawing     | |
| |     (library)    | | (library)   | |
| +------------------+ +-------------+ |
+--------------------------------------+
         ▲          ▲         ▲
         |          |         |
         |          |         |
+--------------------------------------+
|                 2                    |
| +-------------+   +-------------+    |
| | TerminalApp |   | GuiApp      |    |
| | (executable)|   | (executable)|    |
| +-------------+   +-------------+    |
+--------------------------------------+
         ▲                  ▲
         |                  |
         |                  |
+--------------------------------------+
|                 3                    |
|          +-------------+             |
|          |  Checksum   |             |
|          |  (custom)   |             |
|          +-------------+             |
+--------------------------------------+
```

In this project, the `GuiApp` executable target depends on both of the library
targets and the `TerminalApp` executable target only depends on the
`Calculations` library target.

On the other hand, the `Checksum` custom target depends on both the
`TerminalApp` target and the `GuiApp` target.

The `CMakeLists.txt` file for this project would look like the following:

```cmake
cmake_minimum_required(VERSION 3.19.2)

project(BankApp CXX)

add_executable(terminal_app terminal_app.cpp)
add_executable(gui_app gui_app.cpp)

target_link_libraries(terminal_app calculations)
target_link_libraries(gui_app calculations drawing)

add_library(calculations calculations.cpp)
add_library(drawing drawing.cpp)

add_custom_target(checksum ALL
    COMMAND sh -c "cksum terminal_app>terminal.ck"
    COMMAND sh -c "cksum gui_app>gui.ck"
    BYPRODUCTS terminal.ck gui.ck
    COMMENT "Checking the sums..."
)
```

We connect our libraries with executables using the `target_link_libraries()`
command. (Have you noticed that we invoked this command before actually
declaring any of the libraries? When CMake configures the project, it collects
the information about targets and their properties – their names, dependencies,
source files, and other details. )

After parsing all the files, CMake will attempt to build a dependency graph.
When we execute cmake in build mode, the generated buildsystem will check what
top-level targets we have defined and recursively build their dependencies.

However, there's a slight problem/bug with the above `CMakeLists.txt` file.
CMake doesn't know that a checksum depends on the executable binaries being
present, so it's free to start building it first. To fix this issue, we'll need
to put those targets as the checksum target's dependency:

```cmake
cmake_minimum_required(VERSION 3.19.2)

project(BankApp CXX)

add_executable(terminal_app terminal_app.cpp)
add_executable(gui_app gui_app.cpp)

target_link_libraries(terminal_app calculations)
target_link_libraries(gui_app calculations drawing)

add_library(calculations calculations.cpp)
add_library(drawing drawing.cpp)

add_custom_target(checksum ALL
    COMMAND sh -c "cksum terminal_app>terminal.ck"
    COMMAND sh -c "cksum gui_app>gui.ck"
    BYPRODUCTS terminal.ck gui.ck
    COMMENT "Checking the sums..."
)

add_dependency(checksum terminal_app gui_app)
```

You might now wonder, what's the difference between the `add_library()` and the
`add_dependency()` command?

The difference is that the first is intended to be used with actual libraries
and allows you to control property propagation. The second is meant to be used
only with top-level targets to set their build order.

# Visualizing dependencies

Run the following command to generate a dependency graph with CMake:

```sh
cmake --graphviz=test.dot .
```

The module will produce a text file that we can import to the Graphviz
visualization software, which can render an image or produce a PDF or SVG file
that can be stored as part of the software documentation.

_NOTE: Custom targets are not visible by default and we need to create a special
configuration file, `CMakeGraphVizOptions.cmake`, that will allow us to
customize the graph. One handy customization command is
`set(GRAPHVIZ_CUSTOM_TARGETS TRUE);` add it to the special configuration file to
enable reporting custom targets in your graph. You can find more options in the
documentation for the module._

# Target Properties

Targets have properties that work in a similar way to fields of C++ objects. We
can modify some of these properties and others are read-only.

```cmake
get_target_property(<var> <target> <property-name>)
set_target_properties(<target1> <target2>... PROPERTIES <prop1-name> <value1> <prop2-name> <value2>...)
```

Generally, it's better to use as many high-level commands as you can. CMake
offers more of these, even narrower in their scope, such as setting sprecific
properties on a target. For example:

```cmake
get_target_property(...)
set_target_property(...)
```
