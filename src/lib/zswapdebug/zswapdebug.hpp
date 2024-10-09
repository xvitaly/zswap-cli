/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef ZSWAPDEBUG_HPP
#define ZSWAPDEBUG_HPP

/**
 * @file zswapdebug/zswapdebug.hpp
 * Contains the ZSwapDebug class definition.
*/

#include <string>

/**
 * Class for working with the ZSwap kernel module
 * debug information.
*/
class ZSwapDebug
{
public:
    /**
     * Constructor of the ZSwapDebug class.
    */
    ZSwapDebug() = default;

    /**
     * Gets the number of duplicate entries.
     * @returns Duplicate entries count.
    */
    long GetDuplicateEntry() const;

    /**
     * Gets the pool limit hits.
     * @returns Pool limit hits count.
    */
    long GetPoolLimitHit() const;

    /**
     * Gets the pool total size.
     * @returns Pool total size count.
    */
    long GetPoolTotalSize() const;

    /**
     * Gets the number of reject allocation failures.
     * @returns Reject allocation failures count.
    */
    long GetRejectAllocFail() const;

    /**
     * Gets the reject compression poor value.
     * @returns Reject compression poor value.
    */
    long GetRejectCompressPoor() const;

    /**
     * Gets the number of reject Kmemcache failures.
     * @returns Reject Kmemcache failures count.
    */
    long GetRejectKmemCacheFail() const;

    /**
     * Gets the number of reject reclaim failures.
     * @returns Reject reclaim failures count.
    */
    long GetRejectReclaimFail() const;

    /**
     * Gets the number of same filled pages.
     * @returns Same filled pages count.
    */
    long GetSameFilledPages() const;

    /**
     * Gets the number of stored pages.
     * @returns Stored pages count.
    */
    long GetStoredPages() const;

    /**
     * Gets the number of written back pages.
     * @returns Written back pages count.
    */
    long GetWrittenBackPages() const;

    /**
     * Checks if the debug interface is available for use.
     * @returns Debug interface availability.
    */
    bool IsDebugAvailable() const;
private:
    /**
     * Stores the kernel module debug path.
    */
    const std::string ModuleDebugPath = "/sys/kernel/debug/zswap/";

    /**
     * Reads the debug value of the ZSwap kernel module by the
     * specified name.
     * @param Name Debug value name.
     * @returns Value.
    */
    long ReadModuleDebugValue(const std::string&) const;
};

#endif // ZSWAPDEBUG_HPP
