#ifndef ZSWAPDEBUG_HPP
#define ZSWAPDEBUG_HPP

#include "zswapworker/zswapworker.hpp"

class ZSwapDebug
{
public:
    ZSwapDebug();
    long& GetDuplicateEntry();
    long& GetPoolLimitHit();
    long& GetPoolTotalSize();
    long& GetRejectAllocFail();
    long& GetRejectCompressPoor();
    long& GetRejectKmemCacheFail();
    long& GetRejectReclaimFail();
    long& GetSameFilledPages();
    long& GetStoredPages();
    long& GetWrittenBackPages();
protected:
    long DuplicateEntry;
    long PoolLimitHit;
    long PoolTotalSize;
    long RejectAllocFail;
    long RejectCompressPoor;
    long RejectKmemCacheFail;
    long RejectReclaimFail;
    long SameFilledPages;
    long StoredPages;
    long WrittenBackPages;
private:
    void ReadDebugValues();
};

#endif // ZSWAPDEBUG_HPP
