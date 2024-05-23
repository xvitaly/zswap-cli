#
# SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

find_path(KERNELHEADERS_PATH
    NAMES "linux/kernel.h"
)

if (NOT KERNELHEADERS_PATH)
    message(FATAL_ERROR "Linux kernel headers were not found.")
endif()
