#
# SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

find_path(GLIBCHEADERS_PATH
    NAMES "sys/sysinfo.h"
)

if (NOT GLIBCHEADERS_PATH)
    message(FATAL_ERROR "GLibc headers were not found.")
endif()
