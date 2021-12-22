#
# SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

find_package(semver 0.3.0 QUIET)

if (NOT semver_FOUND)
    message(STATUS "Using bundled version of semver library.")
    add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/semver" EXCLUDE_FROM_ALL)
endif()
