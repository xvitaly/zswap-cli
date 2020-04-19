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

#include <iostream>
#include <stdexcept>
#include <regex>
#include <fmt/format.h>

#include "zswapworker/zswapworker.hpp"

class ZSwapObject
{
public:
    ZSwapObject();
    std::string& GetZSwapEnabled();
    void SetZSwapEnabled(const std::string&);
    std::string& GetZSwapSameFilledPages();
    void SetZSwapSameFilledPages(const std::string&);
    std::string& GetZSwapMaxPoolPercent();
    void SetZSwapMaxPoolPercent(const std::string&);
    std::string& GetZSwapCompressor();
    void SetZSwapCompressor(const std::string&);
    std::string& GetZSwapZpool();
    void SetZSwapZpool(const std::string&);
    std::string& GetZSwapAcceptThrehsoldPercent();
    void SetZSwapAcceptThrehsoldPercent(const std::string&);
protected:
    std::string ZSwapEnabled;
    std::string ZSwapSameFilledPages;
    std::string ZSwapMaxPoolPercent;
    std::string ZSwapCompressor;
    std::string ZSwapZpool;
    std::string ZSwapAcceptThrehsoldPercent;
    const std::string ZSwapEnabledName = "enabled";
    const std::string ZSwapSameFilledPagesName = "same_filled_pages_enabled";
    const std::string ZSwapMaxPoolPercentName = "max_pool_percent";
    const std::string ZSwapCompressorName = "compressor";
    const std::string ZSwapZpoolName = "zpool";
    const std::string ZSwapAcceptThrehsoldPercentName = "accept_threhsold_percent";
private:
    void WriteLogEntry(const std::string&, const std::string&, const std::string&);
    void ReadValues();
    bool CheckPercent(const std::string&);
    bool CheckEnabled(const std::string&);
};

#endif // ZSWAPOBJECT_H
