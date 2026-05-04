#
# SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

find_program(
    PANDOC_EXECUTABLE
    NAMES pandoc
    DOC "pandoc executable"
)
mark_as_advanced(PANDOC_EXECUTABLE)

if (PANDOC_EXECUTABLE)
    execute_process(
        COMMAND ${PANDOC_EXECUTABLE} --version
        OUTPUT_VARIABLE _pandoc_version
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if ("${_pandoc_version}" MATCHES "^pandoc[ \t]+([0-9.]+)")
        set(PANDOC_VERSION_STRING "${CMAKE_MATCH_1}")
    else()
        set(PANDOC_VERSION_STRING "")
    endif()
    unset(_pandoc_version)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    Pandoc
    REQUIRED_VARS PANDOC_EXECUTABLE
    VERSION_VAR PANDOC_VERSION_STRING
)

function(pandoc_build_manpage SrcName DestName)
    add_custom_command(
        OUTPUT "${DestName}"
        COMMAND "${PANDOC_EXECUTABLE}"
        ARGS "${SrcName}" -s -t man -o "${DestName}"
        DEPENDS "${SrcName}"
        COMMENT "Building manpage using Pandoc."
        VERBATIM
    )
endfunction()
