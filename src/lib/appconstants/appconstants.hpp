/**
 * SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef APPCONSTANTS_HPP
#define APPCONSTANTS_HPP

/**
 * @file appconstants/appconstants.hpp
 * Contains the AppConstants namespace definition.
*/

#include <string_view>

/**
 * Namespace for working with various constants used in project.
*/
namespace AppConstants {
    /**
     * Returns the application internal name as a string.
    */
    std::string_view ProductNameInternal();

    /**
     * Returns the application version number as a string.
    */
    std::string_view ProductVersionInternal();
}

#endif // APPCONSTANTS_HPP
