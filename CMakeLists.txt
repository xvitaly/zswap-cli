cmake_minimum_required(VERSION 3.10)

project(zswap-cli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories("src")

set(SOURCES
    src/cwrappers/cwrappers.cpp
    src/zswapworker/zswapworker.cpp
    src/zswapobject/zswapobject.cpp
    src/application/application.cpp
    src/main.cpp
)

set(HEADERS
    src/cwrappers/cwrappers.hpp
    src/zswapworker/zswapworker.hpp
    src/zswapobject/zswapobject.hpp
    src/application/application.hpp
)

set(INTERNAL_LIBS
    ${SOURCES}
    ${HEADERS}
)

set(EXTERNAL_LIBS
    fmt::fmt
)

include(GNUInstallDirs)
include(cmake/FindFmt.cmake)
include(cmake/FindCxxOpts.cmake)

add_executable(zswap-cli ${INTERNAL_LIBS})
target_link_libraries(zswap-cli PRIVATE ${EXTERNAL_LIBS})

configure_file("${CMAKE_SOURCE_DIR}/packaging/assets/zswap-cli.service.in" "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.service" @ONLY)

install(TARGETS zswap-cli RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}" BUNDLE DESTINATION "${CMAKE_INSTALL_BINDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/zswap-cli.service" DESTINATION "lib/systemd/system")
install(FILES "${CMAKE_SOURCE_DIR}/packaging/assets/zswap-cli.default" DESTINATION "${CMAKE_INSTALL_FULL_SYSCONFDIR}/default" RENAME "zswap-cli")
