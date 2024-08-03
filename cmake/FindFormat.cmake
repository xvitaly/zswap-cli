#
# SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
#
# SPDX-License-Identifier: MIT
#

include(CheckCXXSourceCompiles)

check_cxx_source_compiles(
    "#if __has_include(<format>)
    #include <format>
    #else
    #error Header <format> is not available.
    #endif
    int main() { return 0; }"
    _FORMAT_HEADER_CHECK)

if(NOT _FORMAT_HEADER_CHECK)
    message(FATAL_ERROR "Current C++ compiler has no <format> support!")
endif()
