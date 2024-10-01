# Installation

## Pre-requirements

Install the Git client, CMake, GCC/Clang compiler with standard library, kernel and libc development packages, and external project dependencies from your distribution's repositories.

## Versions

You need the following versions:

  * C++20 capable compiler: GCC 13+ or Clang 16+;
  * CMake: 3.14+;
  * Boost: 1.70.0+;
  * doxygen (for building documentation);
  * pandoc (for generating manpage).

If no packaged version of the optional dependencies were found, the bundled version will be used.

## Configuration options

This project supports the following build-time configuration options, which can be enabled or disabled using `-DOPTION_NAME=ON/OFF`:

| Name | Description | Default |
| ------- | ------- | ------- |
| BUILD_DOC | Build and install API and application documentation in HTML format. | OFF |
| BUILD_MANPAGE | Build and install manpage with documentation. | OFF |
| LINK_ALL_STATICALLY | Link the program against all libraries statically (no dependencies mode). | OFF |
| LINK_BOOST_STATICALLY | Link the program against Boost library statically (removes dependency on it). | OFF |
| LINK_ENABLE_OPTIMIZATIONS | Enable link-time optimizations if supported by current C++ compiler. | ON |
| SYSTEMD_INTEGRATION | Generate and install systemd units. | ON |

Any other non-default options related to external dependencies are not supported and should not be used.

## Downloading sources

Download sources using Git:

```
git clone --depth=1 https://github.com/xvitaly/zswap-cli.git zswap-cli
```

You can also use the [release tarballs](https://github.com/xvitaly/zswap-cli/releases).

## Building from sources

Start the build process:

```
cmake -S zswap-cli -B zswap-cli/build -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build zswap-cli/build
```

## Installing binaries

Install the result:

```
sudo cmake --install zswap-cli/build
```
