#
# SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

find_program(
    APPSTREAMUTIL_EXECUTABLE
    NAMES appstream-util
    DOC "appstream-util executable"
)
mark_as_advanced(APPSTREAMUTIL_EXECUTABLE)

if (APPSTREAMUTIL_EXECUTABLE)
    execute_process(
        COMMAND ${APPSTREAMUTIL_EXECUTABLE} --version
        OUTPUT_VARIABLE _appstreamutil_version
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if ("${_appstreamutil_version}" MATCHES "^[Vv]ersion[:]?[ \t]+([0-9.]+)")
        set(APPSTREAMUTIL_VERSION_STRING "${CMAKE_MATCH_1}")
    else()
        set(APPSTREAMUTIL_VERSION_STRING "")
    endif()
    unset(_appstreamutil_version)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    AppstreamUtil
    REQUIRED_VARS APPSTREAMUTIL_EXECUTABLE
    VERSION_VAR APPSTREAMUTIL_VERSION_STRING
)

set(APPSTREAMUTIL_PARAMETERS "validate")
if (NOT TESTS_ENABLE_NETWORK)
    list(APPEND APPSTREAMUTIL_PARAMETERS "--nonet")
endif()
