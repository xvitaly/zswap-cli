/**
 * SPDX-FileCopyrightText: 2020-2023 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef CWRAPPERS_HPP
#define CWRAPPERS_HPP

/** @file cwrappers/cwrappers.hpp
 *  This file contains different wrappers for plain C functions.
 */

#include <string>

/**
 *  Static class with wrappers for plain C functions.
*/
class CWrappers
{
public:
    /**
     *  Gets the value of the environment variable, specified by name.
     * @param KeyName Environment variable name.
     * @returns Environment variable value.
    */
    static std::string GetEnv(const std::string&);

    /**
     *  Checks if the program is running with super-user privileges.
     * @returns Check results.
     * @retval true Super-user privileges were detected.
     * @retval false Otherwise.
    */
    static bool CheckRoot();

    /**
     *  Gets the value of the SC_PAGESIZE.
     * @returns SC_PAGESIZE value.
    */
    static long GetSCPageSize();
private:
    /**
     *  Default constructor of the CWrappers class. No one should use it.
    */
    CWrappers() = default;
};

#endif // CWRAPPERS_HPP
