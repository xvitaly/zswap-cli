#
# SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

include(CheckIncludeFileCXX)

CHECK_INCLUDE_FILE_CXX(
    "linux/sysinfo.h"
    KERNELHEADERS_SYSINFO_FOUND
)

CHECK_INCLUDE_FILE_CXX(
    "linux/version.h"
    KERNELHEADERS_VERSION_FOUND
)

if (NOT KERNELHEADERS_SYSINFO_FOUND OR NOT KERNELHEADERS_VERSION_FOUND)
    message(FATAL_ERROR "Kernel headers were not found.")
endif()
