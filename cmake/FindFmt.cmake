#
# SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

find_package(FMT 5.2.0 QUIET)

IF (NOT FMT_FOUND)
    message(STATUS "Using bundled version of fmt library.")
    add_subdirectory("${CMAKE_SOURCE_DIR}/3rdparty/fmt" EXCLUDE_FROM_ALL)
ENDIF()
