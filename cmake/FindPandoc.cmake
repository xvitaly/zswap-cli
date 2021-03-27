#
# SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

if (BUILD_MANPAGE)
    find_program(
        Pandoc_EXECUTABLE
        NAMES pandoc
        DOC "Pandoc main executable"
        REQUIRED
    )
    mark_as_advanced(Pandoc_EXECUTABLE)
endif()
