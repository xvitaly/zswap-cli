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
namespace AppConstants
{
    /**
     * Returns the application internal name as a string.
     * @returns Application internal name.
    */
    std::string_view ProductName();

    /**
     * Returns the application internal version number as a string.
     * @returns Application internal version number.
    */
    std::string_view ProductVersion();

    /**
     * Returns the application internal release as a string.
     * @returns Application internal release.
    */
    std::string_view ProductRelease();
}

#endif // APPCONSTANTS_HPP
