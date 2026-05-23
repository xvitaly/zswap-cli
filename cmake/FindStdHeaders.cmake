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
    STD_FORMAT_HEADER
)

check_include_file_cxx(
    "optional"
    STD_OPTIONAL_HEADER
)

find_package_handle_standard_args(
    StdHeaders
    REQUIRED_VARS STD_FILESYSTEM_HEADER STD_FORMAT_HEADER STD_OPTIONAL_HEADER
    REASON_FAILURE_MESSAGE "C++ standard library has no C++20 support!"
)
