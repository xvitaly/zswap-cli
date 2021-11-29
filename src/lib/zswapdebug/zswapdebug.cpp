/**
 * SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include "zswapdebug/zswapdebug.hpp"
#include "zswapworker/zswapworker.hpp"

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

void ZSwapDebug::ReadDebugValues()
{
    ZSwapDebug::DuplicateEntry = ZSwapWorker::ReadZSwapDebugValue("duplicate_entry");
    ZSwapDebug::PoolLimitHit = ZSwapWorker::ReadZSwapDebugValue("pool_limit_hit");
    ZSwapDebug::PoolTotalSize = ZSwapWorker::ReadZSwapDebugValue("pool_total_size");
    ZSwapDebug::RejectAllocFail = ZSwapWorker::ReadZSwapDebugValue("reject_alloc_fail");
    ZSwapDebug::RejectCompressPoor = ZSwapWorker::ReadZSwapDebugValue("reject_compress_poor");
    ZSwapDebug::RejectKmemCacheFail = ZSwapWorker::ReadZSwapDebugValue("reject_kmemcache_fail");
    ZSwapDebug::RejectReclaimFail = ZSwapWorker::ReadZSwapDebugValue("reject_reclaim_fail");
    ZSwapDebug::SameFilledPages = ZSwapWorker::ReadZSwapDebugValue("same_filled_pages");
    ZSwapDebug::StoredPages = ZSwapWorker::ReadZSwapDebugValue("stored_pages");
    ZSwapDebug::WrittenBackPages = ZSwapWorker::ReadZSwapDebugValue("written_back_pages");
}

ZSwapDebug::ZSwapDebug()
{
    ReadDebugValues();
}
