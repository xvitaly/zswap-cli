#
# SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

include(CheckIncludeFileCXX)

CHECK_INCLUDE_FILE_CXX(
    "format"
    FORMAT_HEADER_FOUND
)

if(NOT FORMAT_HEADER_FOUND)
    message(FATAL_ERROR "Current C++ compiler has no <format> support!")
endif()
