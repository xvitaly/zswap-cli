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
     * Deprecated. Removed in kernel 6.9.0.
     * @returns Duplicate entries count.
    */
    unsigned long GetDuplicateEntry() const;

    /**
     * Gets the pool limit hits.
     * @returns Pool limit hits count.
    */
    unsigned long GetPoolLimitHit() const;

    /**
     * Gets the pool total size.
     * @returns Pool total size count.
    */
    unsigned long GetPoolTotalSize() const;

    /**
     * Gets the number of reject allocation failures.
     * @returns Reject allocation failures count.
    */
    unsigned long GetRejectAllocFail() const;

    /**
     * Gets the reject compression poor value.
     * @returns Reject compression poor value.
    */
    unsigned long GetRejectCompressPoor() const;

    /**
     * Gets the number of reject Kmemcache failures.
     * @returns Reject Kmemcache failures count.
    */
    unsigned long GetRejectKmemCacheFail() const;

    /**
     * Gets the number of reject reclaim failures.
     * @returns Reject reclaim failures count.
    */
    unsigned long GetRejectReclaimFail() const;

    /**
     * Gets the number of compression failures.
     * @returns Reject compression failures count.
    */
    unsigned long GetRejectCompressFail() const;

    /**
     * Gets the number of same filled pages.
     * Deprecated. Removed in kernel 6.12.0.
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
    unsigned long GetWrittenBackPages() const;

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
     * specified name as a signed integer.
     * @param Name Debug value name.
     * @returns Value.
    */
    long ReadModuleDebugValueSigned(const std::string&) const;

    /**
     * Reads the debug value of the ZSwap kernel module by the
     * specified name as an unsigned integer.
     * @param Name Debug value name.
     * @returns Value.
    */
    unsigned long ReadModuleDebugValueUnsigned(const std::string&) const;

    /**
     * Reads the debug value of the ZSwap kernel module by the
     * specified name. Template function.
     * @param Name Debug value name.
     * @param Default Default value.
     * @returns Value of the specified type.
    */
    template <typename T>
    T ReadModuleDebugValue(const std::string&, const T&) const;
};

#endif // ZSWAPDEBUG_HPP
