# Specifying the minimum CMake version

When we use the `cmake_minimum_required()` command with a version number, CMake
calls another command `cmake_policy()` under the hood, which sets the CMake
policy to be used. The CMake policies tell CMake how CMake should run. The CMake
devs use the CMake policies to introduce backwards incompatible changes.

**WARNING: ALWAYS use the `cmake_minimum_required()` command as the first
command in the listfiles or script files to set the CMake minimum version and
the associated policies.**

# Defining the project metadata

The metadata can be defined using the `project()` command like so:

```cmake
project(<PROJECT-NAME>
        [VERSION <semver-version-number>]
        [DESCRIPTION <project-description-string>]
        [HOMEPAGE_URL <url-string>]
        [LANGUAGES <language-name>])

project(BeanCounter
        VERSION 1.22.03
        DESCRIPTION A simple resturant bill calculator app
        HOMEPAGE_URL https://github.com/<username>/<repo_name>
        LANGUAGES CXX)
```

_PRO TIP: CMake enables C and C++ by default, so you may want to explicitly
specify only CXX for your C++ project. It'll save time in CMake's configuration
stage_

# Partitioning the `CMakeLists.txt` file to multiple files

We could use the `include()` command, but that's not a complete solution as it
can pollute the top-level scope.

So, we'll use the `add_subdirectory()` command instead as it introduces variable
scope and more features that are suitable for the task at hand.

```cmake
add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])

add_subdirectory(cars)
```

The `source_dir` is the source directory we want to add to our build. With
`binary_dir` we may optionally provide a path in which build files will be
written.

The EXCLUDE_FROM_ALL keyword will disable the default building of targets
defined in the subdirectory (we'll cover targets in the next chapter). This may
be useful for separating parts of the project that aren't needed for the core
functionality (for example: examples and extensions).

The `add_subdirectory()` command will look for a `CMakeLists.txt` file in the
`source_dir` path provided to the command (evaluated relative to the current
directory). This file will then be parsed in the directory scope, meaning that
all the flaws mentioned in the previous method aren't present:

- Variable changes are isolated to the nested scope
- We're free to configure the nested artifacts however we like
- Changing the nested `CMakeLists.txt` file doesn't require building unrelated
  targets
- Paths are local to the directory, and they can even be added to the parent
  include path if desired.

But, just adding a subdirectory using this command won't work as we expect.
We'll also need to use the `target_link_libraries()`, `add_library()`, and the
`target_include_directories()` command to get the desired result.

Let's see how all that looks in the files:

```
$ tree .
.
├── CMakeLists.txt
├── cars
│   ├── CMakeLists.txt
│   ├── car.cpp
│   └── car.h
└── main.cpp
```

In the root `CMakeLists.txt` file:

```cmake
cmake_minimum_required(VERSION 3.20)

project(Rental CXX)

add_executable(Rental main.cpp)

add_subdirectory(cars)
target_link_libraries(Rental PRIVATE cars)
```

In the `cars/CMakeLists.txt` file:

```cmake
add_library(cars OBJECT
            car.cpp)

target_include_directories(Rental PRIVATE cars)     # for the easy inclusion of header files
```

As you can see, we used `add_library()` to produce a globally visible target,
cars, and added the cars directory to its public include directories with
`target_include_directories()`. This allows `main.cpp` to include the `cars.h`
file without providing a relative path:

In `main.cpp`:

```cpp
#include "car.h"
```

## Nested Projects

In the previous section, we briefly mentioned the `EXCLUDE_FROM_ALL` argument
used in the `add_subdirectory()` command. The CMake documentation suggests that
if we have such parts living inside the source tree, they should have their own
`project()` commands in their `CMakeLists.txt` files so that they can generate
their own buildsystems and can be built independently.

You can achieve that by adding the project() command to the listfile in the
nested directory. Just don't forget to prepend it with cmake_minimum_required().

# Thinking about the project structure

Look up this part from the PDF (book page 93; PDF page 114)

# Scoping the environment

To check the OS you're on with CMake, use the `CMAKE_SYSTEM_NAME` variable:

```cmake
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message("Tux rises from the east...")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message("Steve Jobs approves your OS...")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("You're in an abusive relationship with your OS...")
else()
    message("You're using a less popular OS named: ${CMAKE_SYSTEM_NAME}")
endif()
```

If you want to figure out the version of the OS, you can take a look into the
`CMAKE_SYSTEM_VERSION` variable.

# Cross-compilation

Compiling code on one machine to be run on another is called cross-compilation.

One of the necessary steps to allow cross-compilation is setting the
`CMAKE_SYSTEM_NAME` and `CMAKE_SYSTEM_VERSION` variables to the values
appropriate for the operating system that you're compiling for targets (the
CMake documentation refers to it as the target system). The operating system
used to perform the build is called a host system.

