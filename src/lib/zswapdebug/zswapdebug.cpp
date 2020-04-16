#include "zswapdebug/zswapdebug.hpp"

std::string& ZSwapDebug::GetDuplicateEntry()
{
    return ZSwapDebug::DuplicateEntry;
}

std::string& ZSwapDebug::GetPoolLimitHit()
{
    return ZSwapDebug::PoolLimitHit;
}

std::string& ZSwapDebug::GetPoolTotalSize()
{
    return ZSwapDebug::PoolTotalSize;
}

std::string& ZSwapDebug::GetRejectAllocFail()
{
    return ZSwapDebug::RejectAllocFail;
}

std::string& ZSwapDebug::GetRejectCompressPoor()
{
    return ZSwapDebug::RejectCompressPoor;
}

std::string& ZSwapDebug::GetRejectKmemCacheFail()
{
    return ZSwapDebug::RejectKmemCacheFail;
}

std::string& ZSwapDebug::GetRejectReclaimFail()
{
    return ZSwapDebug::RejectReclaimFail;
}

std::string& ZSwapDebug::GetSameFilledPages()
{
    return ZSwapDebug::SameFilledPages;
}

std::string& ZSwapDebug::GetStoredPages()
{
    return ZSwapDebug::StoredPages;
}

std::string& ZSwapDebug::GetWrittenBackPages()
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
