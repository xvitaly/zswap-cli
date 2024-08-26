#
# SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

include(CheckIncludeFileCXX)

CHECK_INCLUDE_FILE_CXX(
    "sys/sysinfo.h"
    GLIBCHEADERS_SYSINFO_FOUND
)

CHECK_INCLUDE_FILE_CXX(
    "sys/utsname.h"
    GLIBCHEADERS_UTSNAME_FOUND
)

if (NOT GLIBCHEADERS_SYSINFO_FOUND OR NOT GLIBCHEADERS_UTSNAME_FOUND)
    message(FATAL_ERROR "GLibc headers were not found.")
endif()
