#
# SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

include(CheckIncludeFileCXX)
include(FindPackageHandleStandardArgs)

check_include_file_cxx(
    "filesystem"
    FILESYSTEM_HEADER
)

find_package_handle_standard_args(
    FileSystemHeader
    REQUIRED_VARS FILESYSTEM_HEADER
    REASON_FAILURE_MESSAGE "Current C++ compiler has no <filesystem> support!"
)
