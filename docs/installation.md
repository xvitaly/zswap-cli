# Installation

## Pre-requirements

Install Git client, CMake, GCC/Clang compiler and optional dependencies Boost and ([fmt](https://github.com/fmtlib/fmt) from your distro's repositories.

If the packaged version of optional dependency will not be found, the bundled one will be used.

## Versions

You need the following versions:

  * GCC: 7.4+;
  * Clang: 7.0+;
  * CMake: 3.10+;
  * Boost: 1.65.0+;
  * fmt: 6.1.2+;
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
cd zswap-cli
mkdir build
cd build
cmake ..
cmake --build .
```

## Installing binaries

Install result:

```
cd zswap-cli/build
sudo make install
```
