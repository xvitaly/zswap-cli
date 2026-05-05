#
# SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

include(CheckIncludeFileCXX)
include(FindPackageHandleStandardArgs)

check_include_file_cxx(
    "filesystem"
    STD_FILESYSTEM_HEADER
)

check_include_file_cxx(
    "format"
    FORMAT_HEADER
)

find_package_handle_standard_args(
    StdHeaders
    REQUIRED_VARS STD_FILESYSTEM_HEADER FORMAT_HEADER
    REASON_FAILURE_MESSAGE "Current C++ standard library has no C++20 support!"
)
