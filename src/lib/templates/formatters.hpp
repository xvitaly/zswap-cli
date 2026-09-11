/**
 * SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef FORMATTERS_HPP
#define FORMATTERS_HPP

/**
 * @file templates/formatters.hpp
 * Contains custom formatters for various classes.
*/

#include <filesystem>
#include <format>
#include <string>

/**
 * Custom formatter for the std::filesystem::path. Backported from C++26.
*/
template <>
struct std::formatter<std::filesystem::path> : std::formatter<std::string>
{
    auto format(const std::filesystem::path& path, std::format_context& ctx) const
    {
        return std::formatter<std::string>::format(path.string(), ctx);
    }
};

#endif // FORMATTERS_HPP
