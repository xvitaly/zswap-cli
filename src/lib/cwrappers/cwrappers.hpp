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
     * @returns Super-user privileges check results.
     * @retval true Super-user privileges were detected.
     * @retval false Super-user privileges weren't detected.
    */
    bool CheckRoot();

    /**
     * Returns the value of the SC_PAGESIZE constant (memory page size in bytes).
     * @returns SC_PAGESIZE constant value (memory page size in bytes).
    */
    long GetSCPageSize();
}

#endif // CWRAPPERS_HPP
