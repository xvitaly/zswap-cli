#
# SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
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

    function(build_manpage SrcName DestName)
        add_custom_command(
            OUTPUT "${DestName}"
            COMMAND "${Pandoc_EXECUTABLE}"
            ARGS "${SrcName}" -s -t man -o "${DestName}"
            DEPENDS "${SrcName}"
            COMMENT "Building the ${DestName} manpage using Pandoc."
            VERBATIM
        )
    endfunction()
endif()
