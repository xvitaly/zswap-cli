cmake_minimum_required(VERSION 3.10)

project(zswap-cli VERSION 0.4.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/Settings.cmake)
include(cmake/External.cmake)

include_directories("src/app")
include_directories("src/lib")

add_subdirectory("src/lib")
add_subdirectory("src/app")
