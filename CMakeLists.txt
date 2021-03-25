cmake_minimum_required(VERSION 3.12)

project(zswap-cli
    VERSION 0.4.1
    DESCRIPTION "Command-line tool to control zswap options"
    HOMEPAGE_URL "https://github.com/xvitaly/zswap-cli"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/Settings.cmake)
include(cmake/External.cmake)

include_directories("src/lib")
add_subdirectory("src/lib")

include_directories("src/app")
add_subdirectory("src/app")
