/**
 * SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef LOGGER_HPP
#define LOGGER_HPP

/**
 * @file logger/logger.hpp
 * Contains logger implementation.
*/

#include <format>
#include <iostream>

/**
 * Namespace with logger implementation.
*/
namespace Logger
{
    /**
     * Logs an error.
     * @param args Messages for the log.
    */
    template<typename... Args>
    void Error(const Args&... args)
    {
        std::cerr << "[!] ";
        (std::cerr << ... << args) << std::endl;
    }

    /**
     * Logs a failure.
     * @param args Messages for the log.
     */
    template<typename... Args>
    void Failure(const Args&... args)
    {
        std::cerr << "[-] ";
        (std::cerr << ... << args) << std::endl;
    }

    /**
     * Logs an informational message.
     * @param args Messages for the log.
    */
    template<typename... Args>
    void Info(const Args&... args)
    {
        std::cout << "[*] ";
        (std::cout << ... << args) << std::endl;
    }

    /**
     * Logs a successful result.
     * @param args Messages for the log.
    */
    template<typename... Args>
    void Success(const Args&... args)
    {
        std::cout << "[+] ";
        (std::cout << ... << args) << std::endl;
    }

    /**
     * Logs a simple message without any symbolic prefixes.
     * @param args Messages for the log.
     */
    template<typename... Args>
    void Message(const Args&... args)
    {
        (std::cout << ... << args) << std::endl;
    }

    /**
     * Logs a tuple.
     * @param name Name for the log.
     * @param value Value for the log.
     */
    template<typename T, typename T2>
    void Tuple(const T& name, const T2& value)
    {
        std::cout << std::format("{0}: {1}", name, value) << std::endl;
    }
}

#endif // LOGGER_HPP
