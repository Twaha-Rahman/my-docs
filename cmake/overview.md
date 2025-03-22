# The essence of CMake

CMake is like an ochestrator of the build process. It takes into count multiple
different aspects:

- Compiling executables and libraries
- Managing dependencies
- Testing
- Installing
- Packaging
- Producing documentation

# How does it work?

The CMake building process has 3 stages:

- Configuration
- Generation
- Building

### Config Stage

In this stage, CMake reads the project details stored in a directory, called the
_source tree_, and it prepares the output directory called the _build tree_.

CMake starts by creating an empty `build tree` and collecting all of the details
about the environment it is running in. (For example: architecture, available
compilers, linkers, archivers etc)

It also runs the `CMakeLists.txt` file to setup everything. Specifically, a
`CMakeCache.txt` file is created to store more stable variables (such as paths
to compilers and other tools).

### Generation Stage

In this stage, CMake will generate a _buildsystem_ for the exact environment it
is working in. Buildsystems are simply cut-to-size configuration files for other
build tools (For example: GNU Make or Ninja etc).

Please note that, the generation stage is executed automatically after the
configuration stage.

### Building Stage

In this stage, the artifacts are generated using the appropriate build tools.

# The basics of CMake

The bare minimum required to compile a C++ file using CMake is having a
`CMakeLists.txt` file in the source tree alongside the C++ file you'll be
compiling. The minimum amount of config in that file has to be:

```cmake
cmake_minimum_required(VERSION 3.20)
project(Sample)

add_executable(Sample main.cpp)
```

Then run the following commands (from the source tree):

```sh
cmake -S . -B build         # config and generation stage
cmake --build build         # build stage
```

# Mastering the CMake CLI

CMake provides the following actions:

- Generating a project buildsystem
- Building a project
- Installing a project
- Running a script
- Running a CLI tool
- Getting help

### Generating a project buildsystem

Run the following to generate a project buildsystem:

```sh
cmake [<options>] -S <path-to-source> -B <path-to-build>
```

For example: `cmake -S . -B ./build` will generate a buildsystem in the
`./build` directory from the source in the `.` (current) directory.

### Options for caching

To make `Debug`, `Release` or `RelWithDebInfo` builds of source, you'll have to
generate a separate build tree for each in a different directory.

For that, you'll need to set the appropriate cache variables with the `-D` flag.

For example:

```sh
cmake -S . -B build -D <var>=<value>
cmake -S . -B build -D <var>[:<type>]=<value>

cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
cmake -S . -B build -D CMAKE_BUILD_TYPE=Debug
```

We can list cache variables with the `-L` flag. To see the help messages with
the variable, add the `H` modifier. To see the advanced variables too, add the
`A` modifier:

```sh
cmake -L[A][H] <path-to-source>

cmake -LA ./debug

cmake -L ./debug
cmake -LH ./debug

cmake -L ./release
cmake -LH ./release
```

The removal of one or more variables can be done with the `-U` flag:

```sh
cmake -U <globbing_expr> <path-to-source>

cmake -U CMAKE_BUILD_TYPE ./debug
```

Here the globbing expression supports the `*` wildcard and any `?` character
symbol. Be careful when using them.

Please note that, both the `-U` and `-D` options can be repeated multiple times.

### Building a project

To build a project that has its buildsystem already generated in a build tree
directory, run:

```sh
cmake --build <dir> [<options>] [-- <build-tool-options>]
cmake --build <dir> -- <build-tool-options>
cmake --build <dir>

cmake --build ./build
cmake --build ./debug
```

For parallel builds, run:

```sh
cmake --build <dir> -j [<number-of-jobs>]

cmake --build ./build -j 8
```

To clean the buildtree, run:

```sh
cmake --build <dir> -t clean

cmake --build ./debug -t clean
```

To clean first and then build in a buildtree, CMake provides a convenient
shortcut:

```sh
cmake --build <dir> --clean-first

cmake --build ./debug --clean-first
```

To debug what went wrong, use the verbose flag:

```sh
cmake --build <dir> --verbose
cmake --build <dir> -v

cmake --build ./debug -v
```

To install a project, run:

```sh
cmake --install <dir_of_buildtree> [<options>]

cmake --install ./release
```

To debug an installation process, run:

```sh
cmake --install <dir_of_buildtree> --verbose
cmake --install <dir_of_buildtree> -v

cmake --install ./debug -v
```

# Other CMake tools

CTest -> Used to test a project. (More in Chapter 8)

CPack -> Used to package a project for different package managers and platforms.
(More in Chapter 11)

# CMake files and folders

## Source tree (aka `project root`)

This directory will contain all of the C++ sources and CMake project files.

Key takeaways of this directory:

- Have a `CMakeLists.txt` file in this directory.

- This directory should be managed by a VCS (Git for example).

- The path to this directory is given by the user with a `-S` argument of the
  `cmake` command.

- Avoid hardcoding any absolute paths to the source tree in your CMake code. (As
  users may store the project under a different path)

## Build tree (aka `build root` and `binary tree`)

CMake uses this directory to store everything that gets generated during the
build.

Key takeaways of this directory:

- Add this directory to your VCS ignore path.

## Listfiles

Files that contain the CMake language are called _listfiles_ and can be included
by calling `include()` and `find_package()`, or indirectly with
`add_subdirectory()`.

Key takeaways of these files:

- CMake doesn't enforce consistent naming for these files, but usually, they
  have a `.cmake` extension.

- An important naming exception is a file called `CMakeLists.txt` file which is
  the first file to be executed in the configuration stage. It is required at
  the top of the source tree.

- As CMake walks the source tree and includes different listfiles, the following
  variables are set: `CMAKE_CURRENT_LIST_DIR`, `CMAKE_CURRENT_LIST_FILE`,
  `CMAKE_PARENT_LIST_FILE`, and `CMAKE_CURRENT_LIST_LINE`.

## CMakeLists.txt

CMake projects are configured with these files. You are required to provide
atleast one in the root of the source tree. Such a top-level file is the first
to be executed in the configuration stage. The file needs to have the following
two commands as the bare minimum:

```cmake
cmake_minimum_required(VERSION <x.xx>)
project(<name> <OPTIONS>)
```

## CMakeCache.txt

Cache variables will be generated from `listfiles` and stored in
`CMakeCache.txt` when the configuration stage is run for the first time.

Key takeaways of this file:

- You can manage this file manually by using the `cmake` CLI.

- You can reset the project to its defatult configuration by deleting this file;
  it will be regenerated from the listfiles.

## Config-files for packages

TBD....

## The `cmake_install.cmake`, `CTestTestfile.cmake`, and `CPackConfig.cmake` files

These files are generated in the build tree by the `cmake` executable in the
generation stage.

## `CMakePresets.json` and `CMakeUserPresets.json`

TBD....

## Ignoring files in Git

TBD....

# Scripts and modules

CMake scripts are a platform agnostic way to do simple scripting. To run a
script, use the `-P` flag:

```shell
cmake -P <script_name>

cmake -P script.cmake
```

A CMake script can even be empty. But, it's recommended to have atleast a call
to the `cmake_minimum_required()` function to set the minimum CMake version
before doing any scripting work.

Please note that, when running scripts CMake won't execute any of the ususal
stages (configuration or generation), and it won't use the cache. Since there is
no concept of a source/build tree in scripts, variables that usually hold
references to these paths will cntain the current working directory instead:
`CMAKE_BINARY_DIR`, `CMAKE_SOURCE_DIR`, `CMAKE_ CURRENT_BINARY_DIR`, and
`CMAKE_CURRENT_SOURCE_DIR`.
