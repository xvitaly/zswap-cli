/**
 * SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef CWRAPPERS_HPP
#define CWRAPPERS_HPP

/**
 * @file cwrappers/cwrappers.hpp
 * Contains the CWrappers namespace definition.
*/

#include <string>

/**
 * Namespace with wrappers for plain C functions.
*/
namespace CWrappers
{
    /**
     * Returns the value of the environment variable, specified by name.
     * @param KeyName Environment variable name.
     * @returns Environment variable value.
    */
    std::string GetEnv(const std::string&);

    /**
     * Returns whether the program is running with super-user privileges.
     * @returns Check results.
     * @retval true Super-user privileges were detected.
     * @retval false Otherwise.
    */
    bool CheckRoot();

    /**
     * Returns the value of the SC_PAGESIZE.
     * @returns SC_PAGESIZE value.
    */
    long GetSCPageSize();
}

#endif // CWRAPPERS_HPP
