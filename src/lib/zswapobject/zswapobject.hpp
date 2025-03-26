/**
 * SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef ZSWAPOBJECT_HPP
#define ZSWAPOBJECT_HPP

/**
 * @file zswapobject/zswapobject.hpp
 * Contains the ZSwapObject class definition.
*/

#include <string>

/**
 * Class for working with the ZSwap kernel module.
*/
class ZSwapObject
{
public:
    /**
     * Constructor of the ZSwapObject class.
    */
    ZSwapObject() = default;

    /**
     * Gets the ZSwap enabled value.
     * @returns ZSwap enabled value.
    */
    std::string GetZSwapEnabled() const;

    /**
     * Sets the ZSwap enabled value.
     * @param Value New value.
    */
    void SetZSwapEnabled(const std::string&) const;

    /**
     * Gets the same filled pages enabled value.
     * @returns Same filled pages enabled value.
    */
    std::string GetZSwapSameFilledPages() const;

    /**
     * Sets the same filled pages enabled value.
     * @param Value New value.
    */
    void SetZSwapSameFilledPages(const std::string&) const;

    /**
     * Gets the maximum pool percentage value.
     * @returns Maximum pool percentage value.
    */
    std::string GetZSwapMaxPoolPercent() const;

    /**
     * Sets the maximum pool percentage value.
     * @param Value New value.
    */
    void SetZSwapMaxPoolPercent(const std::string&) const;

    /**
     * Gets the compression algorithm name.
     * @returns Compression algorithm name.
    */
    std::string GetZSwapCompressor() const;

    /**
     * Sets the compression algorithm name.
     * @param Value New value.
    */
    void SetZSwapCompressor(const std::string&) const;

    /**
     * Gets the kernel's zpool type.
     * @returns Kernel's zpool type.
    */
    std::string GetZSwapZpool() const;

    /**
     * Sets the kernel's zpool type.
     * @param Value New value.
    */
    void SetZSwapZpool(const std::string&) const;

    /**
     * Gets the accept threshold percentage value.
     * @returns Accept threshold percentage value.
    */
    std::string GetZSwapAcceptThresholdPercent() const;

    /**
     * Sets the accept threshold percentage value.
     * @param Value New value.
    */
    void SetZSwapAcceptThresholdPercent(const std::string&) const;

    /**
     * Gets the non same filled pages enabled value.
     * @returns Non same filled pages enabled value.
    */
    std::string GetZSwapNonSameFilledPages() const;

    /**
     * Sets the non same filled pages enabled value.
     * @param Value New value.
    */
    void SetZSwapNonSameFilledPages(const std::string&) const;

    /**
     * Gets the exclusive loads enabled value.
     * @returns Exclusive loads enabled value.
    */
    std::string GetZSwapExclusiveLoads() const;

    /**
     * Sets the exclusive loads enabled value.
     * @param Value New value.
    */
    void SetZSwapExclusiveLoads(const std::string&) const;

    /**
     * Gets the shrinker enabled value.
     * @returns Shrinker enabled value.
    */
    std::string GetZSwapShrinkerEnabled() const;

    /**
     * Sets the shrinker enabled value.
     * @param Value New value.
    */
    void SetZSwapShrinkerEnabled(const std::string&) const;

    /**
     * Checks if the ZSwap module is loaded and available for use.
     * @returns ZSwap module availability.
    */
    bool IsAvailable() const;
private:
    /**
     * Stores the ZSwap kernel module options path.
    */
    const std::string ZSwapModuleParametersPath = "/sys/module/zswap/parameters/";

    /**
     * Stores the ZSwap enabled internal option name.
    */
    const std::string ZSwapEnabledName = "enabled";

    /**
     * Stores the same filled pages enabled internal option name.
    */
    const std::string ZSwapSameFilledPagesName = "same_filled_pages_enabled";

    /**
     * Stores the maximum pool percentage internal option name.
    */
    const std::string ZSwapMaxPoolPercentName = "max_pool_percent";

    /**
     * Stores the compression algorithm internal option name.
    */
    const std::string ZSwapCompressorName = "compressor";

    /**
     * Stores the kernel's zpool type internal option name.
    */
    const std::string ZSwapZpoolName = "zpool";

    /**
     * Stores the accept threshold percentage internal option name.
    */
    const std::string ZSwapAcceptThresholdPercentName = "accept_threshold_percent";

    /**
     * Stores the non same filled pages enabled internal option name.
    */
    const std::string ZSwapNonSameFilledPagesName = "non_same_filled_pages_enabled";

    /**
     * Stores the exclusive loads enabled internal option name.
    */
    const std::string ZSwapExclusiveLoadsName = "exclusive_loads";

    /**
     * Stores the shrinker enabled internal option name.
    */
    const std::string ZSwapShrinkerEnabledName = "shrinker_enabled";

    /**
     * Writes a new value to the specified ZSwap kernel module option.
     * @param Name Option name.
     * @param Value Option value.
     * @exception Raises an instance of std::runtime_error if the kernel
     * module option is not available.
    */
    void WriteZSwapValue(const std::string&, const std::string&) const;

    /**
     * Reads the value of the ZSwap kernel module option by the
     * specified name.
     * @param Name Option name.
     * @returns Option value or N/A if not available.
    */
    std::string ReadZSwapValue(const std::string&) const;

    /**
     * Prints the log entry to the standard output.
     * @param Name Option name.
     * @param Value Option value.
    */
    void WriteLogEntry(const std::string&, const std::string&) const;

    /**
     * Checks if the value is Y or N.
     * @param Name Option name.
     * @param Value Option value to check.
     * @exception Raises an instance of std::invalid_argument if the
     * value does not meet the criteria.
    */
    void CheckValueBool(const std::string&, const std::string&) const;

    /**
     * Checks if the value is empty.
     * @param Name Option name.
     * @param Value Option value to check.
     * @exception Raises an instance of std::invalid_argument if the
     * value does not meet the criteria.
    */
    void CheckValueEmpty(const std::string&, const std::string&) const;

    /**
     * Checks if the value is in the [0..100] range.
     * @param Name Option name.
     * @param Value Option value to check.
     * @exception Raises an instance of std::invalid_argument if the
     * value does not meet the criteria.
    */
    void CheckValueRange(const std::string&, const std::string&) const;
};

#endif // ZSWAPOBJECT_HPP
