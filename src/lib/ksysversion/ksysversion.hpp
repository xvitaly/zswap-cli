/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef KSYSVERSION_HPP
#define KSYSVERSION_HPP

/** @file ksysversion/ksysversion.hpp
 *  This file gets the kernel version using its API.
 */

#include <string>

/**
 *  Class with properties and methods for working with the
 *  kernel version information.
*/
class KSysVersion
{
public:
    /**
     *  Constructor of the KSysVersion class.
    */
    KSysVersion();

    /**
     *  Gets fully qualified kernel version in semver format.
    */
    std::string& GetKernelVersion();

    /**
     *  Gets fully qualified compile time kernel headers version
     *  in semver format.
    */
    std::string& GetHeadersVersion();
private:
    /**
     *  Parses and extracts version number in semver format from fully
     *  qualified kernel version string.
    */
    std::string ParseKernelVersion(const std::string&) const;

    /**
     *  Reads the kernel version string into the class field.
     * @exception Raises an instance of the std::runtime_error on error.
    */
    void ReadKernelVersion();

    /**
     *  Reads the kernel headers version string into the class field.
    */
    void ReadHeadersVersion();

    /**
     *  Stores the kernel version string.
    */
    std::string KernelVersion;

    /**
     *  Stores the kernel headers version string.
    */
    std::string HeadersVersion;
};

#endif // KSYSVERSION_HPP
