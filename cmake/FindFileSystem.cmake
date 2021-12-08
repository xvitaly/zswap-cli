include(CheckCXXSourceCompiles)

check_cxx_source_compiles(
    "#if __has_include(<filesystem>)
    #include <filesystem>
    #else
    #error Header <filesystem> is not available.
    #endif
    int main() { return 0; }"
    _FILESYSTEM_HEADER_CHECK)

check_cxx_source_compiles(
    "#include <ciso646>
    #if defined(_GLIBCXX_RELEASE) && _GLIBCXX_RELEASE >= 9
    #include <filesystem>
    #else
    #error libstdc++ less than version 9 requires linkage with -lstdc++fs
    #endif
    int main() { return 0; }"
    _FILESYSTEM_LIBRARY_CHECK)

if(_FILESYSTEM_HEADER_CHECK)
    set(_FILESYSTEM_REQUIRE_EXPERIMENTAL FALSE)
else()
    set(_FILESYSTEM_REQUIRE_EXPERIMENTAL TRUE)
endif()

if(_FILESYSTEM_LIBRARY_CHECK)
    set(_FILESYSTEM_REQUIRE_LINKAGE FALSE)
else()
    set(_FILESYSTEM_REQUIRE_LINKAGE TRUE)
endif()

set(FILESYSTEM_REQUIRE_EXPERIMENTAL ${_FILESYSTEM_REQUIRE_EXPERIMENTAL} CACHE BOOL "If required to use experimental filesystem headers." FORCE)
set(FILESYSTEM_REQUIRE_LINKAGE ${_FILESYSTEM_REQUIRE_LINKAGE} CACHE BOOL "If required to pass -lstdc++fs in order to use filesystem functions." FORCE)

if(FILESYSTEM_REQUIRE_EXPERIMENTAL)
    set(_FILESYSTEM_OUTPUT "<experimental/filesystem>")
else()
    set(_FILESYSTEM_OUTPUT "<filesystem>")
endif()

if(FILESYSTEM_REQUIRE_LINKAGE)
    set(_FILESYSTEM_OUTPUT "${_FILESYSTEM_OUTPUT} with -lstdc++fs")
endif()

message(STATUS "Found C++ filesystem library: ${_FILESYSTEM_OUTPUT}.")
