# zswap-cli

[![GitHub version](https://badge.fury.io/gh/xvitaly%2Fzswap-cli.svg)](https://github.com/xvitaly/zswap-cli/releases)
[![Build status](https://travis-ci.org/xvitaly/zswap-cli.svg?branch=master)](https://travis-ci.org/xvitaly/zswap-cli)
[![Build status](https://ci.appveyor.com/api/projects/status/s6a2rtv46jewxwp3?svg=true)](https://ci.appveyor.com/project/xvitaly/zswap-cli)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/xvitaly/zswap-cli.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/xvitaly/zswap-cli/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/xvitaly/zswap-cli.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/xvitaly/zswap-cli/context:cpp)
[![GitHub issues](https://img.shields.io/github/issues/xvitaly/zswap-cli.svg?label=issues&maxAge=180)](https://github.com/xvitaly/zswap-cli/issues)
---

ZSwap-cli is a command-line tool to control [zswap options](https://github.com/torvalds/linux/blob/master/Documentation/vm/zswap.rst).

# Installation

Install CMake, C++ compiler and optional dependencies ([fmt](https://github.com/fmtlib/fmt) and [cxxopts](https://github.com/jarro2783/cxxopts)).

Download sources and build them:

```bash
git clone --depth=1 --recursive https://github.com/xvitaly/zswap-cli.git zswap-cli
cd zswap-cli
mkdir build
cd build
cmake ..
cmake --build .
```

Install:

```bash
cd zswap-cli/build
cmake --install .
```
