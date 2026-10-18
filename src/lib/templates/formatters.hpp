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
#include <optional>
#include <string>

/**
 * Custom formatter for the std::filesystem::path. Backported from C++26.
*/
template <>
struct std::formatter<std::filesystem::path> : std::formatter<std::string>
{
    /**
     * Performs automatic format of the std::filesystem::path instance.
     * @param path Instance of the std::filesystem::path for formatting.
     * @param ctx Format context.
     * @returns Context iterator.
    */
    auto format(const std::filesystem::path& path, std::format_context& ctx) const
    {
        return std::formatter<std::string>::format(path.string(), ctx);
    }
};

/**
 * Custom formatter for the std::optional. Backported from C++26.
*/
template <typename T>
struct std::formatter<std::optional<T>> : std::formatter<T>
{
    /**
     * Performs automatic format of the std::optional instance.
     * @param optional Instance of the std::optional for formatting.
     * @param ctx Format context.
     * @returns Context iterator.
    */
    auto format(const std::optional<T>& optional, std::format_context& ctx) const
    {
        if (optional)
            return std::formatter<T>::format(*optional, ctx);
        return std::format_to(ctx.out(), "N/A");
    }
};

#endif // FORMATTERS_HPP
