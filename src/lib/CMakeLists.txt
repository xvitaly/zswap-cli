#
# SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

set(SOURCES
    cwrappers/cwrappers.cpp
    ksysinfo/ksysinfo.cpp
    zswapworker/zswapworker.cpp
    zswapobject/zswapobject.cpp
    zswapdebug/zswapdebug.cpp
)

set(HEADERS
    cwrappers/cwrappers.hpp
    ksysinfo/ksysinfo.hpp
    zswapworker/zswapworker.hpp
    zswapobject/zswapobject.hpp
    zswapdebug/zswapdebug.hpp
)

set(INTERNAL_LIBS
    ${SOURCES}
    ${HEADERS}
)

set(EXTERNAL_LIBS
    fmt::fmt
)

add_library(${LIB_NAME} OBJECT
    ${INTERNAL_LIBS}
)

target_link_libraries(${LIB_NAME} PRIVATE ${EXTERNAL_LIBS})
