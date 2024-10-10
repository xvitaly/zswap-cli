/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef KSYSVERSION_HPP
#define KSYSVERSION_HPP

/**
 * @file ksysversion/ksysversion.hpp
 * Contains the KSysVersion class definition.
*/

#include <string>

/**
 * Class for working with kernel version information.
*/
class KSysVersion
{
public:
    /**
     * Constructor of the KSysVersion class.
    */
    KSysVersion() = default;

    /**
     * Gets the kernel version.
     * @exception Raises an instance of std::runtime_error on error.
    */
    std::string GetKernelVersion() const;

    /**
     * Gets the compile time kernel headers version.
    */
    std::string GetHeadersVersion() const;
private:
    /**
     * Parses and extracts the kernel version from fully
     * qualified kernel version string.
    */
    std::string ParseKernelVersion(const std::string&) const;
};

#endif // KSYSVERSION_HPP
