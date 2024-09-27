/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef ZSWAPOBJECT_HPP
#define ZSWAPOBJECT_HPP

/** @file zswapobject/zswapobject.hpp
 *  This file gets information from the ZSwap kernel module.
 */

#include <string>

/**
 *  Class with properties and methods for working with the ZSwap kernel
 * module.
*/
class ZSwapObject
{
public:
    /**
     *  Constructor of the ZSwapObject class.
    */
    ZSwapObject();

    /**
     *  Gets the ZSwap enabled value.
     * @returns ZSwap enabled value.
    */
    std::string& GetZSwapEnabled();

    /**
     *  Sets the ZSwap enabled value.
     * @param Value New value.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapEnabled(const std::string&);

    /**
     *  Gets the same filled pages enabled value.
     * @returns Same filled pages enabled value.
    */
    std::string& GetZSwapSameFilledPages();

    /**
     *  Sets the same filled pages enabled value.
     * @param Value New value.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapSameFilledPages(const std::string&);

    /**
     *  Gets the maximum pool percentage value.
     * @returns Maximum pool percentage value.
    */
    std::string& GetZSwapMaxPoolPercent();

    /**
     *  Sets the maximum pool percentage value.
     * @param Value New value.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapMaxPoolPercent(const std::string&);

    /**
     *  Gets the compression algorithm name.
     * @returns Compression algorithm name.
    */
    std::string& GetZSwapCompressor();

    /**
     *  Sets the compression algorithm name.
     * @param Value New value.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapCompressor(const std::string&);

    /**
     *  Gets the kernel's zpool type.
     * @returns Kernel's zpool type.
    */
    std::string& GetZSwapZpool();

    /**
     *  Sets the kernel's zpool type.
     * @param Value New value.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapZpool(const std::string&);

    /**
     *  Gets the accept threshold percentage value.
     * @returns Accept threshold percentage value.
    */
    std::string& GetZSwapAcceptThresholdPercent();

    /**
     *  Sets the accept threshold percentage value.
     * @param Value New value.
     * @exception Raises an instance of std::runtime_error if the kernel
     * version is too old.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapAcceptThresholdPercent(const std::string&);

    /**
     *  Gets the non same filled pages enabled value.
     * @returns Non same filled pages enabled value.
    */
    std::string& GetZSwapNonSameFilledPages();

    /**
     *  Sets the non same filled pages enabled value.
     * @param Value New value.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapNonSameFilledPages(const std::string&);

    /**
     *  Gets the exclusive loads enabled value.
     * @returns Exclusive loads enabled value.
    */
    std::string& GetZSwapExclusiveLoads();

    /**
     *  Sets the exclusive loads enabled value.
     * @param Value New value.
     * @exception Raises an instance of std::runtime_error if the kernel
     * version is too old.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapExclusiveLoads(const std::string&);

    /**
     *  Gets the shrinker enabled value.
     * @returns Shrinker enabled value.
    */
    std::string& GetZSwapShrinkerEnabled();

    /**
     *  Sets the shrinker enabled value.
     * @param Value New value.
     * @exception Raises an instance of std::runtime_error if the kernel
     * version is too old.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapShrinkerEnabled(const std::string&);
private:
    /**
     *  Stores the ZSwap enabled value.
    */
    std::string ZSwapEnabled;

    /**
     *  Determines whether the ZSwap enabled value is available.
    */
    bool ZSwapEnabledAvailable;

    /**
     *  Stores the same filled pages enabled value.
    */
    std::string ZSwapSameFilledPages;

    /**
     *  Determines whether the same filled pages enabled value
     *  is available.
    */
    bool ZSwapSameFilledPagesAvailable;

    /**
     *  Stores the maximum pool percentage value.
    */
    std::string ZSwapMaxPoolPercent;

    /**
     *  Determines whether the maximum pool percentage value
     *  is available.
    */
    bool ZSwapMaxPoolPercentAvailable;

    /**
     *  Stores the compression algorithm name.
    */
    std::string ZSwapCompressor;

