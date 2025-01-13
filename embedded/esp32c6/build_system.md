# Concepts

- A _project_ is a directory that contains all the files and configuration to
  build a single _app_ (executable), as well as additional supporting elements
  such a partition table, data/filesystem partitions, and a bootloader.

- An "app" is an executable that is built by ESP-IDF. A single project will
  usually build two apps: a _bootloader app_ and a _project app_. Where the
  _bootloader app_ is the initial bootloader program that launches the _project
  app_.

- _Components_ are modular pieces of code that are compiled into static
  libraries (`.a` files) and linked to an app. Some are provided by ESP-IDF
  itself and others can be installed later on.

- _Target_ is the hardware for which an application is built.

- (Not of particular interest) _Project configuration_ is held in a single file
  called `sdkconfig` in the root directory of the project and it can be modified
  using the `idf.py menuconfig` command to customize the configuration of the
  project. A single project contains exactly one of these.

# Using the Build System

`idf.py` use the following tools to do the following tasks under-the-hood:

- `CMake`, which configures the project to be built
- `Ninja`, which builds the project
- `esptool.py` for flashing the _target_

If you want to write more _CMake style_ components, please refer to the
documentation more info.

The `idf.py` commands can also be executed with `ninja` or `make` like so:

```sh
idf.py flash

ninja flash

make flash
```

The port or baud rate or both can be set with the help of environment variables.
We can even set them directly in the shell:

```sh
ESPPORT=/dev/ttyACM0 ninja flash
```

Or it can be provided using the `make` syntax:

```sh
make -j3 app-flash ESPPORT=/dev/ttyACM0 ESPBAUD=20000000
```

N.B.: The `make` syntax is cross-platform. Whereas the shell environment
variable will only work in the `bash` or similar shell.

**ESP-IDF works well with Python 3.8+**.

# Example Project Layout

An example project directory tree might look like this:

```
- myProject/
                - CMakeLists.txt
                - sdkconfig

                - bootloader_components/ - boot_component/ - CMakeLists.txt
                                                           - Kconfig
                                                           - src1.c

                - components/ - component1/ - CMakeLists.txt
                                            - Kconfig
                                            - src1.c
                              - component2/ - CMakeLists.txt
                                            - Kconfig
                                            - src1.c
                                            - include/ - component2.h
                - main/       - CMakeLists.txt
                              - src1.c
                              - src2.c
                - build/
```

This example named _myProject_ contains the following elements:

- A top-level project `CMakeLists.txt` file. This file is used by CMake to learn
  how to build the project. It sets project-wide CMake variables and it includes
  other files which implements rest of the build system. Finally, it sets the
  project name and defines the project.

- (Not interested) `sdkconfig` project configuration file. This file is
  created/update when `idf.py menuconfig` runs. This file holds the
  configuration for all of the components in the project (including ESP-IDF
  itself). The `sdkconfig` file may or may not be added to the source control
  system.

- `dependencies.lock` file should never be edited manually. The file is
  generated or updated automatically when IDF Component Manager is used to add
  or update project components. If the project doesn't have `idf_component.yml`
  files in any of its components, then the file won't be created.

- (Optional) `idf_component.yml` file contains metadata about the component and
  its dependencies. It's used by the **IDF Component Manager** to download and
  resolve these dependencies.

- (Optional) `bootloader_components` directory contains components that need to
  be compiled and linked inside the bootloader project. A project doesn't have
  to contain custom bootloader components of this kind, but it can be useful in
  case the bootloader needs to be modified to embed new features.

- (Optional) `components` directory contains components that are part of the
  project. Alternatively, one can set the `EXTRA_COMPONENT_DIRS` CMake variable
  in the top-level CMakeLists.txt file to look for components in other places.

- `main` directory is a special component that contains source code for the
  project itself. `main` is a defalut name, the CMake variable `COMPONENT_DIR`
  includes this component but you can modify this variable. (See the renaming
  main section in the ESP-IDF doc for more info) If you have a lot of source
  files in your project, it's recommended to group most of them into components
  instead of putting them all in `main`.

- `build` directory is where the build output is created.

- `managed_components` directory is created by the IDF Component Manager to
  store components managed by this tool. Each managed component typically
  includes a `idf_component.yml` manifest file defining the components's
  metadata, such as version and dependencies. However, for components sourced
  from git repos, the manifest file is optional. Users should avoid manually
  modifying the contents of the `managed_components` directory. If modification
  is needed, they can be copied into the `components` directory. The
  `managed_components` directory is not usually commited to git.

  # Project CMakeLists File (Top-level CMakeLists.txt)
