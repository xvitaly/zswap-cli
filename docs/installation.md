# Installation

## Pre-requirements

Install Git client, CMake, GCC/Clang compiler and [Boost](https://www.boost.org/) from your distro's repositories.

Optional dependencies:

  * [fmt](https://github.com/fmtlib/fmt);
  * [semver](https://github.com/Neargye/semver).

If no packaged version of optional dependencies were found, the bundled version will be used.

## Versions

You need the following versions:

  * GCC: 7.4+;
  * Clang: 7.0+;
  * CMake: 3.10+;
  * Boost: 1.65.0+;
  * fmt: 6.1.2+ (optional);
  * semver: 0.3.0+ (optional);
  * doxygen (for building documentation);
  * pandoc (for generating manpage).

## Downloading sources

Download sources using Git:

```
git clone --depth=1 --recursive https://github.com/xvitaly/zswap-cli.git zswap-cli
```

You can also use [release tarballs](https://github.com/xvitaly/zswap-cli/releases).

## Building from sources

Run build:

```
cmake -S zswap-cli -B zswap-cli/build -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build zswap-cli/build
```

## Installing binaries

Install result:

```
sudo cmake --install zswap-cli/build
```
