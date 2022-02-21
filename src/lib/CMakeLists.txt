#
# SPDX-FileCopyrightText: 2020-2022 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

set(SOURCES
    cwrappers/cwrappers.cpp
    ksysinfo/ksysinfo.cpp
    ksysversion/ksysversion.cpp
    zswapworker/zswapworker.cpp
    zswapobject/zswapobject.cpp
    zswapdebug/zswapdebug.cpp
)

set(HEADERS
    cwrappers/cwrappers.hpp
    ksysinfo/ksystype.hpp
    ksysinfo/ksysinfo.hpp
    ksysversion/ksysversion.hpp
    zswapworker/zswapworker.hpp
    zswapobject/zswapobject.hpp
    zswapdebug/zswapdebug.hpp
)

configure_file(
    appconstants/appconstants.hpp.in
    generated/appconstants/appconstants.hpp
    @ONLY
)

set(INTERNAL_LIBS
    ${SOURCES}
    ${HEADERS}
)

set(EXTERNAL_LIBS
    fmt::fmt
    semver::semver
)

add_library(${LIB_NAME} OBJECT
    ${INTERNAL_LIBS}
)

target_include_directories(${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/generated
)

target_link_libraries(${LIB_NAME} PRIVATE
    ${EXTERNAL_LIBS}
)
