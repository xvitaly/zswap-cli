/**
 * SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef ZSWAPDEBUG_HPP
#define ZSWAPDEBUG_HPP

/**
 * @file zswapdebug/zswapdebug.hpp
 * Contains the ZSwapDebug class definition.
*/

#include <optional>
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
     * Gets the pool limit hits.
     * @returns Pool limit hits count.
    */
    std::optional<unsigned long> GetPoolLimitHit() const;

    /**
     * Gets the pool total size.
     * @returns Pool total size count.
    */
    std::optional<unsigned long> GetPoolTotalSize() const;

    /**
     * Gets the number of reject allocation failures.
     * @returns Reject allocation failures count.
    */
    std::optional<unsigned long> GetRejectAllocFail() const;

    /**
     * Gets the reject compression poor value.
     * @returns Reject compression poor value.
    */
    std::optional<unsigned long> GetRejectCompressPoor() const;

    /**
     * Gets the number of reject Kmemcache failures.
     * @returns Reject Kmemcache failures count.
    */
    std::optional<unsigned long> GetRejectKmemCacheFail() const;

    /**
     * Gets the number of reject reclaim failures.
     * @returns Reject reclaim failures count.
    */
    std::optional<unsigned long> GetRejectReclaimFail() const;

    /**
     * Gets the number of compression failures.
     * @returns Reject compression failures count.
    */
    std::optional<unsigned long> GetRejectCompressFail() const;

    /**
     * Gets the number of decompression failures.
     * @returns Decompression failures count.
    */
    std::optional<unsigned long> GetDecompressFail() const;

    /**
     * Gets the number of same filled pages.
     * Deprecated. Removed in kernel 6.12.0.
     * @returns Same filled pages count.
    */
    std::optional<unsigned long> GetSameFilledPages() const;

    /**
     * Gets the number of stored pages.
     * @returns Stored pages count.
    */
    std::optional<unsigned long> GetStoredPages() const;

    /**
     * Gets the number of written back pages.
     * @returns Written back pages count.
    */
    std::optional<unsigned long> GetWrittenBackPages() const;

    /**
     * Gets the number of incompressible pages.
     * @returns Incompressible pages count.
    */
    std::optional<unsigned long> GetIncompressiblePages() const;

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
     * specified name as the specified type.
     * @param Name Debug value name.
     * @returns Value of the specified type.
    */
    std::optional<unsigned long> ReadModuleDebugValue(const std::string&) const;
};

#endif // ZSWAPDEBUG_HPP
