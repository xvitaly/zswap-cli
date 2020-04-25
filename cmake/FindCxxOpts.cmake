find_package(cxxopts 2.2.0 CONFIG QUIET)

IF (NOT cxxopts_FOUND)
    message(STATUS "Using bundled version of cxxopts library.")
    include_directories("${CMAKE_SOURCE_DIR}/3rdparty/cxxopts/include")
ENDIF()
