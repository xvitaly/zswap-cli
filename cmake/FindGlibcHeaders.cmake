#
# SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

include(CheckIncludeFileCXX)
include(FindPackageHandleStandardArgs)

check_include_file_cxx(
    "sys/sysinfo.h"
    GLIBC_SYSINFO_HEADER
)

check_include_file_cxx(
    "sys/utsname.h"
    GLIBC_UTSNAME_HEADER
)

find_package_handle_standard_args(
    GlibcHeaders
    REQUIRED_VARS GLIBC_SYSINFO_HEADER GLIBC_UTSNAME_HEADER
    REASON_FAILURE_MESSAGE "GLibc headers were not found!"
)
