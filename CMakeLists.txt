#
# SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

# ======================================================
# =============== Project initialization ===============
# ======================================================

cmake_minimum_required(VERSION 3.28...4.0)

project(zswap-cli
    VERSION 1.1.2
    DESCRIPTION "Command-line tool to control the zswap kernel module options"
    HOMEPAGE_URL "https://github.com/xvitaly/zswap-cli"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# ======================================================
# ================== Project options ===================
# ======================================================

option(BUILD_DOC "Build and install API and application documentation in HTML format." OFF)
option(BUILD_MANPAGE "Build and install manpage with documentation." OFF)
option(BUILD_SHELL_COMPLETION "Build and install shell completion helper files." ON)
option(LINK_ALL_STATICALLY "Link the program against all libraries statically (no dependencies mode)." OFF)
option(LINK_BOOST_STATICALLY "Link the program against Boost library statically (removes dependency on it)." OFF)
option(LINK_ENABLE_OPTIMIZATIONS "Enable link-time optimizations if supported by current C++ compiler." ON)
option(SYSTEMD_INTEGRATION "Generate and install systemd units." ON)

# ======================================================
# ==================== Target names ====================
# ======================================================

set(APP_NAME "${CMAKE_PROJECT_NAME}")
set(LIB_NAME "${CMAKE_PROJECT_NAME}-lib")
set(DOCS_NAME "${CMAKE_PROJECT_NAME}-docs")
set(MAN_NAME "${CMAKE_PROJECT_NAME}-man")

# ======================================================
# ================== Components names ==================
# ======================================================

set(APP_COMP_NAME "application")
set(ASSETS_COMP_NAME "assets")

# ======================================================
# ===================== File names =====================
# ======================================================

set(CONF_FILE_NAME "${CMAKE_PROJECT_NAME}.conf")
set(UNIT_FILE_NAME "${CMAKE_PROJECT_NAME}.service")

# ======================================================
# ================= Internal imports ===================
# ======================================================

include(GNUInstallDirs)

# ======================================================
# ============= External custom imports ================
# ======================================================

include(cmake/FindFileSystem.cmake)
include(cmake/FindFormat.cmake)
include(cmake/FindPandoc.cmake)
include(cmake/FindKernelHeaders.cmake)
include(cmake/FindGlibcHeaders.cmake)

# ======================================================
# =========== Link time optimizations checks ===========
# ======================================================

include(CheckIPOSupported)
include(CheckPIESupported)

check_ipo_supported(RESULT CMAKE_CXX_LINK_IPO_SUPPORTED LANGUAGES CXX)
check_pie_supported(LANGUAGES CXX)

# ======================================================
# ================== Boost detection ===================
# ======================================================

if (LINK_BOOST_STATICALLY OR LINK_ALL_STATICALLY)
    set(Boost_USE_STATIC_LIBS ON)
endif()

find_package(Boost 1.70.0 REQUIRED COMPONENTS program_options CONFIG)

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
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "docs/README.md")
endif()

# ======================================================
# ================= systemd detection ==================
# ======================================================

if (SYSTEMD_INTEGRATION)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SYSTEMD REQUIRED IMPORTED_TARGET systemd)
    pkg_get_variable(SYSTEMD_UNITDIR systemd "systemdsystemunitdir" DEFINE_VARIABLES "prefix=${CMAKE_INSTALL_PREFIX}" "rootprefix=${CMAKE_INSTALL_PREFIX}")
endif()

# ======================================================
# ================== Library target ====================
# ======================================================

set(LIBRARY_HEADERS
    src/lib/cwrappers/cwrappers.hpp
    src/lib/ksysinfo/ksysinfo.hpp
    src/lib/ksysversion/ksysversion.hpp
    src/lib/zswapdebug/zswapdebug.hpp
    src/lib/zswapobject/zswapobject.hpp
)

set(LIBRARY_SOURCES
    src/lib/cwrappers/cwrappers.cpp
    src/lib/ksysinfo/ksysinfo.cpp
    src/lib/ksysversion/ksysversion.cpp
    src/lib/zswapdebug/zswapdebug.cpp
    src/lib/zswapobject/zswapobject.cpp
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

if (LINK_ENABLE_OPTIMIZATIONS AND CMAKE_CXX_LINK_IPO_SUPPORTED)
    set_target_properties(${LIB_NAME}
        PROPERTIES INTERPROCEDURAL_OPTIMIZATION ON
    )
endif()

if (LINK_ENABLE_OPTIMIZATIONS AND CMAKE_CXX_LINK_PIE_SUPPORTED)
    set_target_properties(${LIB_NAME}
        PROPERTIES POSITION_INDEPENDENT_CODE ON
    )
endif()

if (LINK_ALL_STATICALLY)
    target_link_libraries(${LIB_NAME} PRIVATE
        -static
    )
endif()

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

if (LINK_ENABLE_OPTIMIZATIONS AND CMAKE_CXX_LINK_IPO_SUPPORTED)
    set_target_properties(${APP_NAME}
        PROPERTIES INTERPROCEDURAL_OPTIMIZATION ON
    )
endif()

if (LINK_ENABLE_OPTIMIZATIONS AND CMAKE_CXX_LINK_PIE_SUPPORTED)
    set_target_properties(${APP_NAME}
        PROPERTIES POSITION_INDEPENDENT_CODE ON
    )
endif()

if (LINK_ALL_STATICALLY)
    target_link_libraries(${APP_NAME} PRIVATE
        -static
    )
endif()

install(TARGETS ${APP_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT ${APP_COMP_NAME})

# ======================================================
# =================== Assets target ====================
# ======================================================

if (BUILD_DOC)
    doxygen_add_docs(${DOCS_NAME} src docs ALL WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} COMMENT "Building documentation with Doxygen.")
    install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/html/" DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT ${ASSETS_COMP_NAME})
endif()

if (BUILD_MANPAGE)
    configure_file("assets/manpage/${APP_NAME}.md.in" "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.md" @ONLY)
    pandoc_build_manpage("${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.md" "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1")
    add_custom_target(${MAN_NAME} ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1")
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.1" DESTINATION "${CMAKE_INSTALL_MANDIR}/man1" COMPONENT ${ASSETS_COMP_NAME})
endif()

if (BUILD_SHELL_COMPLETION)
    configure_file("assets/shell-completion/${APP_NAME}.bash.in" "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.bash" @ONLY)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${APP_NAME}.bash" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/bash-completion/completions" RENAME ${APP_NAME} COMPONENT ${ASSETS_COMP_NAME})
endif()

if (SYSTEMD_INTEGRATION)
    configure_file("assets/systemd/${UNIT_FILE_NAME}.in" "${CMAKE_CURRENT_BINARY_DIR}/${UNIT_FILE_NAME}" @ONLY)
    install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${UNIT_FILE_NAME}" DESTINATION "${SYSTEMD_UNITDIR}" COMPONENT ${ASSETS_COMP_NAME})
    install(FILES "assets/config/${CONF_FILE_NAME}" DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}/${APP_NAME}" COMPONENT ${ASSETS_COMP_NAME})
endif()
