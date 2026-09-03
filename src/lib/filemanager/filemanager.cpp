/**
 * SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/**
 * @file filemanager/filemanager.cpp
 * Contains the FileManager namespace implementation.
*/

#include <filesystem>
#include <system_error>

#include "filemanager/filemanager.hpp"

bool FileManager::CheckFileExists(const std::filesystem::path& FullPath)
{
    std::error_code error;
    std::filesystem::file_status status = std::filesystem::status(FullPath, error);
    return !error && std::filesystem::exists(status) && std::filesystem::is_regular_file(status);
}
