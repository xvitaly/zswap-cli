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

/**
 * Class for the "Value not set" exception type.
*/
class ValueNotSetException : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

/**
 * Class for the "Value incorrect" exception type.
*/
class ValueIncorrectException : public std::invalid_argument
{
public:
    using std::invalid_argument::invalid_argument;
};

/**
 * Class for the "Syscall failure" exception type.
 */
class SyscallFailureException : public std::runtime_error
{
  public:
    using std::runtime_error::runtime_error;
};

/**
 * Class for the "Configuration file not found" exception type.
 */
class ConfigNotFoundException : public std::runtime_error
{
  public:
    using std::runtime_error::runtime_error;
};

/**
 * Class for the "Swap file or partition not found" exception type.
 */
class SwapNotFoundException : public std::runtime_error
{
  public:
    using std::runtime_error::runtime_error;
};

#endif // EXCEPTIONS_HPP
