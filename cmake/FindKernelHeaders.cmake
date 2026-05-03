#
# SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

include(CheckIncludeFileCXX)
include(FindPackageHandleStandardArgs)

check_include_file_cxx(
    "linux/sysinfo.h"
    KERNEL_SYSINFO_HEADER
)

check_include_file_cxx(
    "linux/version.h"
    KERNEL_VERSION_HEADER
)

find_package_handle_standard_args(
    KernelHeaders
    REQUIRED_VARS KERNEL_SYSINFO_HEADER KERNEL_VERSION_HEADER
    REASON_FAILURE_MESSAGE "Kernel headers were not found!"
)
