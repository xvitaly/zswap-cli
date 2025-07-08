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
#include <string>

#include "zswapdebug/zswapdebug.hpp"

unsigned long ZSwapDebug::GetPoolLimitHit() const
{
    return ReadModuleDebugValue("pool_limit_hit", 0UL);
}

unsigned long ZSwapDebug::GetPoolTotalSize() const
{
    return ReadModuleDebugValue("pool_total_size", 0UL);
}

unsigned long ZSwapDebug::GetRejectAllocFail() const
{
    return ReadModuleDebugValue("reject_alloc_fail", 0UL);
}

unsigned long ZSwapDebug::GetRejectCompressPoor() const
{
    return ReadModuleDebugValue("reject_compress_poor", 0UL);
}

unsigned long ZSwapDebug::GetRejectKmemCacheFail() const
{
    return ReadModuleDebugValue("reject_kmemcache_fail", 0UL);
}

unsigned long ZSwapDebug::GetRejectReclaimFail() const
{
    return ReadModuleDebugValue("reject_reclaim_fail", 0UL);
}

unsigned long ZSwapDebug::GetRejectCompressFail() const
{
    return ReadModuleDebugValue("reject_compress_fail", 0UL);
}

unsigned long ZSwapDebug::GetSameFilledPages() const
{
    return ReadModuleDebugValue("same_filled_pages", 0UL);
}

unsigned long ZSwapDebug::GetStoredPages() const
{
    return ReadModuleDebugValue("stored_pages", 0UL);
}

unsigned long ZSwapDebug::GetWrittenBackPages() const
{
    return ReadModuleDebugValue("written_back_pages", 0UL);
}

bool ZSwapDebug::IsDebugAvailable() const
{
    return std::filesystem::exists(ModuleDebugPath);
}

unsigned long ZSwapDebug::ReadModuleDebugValue(const std::string& Name, const unsigned long& Default) const
{
    const std::string FullPath = ModuleDebugPath + Name;
    unsigned long Result = Default;

    if (std::filesystem::exists(FullPath))
    {
        std::ifstream ZSwapSysFs(FullPath);
        ZSwapSysFs >> Result;
    }

    return Result;
}
