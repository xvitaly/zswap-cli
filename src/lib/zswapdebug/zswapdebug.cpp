/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <filesystem>
#include <fstream>
#include <string>

#include "zswapdebug/zswapdebug.hpp"

long ZSwapDebug::GetDuplicateEntry() const
{
    return ReadModuleDebugValue("duplicate_entry");
}

long ZSwapDebug::GetPoolLimitHit() const
{
    return ReadModuleDebugValue("pool_limit_hit");
}

long ZSwapDebug::GetPoolTotalSize() const
{
    return ReadModuleDebugValue("pool_total_size");
}

long ZSwapDebug::GetRejectAllocFail() const
{
    return ReadModuleDebugValue("reject_alloc_fail");
}

long ZSwapDebug::GetRejectCompressPoor() const
{
    return ReadModuleDebugValue("reject_compress_poor");
}

long ZSwapDebug::GetRejectKmemCacheFail() const
{
    return ReadModuleDebugValue("reject_kmemcache_fail");
}

long ZSwapDebug::GetRejectReclaimFail() const
{
    return ReadModuleDebugValue("reject_reclaim_fail");
}

long ZSwapDebug::GetSameFilledPages() const
{
    return ReadModuleDebugValue("same_filled_pages");
}

long ZSwapDebug::GetStoredPages() const
{
    return ReadModuleDebugValue("stored_pages");
}

long ZSwapDebug::GetWrittenBackPages() const
{
    return ReadModuleDebugValue("written_back_pages");
}

bool ZSwapDebug::IsDebugAvailable() const
{
    return std::filesystem::exists(ModuleDebugPath);
}

long ZSwapDebug::ReadModuleDebugValue(const std::string& Name) const
{
    const std::string FullPath = ModuleDebugPath + Name;
    long Result = 0;

    if (std::filesystem::exists(FullPath))
    {
        std::ifstream ZSwapSysFs(FullPath);
        ZSwapSysFs >> Result;
        ZSwapSysFs.close();
    }

    return Result;
}
