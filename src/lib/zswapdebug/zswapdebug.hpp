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
