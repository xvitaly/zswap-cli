#
# SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

include(CheckIncludeFileCXX)
include(FindPackageHandleStandardArgs)

check_include_file_cxx(
    "format"
    FORMAT_HEADER
)

find_package_handle_standard_args(
    FormatHeader
    REQUIRED_VARS FORMAT_HEADER
    REASON_FAILURE_MESSAGE "Current C++ compiler has no <format> support!"
)
