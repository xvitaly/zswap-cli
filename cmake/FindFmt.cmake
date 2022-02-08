#
# SPDX-FileCopyrightText: 2020-2022 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

find_package(FMT 6.1.2 QUIET)

if (NOT FMT_FOUND)
    message(STATUS "Using bundled version of fmt library.")
    add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/fmt" EXCLUDE_FROM_ALL)
endif()
