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

#ifndef ZSWAPOBJECT_H
#define ZSWAPOBJECT_H

/** @file zswapobject/zswapobject.hpp
 *  This file gets information from the ZSwap kernel module.
 */

#include <iostream>
#include <stdexcept>
#include <regex>
#include <stdexcept>
#include <fmt/format.h>

#include "zswapworker/zswapworker.hpp"

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
     *  Gets the accept threhsold percentage value.
     * @returns Accept threhsold percentage value.
    */
    std::string& GetZSwapAcceptThrehsoldPercent();

    /**
     *  Sets the accept threhsold percentage value.
     * @param Value New value.
     * @exception Raises an instance of std::invalid_argument if cannot set
     * the proposed value.
    */
    void SetZSwapAcceptThrehsoldPercent(const std::string&);
protected:
    /**
     *  Stores the ZSwap enabled value.
    */
    std::string ZSwapEnabled;

    /**
     *  Stores the same filled pages enabled value.
    */
    std::string ZSwapSameFilledPages;

    /**
     *  Stores the maximum pool percentage value.
    */
    std::string ZSwapMaxPoolPercent;

    /**
     *  Stores the compression algorithm name.
    */
    std::string ZSwapCompressor;

    /**
     *  Stores the kernel's zpool type.
    */
    std::string ZSwapZpool;

    /**
     *  Stores the accept threhsold percentage value.
    */
    std::string ZSwapAcceptThrehsoldPercent;

    /**
     *  Stores the ZSwap enabled internal parameter name.
    */
    const std::string ZSwapEnabledName = "enabled";

    /**
     *  Stores the same filled pages enabled internal parameter name.
    */
    const std::string ZSwapSameFilledPagesName = "same_filled_pages_enabled";

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
     *  Stores the accept threhsold percentage internal parameter name.
    */
    const std::string ZSwapAcceptThrehsoldPercentName = "accept_threhsold_percent";
private:
    /**
     *  Prints log entry to the standard output.
     * @param Name Parameter name.
     * @param NewValue New value.
     * @param OldValue Old value.
    */
    void WriteLogEntry(const std::string&, const std::string&, const std::string&);

    /**
     *  Reads the ZSwap kernel module values.
    */
    void ReadValues();

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
};

#endif // ZSWAPOBJECT_H
