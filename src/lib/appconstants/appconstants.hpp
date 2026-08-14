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
     * Returns the full path to the configuration file installed
     * by the package.
     * @returns Full path to the system configuration file.
    */
    std::string_view SystemConfigFile();

    /**
     * Returns the full path to configuration file created and modified
     * by the user.
     * @returns Full path to the user configuration file.
    */
    std::string_view UserConfigFile();

    /**
     * Returns the application name as a string.
     * @returns Application name.
    */
    std::string_view ProductName();

    /**
     * Returns the application version number as a string.
     * @returns Application version number.
    */
    std::string_view ProductVersion();

    /**
     * Returns the application release as a string.
     * @returns Application release.
    */
    std::string_view ProductRelease();
}

#endif // APPCONSTANTS_HPP
