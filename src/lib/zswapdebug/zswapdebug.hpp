/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef ZSWAPDEBUG_HPP
#define ZSWAPDEBUG_HPP

/** @file zswapdebug/zswapdebug.hpp
 *  This file gets debug information from the ZSwap kernel module.
 */

#include <string>

/**
 *  Class with properties and methods for working with the ZSwap kernel
 * module debug information.
*/
class ZSwapDebug
{
public:
    /**
     *  Constructor of the ZSwapDebug class.
    */
    ZSwapDebug();

    /**
     *  Gets the number of the duplicate entries.
     * @returns Duplicate entries count.
    */
    long& GetDuplicateEntry();

    /**
     *  Gets the pool limit hits.
     * @returns Pool limit hits.
    */
    long& GetPoolLimitHit();

    /**
     *  Gets the pool total size value.
     * @returns Pool total size.
    */
    long& GetPoolTotalSize();

    /**
     *  Gets the number of reject allocation failures.
     * @returns Reject allocation failures.
    */
    long& GetRejectAllocFail();

    /**
     *  Gets the reject compression poor value.
     * @returns Reject compression poor value.
    */
    long& GetRejectCompressPoor();

    /**
     *  Gets the number of reject Kmemcache failures.
     * @returns Reject Kmemcache failures.
    */
    long& GetRejectKmemCacheFail();

    /**
     *  Gets the number of reject reclaim failures.
     * @returns Reject reclaim failures.
    */
    long& GetRejectReclaimFail();

    /**
     *  Gets the number of the same filled pages.
     * @returns Same filled pages count.
    */
    long& GetSameFilledPages();

    /**
     *  Gets the number of the stored pages.
     * @returns Stored pages count.
    */
    long& GetStoredPages();

    /**
     *  Gets the number of the written back pages.
     * @returns Written back pages count.
    */
    long& GetWrittenBackPages();

    /**
     *  Gets the kernel module debug path.
     * @returns Kernel module debug path.
    */
    static const std::string& GetModulePath();
protected:
    /**
     *  Stores the number of the duplicate entries.
    */
    long DuplicateEntry;

    /**
     *  Stores the pool limit hits.
    */
    long PoolLimitHit;

    /**
     *  Stores the pool total size value.
    */
    long PoolTotalSize;

    /**
     *  Stores the number of reject allocation failures.
    */
    long RejectAllocFail;

    /**
     *  Stores the reject compression poor value.
    */
    long RejectCompressPoor;

    /**
     *  Stores the number of reject Kmemcache failures.
    */
    long RejectKmemCacheFail;

    /**
     *  Stores the number of reject reclaim failures.
    */
    long RejectReclaimFail;

    /**
     *  Stores the number of the same filled pages.
    */
    long SameFilledPages;

    /**
     *  Stores the number of the stored pages.
    */
    long StoredPages;

    /**
     *  Stores the number of the written back pages.
    */
    long WrittenBackPages;

    /**
     *  Stores the kernel module debug path.
    */
    static inline const std::string ModuleDebugPath = "/sys/kernel/debug/zswap/";
private:
    /**
     *  Reads the ZSwap kernel module debug values.
    */
    void ReadDebugValues();

    /**
     *  Reads the debug value of the ZSwap kernel module by specified name.
     * @param Name Debug value name.
     * @returns Value.
    */
    long ReadModuleDebugValue(const std::string&);
};

#endif // ZSWAPDEBUG_HPP