    /**
     *  Determines whether the compression algorithm name value
     *  is available.
    */
    bool ZSwapCompressorAvailable;

    /**
     *  Stores the kernel's zpool type.
    */
    std::string ZSwapZpool;

    /**
     *  Determines whether the kernel's zpool type value
     *  is available.
    */
    bool ZSwapZpoolAvailable;

    /**
     *  Stores the accept threshold percentage value.
    */
    std::string ZSwapAcceptThresholdPercent;

    /**
     *  Determines whether the accept threshold percentage value
     *  is available.
    */
    bool ZSwapAcceptThresholdPercentAvailable;

    /**
     *  Stores the non same filled pages enabled value.
    */
    std::string ZSwapNonSameFilledPages;

    /**
     *  Determines whether the non same filled pages enabled value
     *  is available.
    */
    bool ZSwapNonSameFilledPagesAvailable;

    /**
     *  Stores the exclusive loads enabled value.
    */
    std::string ZSwapExclusiveLoads;

    /**
     *  Determines whether the exclusive loads enabled value
     *  is available.
    */
    bool ZSwapExclusiveLoadsAvailable;

    /**
     *  Stores the shrinker enabled value.
    */
    std::string ZSwapShrinkerEnabled;

    /**
     *  Determines whether the shrinker enabled value
     *  is available.
    */
    bool ZSwapShrinkerEnabledAvailable;

    /**
     *  Stores the ZSwap log message template.
    */
    const std::string ZSwapMessageLog = "Writing a new value \"{1}\" to the \"{0}\" variable. The old value was: \"{2}\".";

    /**
     *  Stores the ZSwap error message template for Y or N values.
    */
    const std::string ZSwapErrorBool = "The requested value for the \"{0}\" variable is incorrect (only Y or N are supported).";

    /**
     *  Stores the ZSwap error message template for range values.
    */
    const std::string ZSwapErrorRange = "The requested value for the \"{0}\" variable is out of range [0..100].";

    /**
     *  Stores the ZSwap error message template for empty values.
    */
    const std::string ZSwapErrorEmpty = "The requested value for the \"{0}\" variable is empty.";

    /**
     *  Stores the ZSwap error message template for incorrect kernel version.
    */
    const std::string ZSwapErrorKernel = "Configuring the \"{0}\" variable requires kernel \"{1}\" or later.";

    /**
     *  Stores the ZSwap error message template for the kernel version
     *  that doesn't match the required range.
    */
    const std::string ZSwapErrorKernelRange = "Configuring the \"{0}\" variable requires kernel version from \"{1}\" to \"{2}\".";

    /**
     *  Stores the ZSwap kernel module parameters path.
    */
    const std::string ZSwapModuleParametersPath = "/sys/module/zswap/parameters/";

    /**
     *  Stores the ZSwap enabled internal parameter name.
    */
    const std::string ZSwapEnabledName = "enabled";

    /**
     *  Stores the same filled pages enabled internal parameter name.
    */
    const std::string ZSwapSameFilledPagesName = "same_filled_pages_enabled";

    /**
     *  Stores the required kernel version to work non same filled pages
     *  enabled value.
    */
    const std::string ZSwapSameFilledPagesRequiredKernelVersion = "4.16.0";

    /**
     *  Stores the kernel version after which the same filled pages enabled
     *  value will no longer be available.
    */
    const std::string ZSwapSameFilledPagesUnavailableKernelVersion = "6.10.0";

    /**
     *  Stores the maximum pool percentage internal parameter name.
    */
    const std::string ZSwapMaxPoolPercentName = "max_pool_percent";

    /**
     *  Stores the compression algorithm internal parameter name.
    */
    const std::string ZSwapCompressorName = "compressor";

    /**
     *  Stores the kernel's zpool type internal parameter name.
    */
    const std::string ZSwapZpoolName = "zpool";

    /**
     *  Stores the accept threshold percentage internal parameter name.
    */
    const std::string ZSwapAcceptThresholdPercentName = "accept_threshold_percent";

