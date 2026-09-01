/**
 * SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/**
 * @file zswapdebug/zswapdebug.cpp
 * Contains the ZSwapDebug class implementation.
*/

#include <filesystem>
#include <fstream>
#include <optional>
#include <string_view>
#include <system_error>

#include "zswapdebug/zswapdebug.hpp"

unsigned long ZSwapDebug::ReadDebugValue(const std::filesystem::path& FullPath) const
{
    unsigned long Result;
    std::ifstream ZSwapSysFs(FullPath);
    ZSwapSysFs >> Result;
    return Result;
}

std::optional<unsigned long> ZSwapDebug::ReadModuleDebugValue(const std::string_view Name) const
{
    const std::filesystem::path FullPath = std::filesystem::path(ModuleDebugPath) / std::filesystem::path(Name);
    if (!std::filesystem::exists(FullPath)) return std::nullopt;
    return ReadDebugValue(FullPath);
}

std::optional<unsigned long> ZSwapDebug::GetPoolLimitHit() const
{
    return ReadModuleDebugValue("pool_limit_hit");
}

std::optional<unsigned long> ZSwapDebug::GetPoolTotalSize() const
{
    return ReadModuleDebugValue("pool_total_size");
}

std::optional<unsigned long> ZSwapDebug::GetRejectAllocFail() const
{
    return ReadModuleDebugValue("reject_alloc_fail");
}

std::optional<unsigned long> ZSwapDebug::GetRejectCompressPoor() const
{
    return ReadModuleDebugValue("reject_compress_poor");
}

std::optional<unsigned long> ZSwapDebug::GetRejectKmemCacheFail() const
{
    return ReadModuleDebugValue("reject_kmemcache_fail");
}

std::optional<unsigned long> ZSwapDebug::GetRejectReclaimFail() const
{
    return ReadModuleDebugValue("reject_reclaim_fail");
}

std::optional<unsigned long> ZSwapDebug::GetRejectCompressFail() const
{
    return ReadModuleDebugValue("reject_compress_fail");
}

std::optional<unsigned long> ZSwapDebug::GetDecompressFail() const
{
    return ReadModuleDebugValue("decompress_fail");
}

std::optional<unsigned long> ZSwapDebug::GetSameFilledPages() const
{
    return ReadModuleDebugValue("same_filled_pages");
}

std::optional<unsigned long> ZSwapDebug::GetStoredPages() const
{
    return ReadModuleDebugValue("stored_pages");
}

std::optional<unsigned long> ZSwapDebug::GetWrittenBackPages() const
{
    return ReadModuleDebugValue("written_back_pages");
}

std::optional<unsigned long> ZSwapDebug::GetIncompressiblePages() const
{
    return ReadModuleDebugValue("stored_incompressible_pages");
}

bool ZSwapDebug::IsDebugAvailable() const
{
    std::error_code error;
    std::filesystem::file_status status = std::filesystem::status(ModuleDebugPath, error);
    return !error && std::filesystem::exists(status) && std::filesystem::is_directory(status);
}
