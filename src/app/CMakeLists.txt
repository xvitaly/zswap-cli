#
# SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

set(SOURCES
    application/application.cpp
    main.cpp
)

set(HEADERS
    application/application.hpp
)

set(INTERNAL_LIBS
    ${SOURCES}
    ${HEADERS}
)

set(EXTERNAL_LIBS
    ${LIB_NAME}
    fmt::fmt
    Boost::program_options
)

add_executable(${APP_NAME} ${INTERNAL_LIBS})

if (FILESYSTEM_REQUIRE_LINKAGE)
    list(APPEND EXTERNAL_LIBS stdc++fs)
endif()

if(FILESYSTEM_REQUIRE_EXPERIMENTAL)
    target_compile_definitions(${APP_NAME} PRIVATE FILESYSTEM_LEGACY)
endif()

target_link_libraries(${APP_NAME} PRIVATE ${EXTERNAL_LIBS})

install(TARGETS ${APP_NAME} DESTINATION "${CMAKE_INSTALL_SBINDIR}")