    /**
     *  Stores the required kernel version to work with accept threshold
     *  percentage values.
    */
    const std::string ZSwapAcceptThresholdRequiredKernelVersion = "5.6.0";

    /**
     *  Stores the non same filled pages enabled internal parameter name.
    */
    const std::string ZSwapNonSameFilledPagesName = "non_same_filled_pages_enabled";

    /**
     *  Stores the required kernel version to work with non same filled pages
     *  enabled value.
    */
    const std::string ZSwapNonSameFilledPagesRequiredKernelVersion = "5.18.0";

    /**
     *  Stores the kernel version after which the non same filled pages enabled
     *  value will no longer be available.
    */
    const std::string ZSwapNonSameFilledPagesUnavailableKernelVersion = "6.10.0";

    /**
     *  Stores the exclusive loads enabled internal parameter name.
    */
    const std::string ZSwapExclusiveLoadsName = "exclusive_loads";

    /**
     *  Stores the required kernel version to work with exclusive loads
     *  value.
    */
    const std::string ZSwapExclusiveLoadsRequiredKernelVersion = "6.5.0";

    /**
     *  Stores the kernel version after which the exclusive loads value will
     *  no longer be available.
    */
    const std::string ZSwapExclusiveLoadsUnavailableKernelVersion = "6.9.0";

    /**
     *  Stores the shrinker enabled internal parameter name.
    */
    const std::string ZSwapShrinkerEnabledName = "shrinker_enabled";

    /**
     *  Stores the required kernel version to work with shrinker enabled
     *  value.
    */
    const std::string ZSwapShrinkerEnabledRequiredKernelVersion = "6.8.0";

    /**
     *  Stores the current kernel version in string format.
    */
    std::string KernelVersion;

    /**
     *  Writes the ZSwap kernel module value.
     * @param Name Name.
     * @param Value Value.
    */
    void WriteZSwapValue(const std::string&, const std::string&);

    /**
     *  Reads the value of the ZSwap kernel module by specified name.
     * @param Name Value name.
     * @returns Value.
    */
    std::string ReadZSwapValue(const std::string&);

    /**
     *  Prints log entry to the standard output.
     * @param Name Parameter name.
     * @param NewValue New value.
     * @param OldValue Old value.
    */
    void WriteLogEntry(const std::string&, const std::string&, const std::string&);

    /**
     *  Reads the current kernel version and and stores it in a private
     *  field.
    */
    void ReadKernelVersion();

    /**
     *  Reads the ZSwap kernel module values.
    */
    void ReadValues();

    /**
     *  Reads the availability of ZSwap kernel options.
    */
    void ReadAvailability();

    /**
     *  Checks if the value matches the specified criteria [0..100].
     * @param Value Value to check.
     * @returns Check results.
     * @retval true If the value belongs to [0..100] range.
     * @retval false Otherwise.
    */
    bool CheckPercent(const std::string&);

    /**
     *  Checks if the value matches the specified criteria (Y or N).
     * @param Value Value to check.
     * @returns Check results.
     * @retval true If the value matches the specified criteria.
     * @retval false Otherwise.
    */
    bool CheckEnabled(const std::string&);

    /**
     *  Checks if the kernel version is higher or equal the required
     *  version.
     * @param RequiredKernelVersion The required kernel version to check.
     * @returns Check results.
     * @retval true If the required kernel version lower than current version.
     * @retval false Otherwise.
    */
    bool CheckKernelVersion(const std::string&);

    /**
     *  Checks if the kernel version is higher or equal the required
     *  minimum version and less than the required maximum version.
     * @param MinKernelVersion The required minimum kernel version to check.
     * @param MaxKernelVersion The required maximum kernel version to check.
     * @returns Check results.
     * @retval true If the current version is out of version range.
     * @retval false Otherwise.
    */
    bool CheckKernelVersionRange(const std::string&, const std::string&);
};

#endif // ZSWAPOBJECT_HPP