Regardless of the configuration, the information on the host system is always
accessible in variables with a HOST keyword in their name: `CMAKE_HOST_SYSTEM`,
`CMAKE_HOST_SYSTEM_NAME`, `CMAKE_HOST_SYSTEM_PROCESSOR`, and
`CMAKE_HOST_SYSTEM_VERSION`.

There are a few more variables with a HOST keyword in their name, so just keep
in mind that they're explicitly referencing the host system. Otherwise, all
variables reference the target system (which normally is the host system anyway,
unless we're cross-compiling).

# Host System Information

CMake could provide one with many information about the host system if it is
requested using the `cmake_host_system_information()` command.

We can ask for many details about the environment and the OS:

```
-------------------------------------------------------------------------------
|           Key             |                   Returned Value                |
|---------------------------|-------------------------------------------------|
|   HOSTNAME                |   The hostname                                  |
|---------------------------|-------------------------------------------------|
|   FQDN                    |   The fully qualified domain name               |
|---------------------------|-------------------------------------------------|
|   HOSTNAME                |   The hostname                                  |
|---------------------------|-------------------------------------------------|
|   TOTAL_VIRTUAL_MEMORY    |   The total virtual memory in MiB               |
|---------------------------|-------------------------------------------------|
|   AVAILABLE_VIRTUAL_MEMORY|   The available virtual memory in MiB           |
|---------------------------|-------------------------------------------------|
|   TOTAL_PHYSICAL_MEMORY   |   The total physical memory in MiB              |
|---------------------------|-------------------------------------------------|
|AVAILABLE_PHYSICAL_MEMORY  |   The available physical memory in MiB          |
|---------------------------|-------------------------------------------------|
|   OS_NAME                 |   The output of `uname -s`; otherwise one of    |
|                           |   `Windows` or `Linux` or `Darwin`.             |
|---------------------------|-------------------------------------------------|
|   OS_RELEASE              |   The OS syb-type, e.g., Windows Professional   |
|---------------------------|-------------------------------------------------|
|   OS_VERSION              |   The OS build ID                               |
|---------------------------|-------------------------------------------------|
|   OS_PLATFORM             |   The output of `uname -m` on Linux and MacOS   |
|---------------------------|-------------------------------------------------|
|   NUMBER_OF_LOGICAL_CORES |   The number of logical cores                   |
|---------------------------|-------------------------------------------------|
|  NUMBER_OF_PHYSICAL_CORES |   The number of physical cores                  |
|---------------------------|-------------------------------------------------|
|   HAS_SERIAL_NUMBER       |   1 if the processor has a serial number        |
|---------------------------|-------------------------------------------------|
|   PROCESSOR_SERIAL_NUMBER |   The processor serial number                   |
|---------------------------|-------------------------------------------------|
|   PROCESSOR_NAME          |   The human-readable processor name             |
|---------------------------|-------------------------------------------------|
|   PROCESSOR_DESCRIPTION   |   The human-readable full processor description |
|---------------------------|-------------------------------------------------|
|   IS_64BIT                |   1 if the processor is 64 bit                  |
|---------------------------|-------------------------------------------------|
|   HAS_FPU                 |   1 if the processor has a floating-point unit  |
|---------------------------|-------------------------------------------------|
```

And the command to get the information is:

```cmake
cmake_host_system_information(RESULT <variable> QUERY <KEY>...)

cmake_host_system_information(RESULT queryResponse QUERY IS_64BIT)
```

We need to provide a target variable and a list of keys we're interested in. If
we provide just one key, the variable will contain a single value; otherwise, it
will be a list of values.

# Does the platform have 32-bit or 64-bit architecture?

The `CMAKE_SIZEOF_VOID_P` variable can be used to figure out the platform's
architecture.

```cmake
if(CMAKE_SIZEOF_VOID_P EQUAL 8)         # 8 byte = 64 bits
    message(STATUS "Target is 64 bits")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)     # 4 byte = 32 bits
    message(STATUS "Target is 32 bits")
else()
    message(STATUS "CMAKE_SIZEOF_VOID_P: ${CMAKE_SIZEOF_VOID_P}")
endif()
```

# What is the endianness of the system?

In most cases, endianness doesn't matter, but when you're writing bit-wise code
that needs to be portable, CMake will provide you with a `BIG_ENDIAN` or
`LITTLE_ENDIAN` value stored in the `CMAKE_<LANG>_BYTE_ORDER` variable, where
<LANG> is C, CXX, OBJC, or CUDA.

# Configuring the toolchain

## Setting the C++ standard

C++11 isn't recommended for newer projects; try to use the newer C++ releases
like: C++14, C++17, C++20 or so on.

CMake supports setting the standard on a target-per-target basis, which means
that you can have any granularity you like. However, I believe it's better to
converge to a single standard across the project. This can be done by setting
the `CMAKE_CXX_STANDARD` variable to one of the following values: 98, 11, 14,
17, 20, or 23 (since CMake 3.20). This will be a default value for all
subsequently defined targets (so it's best to set it close to the top of the
root listfile). You can override it on a per-target basis if needed, like so:

```cmake
set_project(TARGET <target> PROPERTY CXX_STANDARD <standard>)

set_project(TARGET cars PROPERTY CXX_STANDARD 20)
```

The CXX_STANDARD property mentioned in the previous section won't stop CMake
from continuing with the build, even if the compiler isn't supporting the
desired version – it's treated as a preference. CMake doesn't know if our code
actually uses the brand-new features that aren't available in the previous
compilers, and it will try to work with what it has available. If we know for
certain that this won't be successful, we can set another default flag (which is
overridable in the same manner as the previous one) and explicitly require the
standard we target:

```cmake
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```

In that case, if the latest compiler isn't present in the system (in this case,
GNU GCC 11), the user will just see the following message and the build will
stop:

> Target "Standard" requires the language dialect "CXX23" (with compiler
> extensions), but CMake does not know the compile flags to use to enable it.

## Turning off vendor-specific extensions

Compiler devs add some extra features that aren't in the standard, these feature
can thought as _plugins_. Using these features can result in vendor lock-in and
might be troublesome down the road. Thus, it's a good idea to stay away from
them and use vendor-agnostic code.

Add the following command to disable its vendor-specific extensions:

```cmake
set(CMAKE_CXX_EXTENSIONS OFF)
```

I recommend doing so if possible, as this option will insist on having
vendor-agnostic code.

## Compiling a test file

There's a way in CMake to compile and run a test code to check if everything
(feature) is working as expected. We do so using the `try_run()` command:

```cmake
try_run(run_result compile_result
        ${CMAKE_BINARY_DIR}/test_output
        ${CMAKE_SOURCE_DIR}/main.cpp
        RUN_OUTPUT_VARIABLE output)

message("Is successfully compiled? Answer: ${compile_result}")
message("Run result (program's exit code): ${run_result}")

message("Test program's output: ${output}")
```
