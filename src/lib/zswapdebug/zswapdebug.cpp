/**
 * SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
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
#include <string>

#include "zswapdebug/zswapdebug.hpp"

std::optional<unsigned long> ZSwapDebug::ReadModuleDebugValue(const std::string& Name) const
{
    const std::string FullPath = ModuleDebugPath + Name;
    if (!std::filesystem::exists(FullPath)) return std::nullopt;
    unsigned long Result;
    std::ifstream ZSwapSysFs(FullPath);
    ZSwapSysFs >> Result;
    return Result;
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

bool ZSwapDebug::IsDebugAvailable() const
{
    return std::filesystem::exists(ModuleDebugPath);
}
