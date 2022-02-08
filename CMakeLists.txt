#
# SPDX-FileCopyrightText: 2020-2022 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

cmake_minimum_required(VERSION 3.12)

project(zswap-cli
    VERSION 0.7.0
    DESCRIPTION "Command-line tool to control zswap options"
    HOMEPAGE_URL "https://github.com/xvitaly/zswap-cli"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/Variables.cmake)
include(cmake/Settings.cmake)
include(cmake/External.cmake)

add_subdirectory("assets")
add_subdirectory("src")
