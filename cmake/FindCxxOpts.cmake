find_path(CXXOPTS_INCLUDE_DIR NAMES "cxxopts.hpp" PATHS "${CMAKE_SOURCE_DIR}/3rdparty/cxxopts/include")
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CXXOPTS DEFAULT_MSG CXXOPTS_INCLUDE_DIR)

add_library(cxxopts INTERFACE IMPORTED GLOBAL)
target_include_directories(cxxopts INTERFACE ${CXXOPTS_INCLUDE_DIR})
