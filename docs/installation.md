# Installation

## Pre-requirements

Install the Git client, CMake, GCC/Clang compiler, and library dependencies from your distribution's repositories.

## Versions

You need the following versions:

  * GCC: 13+;
  * Clang: 16+;
  * CMake: 3.14+;
  * Boost: 1.65.0+;
  * semver: 0.3.0+ (optional);
  * doxygen (for building documentation);
  * pandoc (for generating manpage).

If no packaged version of the optional dependencies were found, the bundled version will be used.

## Downloading sources

Download sources using Git:

```
git clone --depth=1 --recursive https://github.com/xvitaly/zswap-cli.git zswap-cli
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
