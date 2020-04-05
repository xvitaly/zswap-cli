cmake_minimum_required(VERSION 3.10)

project(zswap-cli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/External.cmake)
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

add_executable(zswap-cli ${INTERNAL_LIBS})
target_link_libraries(zswap-cli PRIVATE ${EXTERNAL_LIBS})

include(cmake/InstallTargets.cmake)
