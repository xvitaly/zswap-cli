/**
 * SPDX-FileCopyrightText: 2020-2023 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef KSYSVERSION_HPP
#define KSYSVERSION_HPP

/** @file ksysversion/ksysversion.hpp
 *  This file gets the Linux kernel version using its API.
 */

#include <string>
#include <sys/utsname.h>

/**
 *  Class with properties and methods for working with the Linux
 *  kernel version information.
*/
class KSysVersion
{
public:
    /**
     *  Constructor of the KSysVersion class.
     * @exception Raises an instance of std::runtime_error on error.
    */
    KSysVersion();

    /**
     *  Gets fully qualified Linux kernel version in semver format.
    */
    std::string GetKernelVersion() const;
private:
    /**
     *  Stores an instance of the utsname structure.
    */
    struct utsname UTSName;

    /**
     *  Parses and extracts version number in semver format from fully
     *  qualified Linux kernel version string.
    */
    std::string ParseKernelVersion(const std::string&) const;
};

#endif // KSYSVERSION_HPP
