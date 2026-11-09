/**
 * SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

/**
 * @file exceptions/exceptions.hpp
 * Contains definitions of various custom exception types.
*/

#include <stdexcept>

/**
 * Class for the "Not supported" exception type.
*/
class NotSupportedException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

/**
 * Class for the "Value exists" exception type.
*/
class ValueExistsException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

#endif // EXCEPTIONS_HPP
