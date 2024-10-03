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
    ZSwapDebug() = default;

    /**
     *  Gets the number of the duplicate entries.
     * @returns Duplicate entries count.
    */
    long GetDuplicateEntry() const;

    /**
     *  Gets the pool limit hits.
     * @returns Pool limit hits.
    */
    long GetPoolLimitHit() const;

    /**
     *  Gets the pool total size value.
     * @returns Pool total size.
    */
    long GetPoolTotalSize() const;

    /**
     *  Gets the number of reject allocation failures.
     * @returns Reject allocation failures.
    */
    long GetRejectAllocFail() const;

    /**
     *  Gets the reject compression poor value.
     * @returns Reject compression poor value.
    */
    long GetRejectCompressPoor() const;

    /**
     *  Gets the number of reject Kmemcache failures.
     * @returns Reject Kmemcache failures.
    */
    long GetRejectKmemCacheFail() const;

    /**
     *  Gets the number of reject reclaim failures.
     * @returns Reject reclaim failures.
    */
    long GetRejectReclaimFail() const;

    /**
     *  Gets the number of the same filled pages.
     * @returns Same filled pages count.
    */
    long GetSameFilledPages() const;

    /**
     *  Gets the number of the stored pages.
     * @returns Stored pages count.
    */
    long GetStoredPages() const;

    /**
     *  Gets the number of the written back pages.
     * @returns Written back pages count.
    */
    long GetWrittenBackPages() const;

    /**
     *  Checks if the debug interface is available for use.
     * @returns Debug interface availability.
    */
    bool IsDebugAvailable() const;
private:
    /**
     *  Stores the kernel module debug path.
    */
    const std::string ModuleDebugPath = "/sys/kernel/debug/zswap/";

    /**
     *  Reads the debug value of the ZSwap kernel module by specified name.
     * @param Name Debug value name.
     * @returns Value.
    */
    long ReadModuleDebugValue(const std::string&) const;
};

#endif // ZSWAPDEBUG_HPP
