/*
    Copyright (c) 2020 EasyCoding Team

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

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
