/*
    Copyright (c) 2020 EasyCoding Team

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifndef CWRAPPERS_HPP
#define CWRAPPERS_HPP

/** @file cwrappers/cwrappers.hpp
 *  This file contains different wrappers for plain C functions.
 */

#include <string>
#include <unistd.h>

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
