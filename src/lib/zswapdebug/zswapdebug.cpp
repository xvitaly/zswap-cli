/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <filesystem>
#include <fstream>
#include <string>

#include "zswapdebug/zswapdebug.hpp"

long ZSwapDebug::GetDuplicateEntry()
{
    return ReadModuleDebugValue("duplicate_entry");
}

long ZSwapDebug::GetPoolLimitHit()
{
    return ReadModuleDebugValue("pool_limit_hit");
}

long ZSwapDebug::GetPoolTotalSize()
{
    return ReadModuleDebugValue("pool_total_size");
}

long ZSwapDebug::GetRejectAllocFail()
{
    return ReadModuleDebugValue("reject_alloc_fail");
}

long ZSwapDebug::GetRejectCompressPoor()
{
    return ReadModuleDebugValue("reject_compress_poor");
}

long ZSwapDebug::GetRejectKmemCacheFail()
{
    return ReadModuleDebugValue("reject_kmemcache_fail");
}

long ZSwapDebug::GetRejectReclaimFail()
{
    return ReadModuleDebugValue("reject_reclaim_fail");
}

long ZSwapDebug::GetSameFilledPages()
{
    return ReadModuleDebugValue("same_filled_pages");
}

long ZSwapDebug::GetStoredPages()
{
    return ReadModuleDebugValue("stored_pages");
}

long ZSwapDebug::GetWrittenBackPages()
{
    return ReadModuleDebugValue("written_back_pages");
}

bool ZSwapDebug::IsDebugAvailable()
{
    return std::filesystem::exists(ModuleDebugPath);
}

long ZSwapDebug::ReadModuleDebugValue(const std::string& Name)
{
    long Result = 0;
    std::ifstream ZSwapSysFs(ModuleDebugPath + Name);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}
