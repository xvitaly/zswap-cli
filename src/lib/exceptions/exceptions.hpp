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
 * Namespace with custom exception types.
*/
namespace Exceptions
{
    /**
     * Class for the "Not supported" exception type.
    */
    class NotSupported : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    /**
     * Class for the "Value exists" exception type.
    */
    class ValueExists : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    /**
     * Class for the "Value not set" exception type.
    */
    class ValueNotSet : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    /**
     * Class for the "Value incorrect" exception type.
    */
    class ValueIncorrect : public std::invalid_argument
    {
    public:
        using std::invalid_argument::invalid_argument;
    };

    /**
     * Class for the "Syscall failure" exception type.
     */
    class SyscallFailure : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    /**
     * Class for the "Configuration file not found" exception type.
     */
    class ConfigNotFound : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    /**
     * Class for the "Swap file or partition not found" exception type.
     */
    class SwapNotFound : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    /**
     * Class for the "virtual file system access failure" exception type.
     */
    class VFSAccessFailure : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    /**
     * Class for the "no super-user privileges" exception type.
     */
    class NoPrivileges : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };

    /**
     * Class for the "empty pool" exception type.
     */
    class EmptyPool : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };
}

#endif // EXCEPTIONS_HPP
