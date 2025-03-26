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
    return ReadModuleDebugValue<unsigned long>("pool_limit_hit", 0UL);
}

unsigned long ZSwapDebug::GetPoolTotalSize() const
{
    return ReadModuleDebugValue<unsigned long>("pool_total_size", 0UL);
}

unsigned long ZSwapDebug::GetRejectAllocFail() const
{
    return ReadModuleDebugValue<unsigned long>("reject_alloc_fail", 0UL);
}

unsigned long ZSwapDebug::GetRejectCompressPoor() const
{
    return ReadModuleDebugValue<unsigned long>("reject_compress_poor", 0UL);
}

unsigned long ZSwapDebug::GetRejectKmemCacheFail() const
{
    return ReadModuleDebugValue<unsigned long>("reject_kmemcache_fail", 0UL);
}

unsigned long ZSwapDebug::GetRejectReclaimFail() const
{
    return ReadModuleDebugValue<unsigned long>("reject_reclaim_fail", 0UL);
}

unsigned long ZSwapDebug::GetRejectCompressFail() const
{
    return ReadModuleDebugValue<unsigned long>("reject_compress_fail", 0UL);
}

long ZSwapDebug::GetSameFilledPages() const
{
    return ReadModuleDebugValue<long>("same_filled_pages", 0L);
}

long ZSwapDebug::GetStoredPages() const
{
    return ReadModuleDebugValue<long>("stored_pages", 0L);
}

unsigned long ZSwapDebug::GetWrittenBackPages() const
{
    return ReadModuleDebugValue<unsigned long>("written_back_pages", 0UL);
}

bool ZSwapDebug::IsDebugAvailable() const
{
    return std::filesystem::exists(ModuleDebugPath);
}

template <typename T>
T ZSwapDebug::ReadModuleDebugValue(const std::string& Name, const T& Default) const
{
    const std::string FullPath = ModuleDebugPath + Name;
    T Result = Default;

    if (std::filesystem::exists(FullPath))
    {
        std::ifstream ZSwapSysFs(FullPath);
        ZSwapSysFs >> Result;
    }

    return Result;
}
