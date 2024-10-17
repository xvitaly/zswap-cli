/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
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

unsigned long ZSwapDebug::GetDuplicateEntry() const
{
    return ReadModuleDebugValueUnsigned("duplicate_entry");
}

unsigned long ZSwapDebug::GetPoolLimitHit() const
{
    return ReadModuleDebugValueUnsigned("pool_limit_hit");
}

unsigned long ZSwapDebug::GetPoolTotalSize() const
{
    return ReadModuleDebugValueUnsigned("pool_total_size");
}

unsigned long ZSwapDebug::GetRejectAllocFail() const
{
    return ReadModuleDebugValueUnsigned("reject_alloc_fail");
}

unsigned long ZSwapDebug::GetRejectCompressPoor() const
{
    return ReadModuleDebugValueUnsigned("reject_compress_poor");
}

unsigned long ZSwapDebug::GetRejectKmemCacheFail() const
{
    return ReadModuleDebugValueUnsigned("reject_kmemcache_fail");
}

unsigned long ZSwapDebug::GetRejectReclaimFail() const
{
    return ReadModuleDebugValueUnsigned("reject_reclaim_fail");
}

unsigned long ZSwapDebug::GetRejectCompressFail() const
{
    return ReadModuleDebugValueUnsigned("reject_compress_fail");
}

long ZSwapDebug::GetSameFilledPages() const
{
    return ReadModuleDebugValueSigned("same_filled_pages");
}

long ZSwapDebug::GetStoredPages() const
{
    return ReadModuleDebugValueSigned("stored_pages");
}

unsigned long ZSwapDebug::GetWrittenBackPages() const
{
    return ReadModuleDebugValueUnsigned("written_back_pages");
}

bool ZSwapDebug::IsDebugAvailable() const
{
    return std::filesystem::exists(ModuleDebugPath);
}

template <typename T>
T ZSwapDebug::ReadModuleDebugValue(const std::string& Name) const
{
    const std::string FullPath = ModuleDebugPath + Name;
    T Result = 0;

    if (std::filesystem::exists(FullPath))
    {
        std::ifstream ZSwapSysFs(FullPath);
        ZSwapSysFs >> Result;
        ZSwapSysFs.close();
    }

    return Result;
}

long ZSwapDebug::ReadModuleDebugValueSigned(const std::string& Name) const
{
    return ReadModuleDebugValue<long>(Name);
}

unsigned long ZSwapDebug::ReadModuleDebugValueUnsigned(const std::string& Name) const
{
    return ReadModuleDebugValue<unsigned long>(Name);
}
