/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef KSYSVERSION_HPP
#define KSYSVERSION_HPP

/** @file ksysversion/ksysversion.hpp
 *  Contains the KSysVersion class definition.
 */

#include <string>

/**
 *  Class for working with kernel version information.
*/
class KSysVersion
{
public:
    /**
     *  Constructor of the KSysVersion class.
    */
    KSysVersion();

    /**
     *  Gets the kernel version.
    */
    std::string& GetKernelVersion();

    /**
     *  Gets the compile time kernel headers version.
    */
    std::string& GetHeadersVersion();
private:
    /**
     *  Parses and extracts the kernel version from fully
     * qualified kernel version string.
    */
    std::string ParseKernelVersion(const std::string&) const;

    /**
     *  Reads the kernel version string into the class field.
     * @exception Raises an instance of std::runtime_error on error.
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
