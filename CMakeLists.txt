#
# SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

# ======================================================
# =============== Project initialization ===============
# ======================================================

cmake_minimum_required(VERSION 3.14)

project(zswap-cli
    VERSION 0.9.1
    DESCRIPTION "Command-line tool to control zswap options"
    HOMEPAGE_URL "https://github.com/xvitaly/zswap-cli"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ======================================================
# ================== Project options ===================
# ======================================================

option(BUILD_DOC "Build documentation." OFF)
option(BUILD_MANPAGE "Build manpage." OFF)
option(LINK_BOOST_STATICALLY "Link against Boost statically." OFF)
option(SYSTEMD_INTEGRATION "Generate and install systemd units." ON)

# ======================================================
# ==================== Target names ====================
# ======================================================

set(APP_NAME "${CMAKE_PROJECT_NAME}")
set(LIB_NAME "${CMAKE_PROJECT_NAME}-lib")
set(DOCS_NAME "${CMAKE_PROJECT_NAME}-docs")
set(MAN_NAME "${CMAKE_PROJECT_NAME}-man")
set(UNIT_NAME "${CMAKE_PROJECT_NAME}")

# ======================================================
# ================= Internal imports ===================
# ======================================================

include(GNUInstallDirs)
include(FetchContent)

# ======================================================
# ============= External custom imports ================
# ======================================================

include(cmake/FindFormat.cmake)
include(cmake/FindPandoc.cmake)
include(cmake/FindKernelHeaders.cmake)
include(cmake/FindGlibcHeaders.cmake)

# ======================================================
# ================== Boost detection ===================
# ======================================================

set(Boost_USE_STATIC_LIBS ${LINK_BOOST_STATICALLY})
find_package(Boost 1.65.0 COMPONENTS program_options REQUIRED)

# ======================================================
# ================= Doxygen detection ==================
# ======================================================

if (BUILD_DOC)
    find_package(Doxygen REQUIRED)
    set(DOXYGEN_QUIET YES)
    set(DOXYGEN_RECURSIVE YES)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN NO)
    set(DOXYGEN_QT_AUTOBRIEF YES)
    set(DOXYGEN_MARKDOWN_SUPPORT YES)
    set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
    set(DOXYGEN_EXTRACT_PRIVATE YES)
    set(DOXYGEN_EXTRACT_PRIV_VIRTUAL YES)
    set(DOXYGEN_EXTRACT_PACKAGE YES)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_EXTRACT_LOCAL_CLASSES YES)
    set(DOXYGEN_EXTRACT_LOCAL_METHODS YES)
    set(DOXYGEN_SHOW_INCLUDE_FILES YES)
    set(DOXYGEN_BINARY_TOC YES)
    set(DOXYGEN_TOC_EXPAND YES)
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "README.md")
endif()

# ======================================================
# ================= semver detection ===================
# ======================================================

find_package(semver 0.3.0 QUIET)

if (NOT semver_FOUND)
    message(STATUS "Using bundled version of semver library.")
    FetchContent_Declare(
        semver
        GIT_REPOSITORY "https://github.com/Neargye/semver.git"
        GIT_TAG "v0.3.1"
    )
    FetchContent_MakeAvailable(semver)
endif()

# ======================================================
# ================= systemd detection ==================
# ======================================================

if (SYSTEMD_INTEGRATION)
    if (CMAKE_VERSION VERSION_LESS "3.28")
        set(SYSTEMD_UNITDIR "lib/systemd/system")
    else()
        find_package(PkgConfig REQUIRED)
        pkg_check_modules(SYSTEMD REQUIRED IMPORTED_TARGET systemd)
        pkg_get_variable(SYSTEMD_UNITDIR systemd "systemdsystemunitdir" DEFINE_VARIABLES "prefix=${CMAKE_INSTALL_PREFIX}" "rootprefix=${CMAKE_INSTALL_PREFIX}")
    endif()
endif()

# ======================================================
# ================== Library target ====================
# ======================================================

set(LIBRARY_HEADERS
    src/lib/cwrappers/cwrappers.hpp
    src/lib/ksysinfo/ksystype.hpp
    src/lib/ksysinfo/ksysinfo.hpp
    src/lib/ksysversion/ksysversion.hpp
    src/lib/zswapobject/zswapobject.hpp
    src/lib/zswapdebug/zswapdebug.hpp
)

set(LIBRARY_SOURCES
    src/lib/cwrappers/cwrappers.cpp
    src/lib/ksysinfo/ksysinfo.cpp
    src/lib/ksysversion/ksysversion.cpp
    src/lib/zswapobject/zswapobject.cpp
    src/lib/zswapdebug/zswapdebug.cpp
)

configure_file(
    src/lib/appconstants/appconstants.hpp.in
    generated/appconstants/appconstants.hpp
    @ONLY
)

add_library(${LIB_NAME} OBJECT
    ${LIBRARY_HEADERS}
    ${LIBRARY_SOURCES}
)

target_include_directories(${LIB_NAME} PUBLIC
    src/lib
    "${CMAKE_CURRENT_BINARY_DIR}/generated"
)

target_link_libraries(${LIB_NAME} PUBLIC
    semver::semver
)

# ======================================================
# ================= Application target =================
# ======================================================

set(APPLICATION_HEADERS
    src/app/application/application.hpp
)

set(APPLICATION_SOURCES
    src/app/application/application.cpp
    src/app/main.cpp
)

add_executable(${APP_NAME}
    ${APPLICATION_HEADERS}
    ${APPLICATION_SOURCES}
)

target_include_directories(${APP_NAME} PRIVATE
    src/app
)

target_link_libraries(${APP_NAME} PRIVATE
    ${LIB_NAME}
    Boost::program_options
)

install(TARGETS ${APP_NAME} DESTINATION ${CMAKE_INSTALL_SBINDIR})

# ======================================================
# =================== Assets target ====================
# ======================================================

if (BUILD_DOC)
    doxygen_add_docs(${DOCS_NAME} src docs ALL WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} COMMENT "Building documentation with Doxygen.")
    install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/html/" DESTINATION ${CMAKE_INSTALL_DOCDIR})
endif()

if (BUILD_MANPAGE)
    configure_file("assets/manpage/${CMAKE_PROJECT_NAME}.md.in" "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.md" @ONLY)
    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" COMMAND "${Pandoc_EXECUTABLE}" ARGS "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.md" -s -t man -o "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" COMMENT "Building manpage using Pandoc." VERBATIM)
    add_custom_target(${MAN_NAME} ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1")
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" DESTINATION "${CMAKE_INSTALL_MANDIR}/man1")
endif()

if (SYSTEMD_INTEGRATION)
    configure_file("assets/systemd/${CMAKE_PROJECT_NAME}.service.in" "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.service" @ONLY)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.service" DESTINATION "${SYSTEMD_UNITDIR}" RENAME "${UNIT_NAME}.service")
endif()

install(FILES "assets/config/${CMAKE_PROJECT_NAME}.conf" DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}/${CMAKE_PROJECT_NAME}" RENAME "${APP_NAME}.conf")
