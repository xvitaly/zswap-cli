/**
 * SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

/**
 * @file filemanager/filemanager.hpp
 * Contains the FileManager namespace definition.
*/

#include <filesystem>

/**
 * Namespace with functions for working with files and directories.
*/
namespace FileManager
{
    /**
     * Returns whether the specified file exists.
     * @returns File existence check results.
     * @retval true The specified file exists.
     * @retval false The specified file does not exists.
    */
    bool CheckFileExists(const std::filesystem::path&);
}

#endif // FILEMANAGER_HPP
