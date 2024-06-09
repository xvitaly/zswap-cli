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
    return ZSwapDebug::DuplicateEntry;
}

long& ZSwapDebug::GetPoolLimitHit()
{
    return ZSwapDebug::PoolLimitHit;
}

long& ZSwapDebug::GetPoolTotalSize()
{
    return ZSwapDebug::PoolTotalSize;
}

long& ZSwapDebug::GetRejectAllocFail()
{
    return ZSwapDebug::RejectAllocFail;
}

long& ZSwapDebug::GetRejectCompressPoor()
{
    return ZSwapDebug::RejectCompressPoor;
}

long& ZSwapDebug::GetRejectKmemCacheFail()
{
    return ZSwapDebug::RejectKmemCacheFail;
}

long& ZSwapDebug::GetRejectReclaimFail()
{
    return ZSwapDebug::RejectReclaimFail;
}

long& ZSwapDebug::GetSameFilledPages()
{
    return ZSwapDebug::SameFilledPages;
}

long& ZSwapDebug::GetStoredPages()
{
    return ZSwapDebug::StoredPages;
}

long& ZSwapDebug::GetWrittenBackPages()
{
    return ZSwapDebug::WrittenBackPages;
}

const std::string& ZSwapDebug::GetModulePath()
{
    return ZSwapDebug::ModuleDebugPath;
}

long ZSwapDebug::ReadModuleDebugValue(const std::string& Name)
{
    long Result = 0;
    std::ifstream ZSwapSysFs(ZSwapDebug::ModuleDebugPath + Name);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}

void ZSwapDebug::ReadDebugValues()
{
    ZSwapDebug::DuplicateEntry = ZSwapDebug::ReadModuleDebugValue("duplicate_entry");
    ZSwapDebug::PoolLimitHit = ZSwapDebug::ReadModuleDebugValue("pool_limit_hit");
    ZSwapDebug::PoolTotalSize = ZSwapDebug::ReadModuleDebugValue("pool_total_size");
    ZSwapDebug::RejectAllocFail = ZSwapDebug::ReadModuleDebugValue("reject_alloc_fail");
    ZSwapDebug::RejectCompressPoor = ZSwapDebug::ReadModuleDebugValue("reject_compress_poor");
    ZSwapDebug::RejectKmemCacheFail = ZSwapDebug::ReadModuleDebugValue("reject_kmemcache_fail");
    ZSwapDebug::RejectReclaimFail = ZSwapDebug::ReadModuleDebugValue("reject_reclaim_fail");
    ZSwapDebug::SameFilledPages = ZSwapDebug::ReadModuleDebugValue("same_filled_pages");
    ZSwapDebug::StoredPages = ZSwapDebug::ReadModuleDebugValue("stored_pages");
    ZSwapDebug::WrittenBackPages = ZSwapDebug::ReadModuleDebugValue("written_back_pages");
}

ZSwapDebug::ZSwapDebug()
{
    ReadDebugValues();
}
