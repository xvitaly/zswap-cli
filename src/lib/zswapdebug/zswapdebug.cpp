/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <fstream>
#include <string>

#include "zswapdebug/zswapdebug.hpp"

long& ZSwapDebug::GetDuplicateEntry()
{
    return DuplicateEntry;
}

long& ZSwapDebug::GetPoolLimitHit()
{
    return PoolLimitHit;
}

long& ZSwapDebug::GetPoolTotalSize()
{
    return PoolTotalSize;
}

long& ZSwapDebug::GetRejectAllocFail()
{
    return RejectAllocFail;
}

long& ZSwapDebug::GetRejectCompressPoor()
{
    return RejectCompressPoor;
}

long& ZSwapDebug::GetRejectKmemCacheFail()
{
    return RejectKmemCacheFail;
}

long& ZSwapDebug::GetRejectReclaimFail()
{
    return RejectReclaimFail;
}

long& ZSwapDebug::GetSameFilledPages()
{
    return SameFilledPages;
}

long& ZSwapDebug::GetStoredPages()
{
    return StoredPages;
}

long& ZSwapDebug::GetWrittenBackPages()
{
    return WrittenBackPages;
}

const std::string& ZSwapDebug::GetModulePath()
{
    return ModuleDebugPath;
}

long ZSwapDebug::ReadModuleDebugValue(const std::string& Name)
{
    long Result = 0;
    std::ifstream ZSwapSysFs(ModuleDebugPath + Name);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}

void ZSwapDebug::ReadDebugValues()
{
    DuplicateEntry = ReadModuleDebugValue("duplicate_entry");
    PoolLimitHit = ReadModuleDebugValue("pool_limit_hit");
    PoolTotalSize = ReadModuleDebugValue("pool_total_size");
    RejectAllocFail = ReadModuleDebugValue("reject_alloc_fail");
    RejectCompressPoor = ReadModuleDebugValue("reject_compress_poor");
    RejectKmemCacheFail = ReadModuleDebugValue("reject_kmemcache_fail");
    RejectReclaimFail = ReadModuleDebugValue("reject_reclaim_fail");
    SameFilledPages = ReadModuleDebugValue("same_filled_pages");
    StoredPages = ReadModuleDebugValue("stored_pages");
    WrittenBackPages = ReadModuleDebugValue("written_back_pages");
}

ZSwapDebug::ZSwapDebug()
{
    ReadDebugValues();
}
