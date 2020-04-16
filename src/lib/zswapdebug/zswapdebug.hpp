#ifndef ZSWAPDEBUG_HPP
#define ZSWAPDEBUG_HPP

#include "zswapworker/zswapworker.hpp"

class ZSwapDebug
{
public:
    ZSwapDebug();
    std::string& GetDuplicateEntry();
    std::string& GetPoolLimitHit();
    std::string& GetPoolTotalSize();
    std::string& GetRejectAllocFail();
    std::string& GetRejectCompressPoor();
    std::string& GetRejectKmemCacheFail();
    std::string& GetRejectReclaimFail();
    std::string& GetSameFilledPages();
    std::string& GetStoredPages();
    std::string& GetWrittenBackPages();
protected:
    std::string DuplicateEntry;
    std::string PoolLimitHit;
    std::string PoolTotalSize;
    std::string RejectAllocFail;
    std::string RejectCompressPoor;
    std::string RejectKmemCacheFail;
    std::string RejectReclaimFail;
    std::string SameFilledPages;
    std::string StoredPages;
    std::string WrittenBackPages;
private:
    void ReadDebugValues();
};

#endif // ZSWAPDEBUG_HPP
