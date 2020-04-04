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

#include "application/application.hpp"

std::string Application::GetEnv(std::string const& KeyName)
{
    char const* EnvValue = getenv(KeyName.c_str());
    return EnvValue != nullptr ? std::string(EnvValue) : std::string();
}

void Application::WriteLogEntry(std::string const& Name, std::string const& NewValue, std::string const& OldValue)
{
    std::cout << fmt::format("Writing to \"{0}\". Value: \"{1}\". Old value was: \"{2}\".", Name, NewValue, OldValue) << std::endl;
}

void Application::WriteZSwapValue(ZSwapObject& ZSwapObj, std::string const& NewValue)
{
    if (ZSwapObj.Validate(NewValue))
    {
        WriteLogEntry(ZSwapObj.GetName(), NewValue, ZSwapObj.GetValue());
        ZSwapObj.SetValue(NewValue);
    }
    else
    {
        std::cerr << fmt::format("Failed to change \"{0}\" variable. Value \"{1}\" does not match regular expression.", ZSwapObj.GetName(), NewValue) << std::endl;
    }
}

void Application::ExecuteEnv()
{
    std::string const ZSwapEnabledEnv = GetEnv("ZSWAP_ENABLED_VALUE");
    std::string const ZSwapSameFilledPagesEnv = GetEnv("ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE");
    std::string const ZSwapMaxPoolPercentEnv = GetEnv("ZSWAP_MAX_POOL_PERCENT_VALUE");
    std::string const ZSwapCompressorEnv = GetEnv("ZSWAP_COMPRESSOR_VALUE");
    std::string const ZSwapZpoolEnv = GetEnv("ZSWAP_ZPOOL_VALUE");
    std::string const ZSwapAcceptThrehsoldPercentEnv = GetEnv("ZSWAP_ACCEPT_THREHSOLD_PERCENT_VALUE");

    if (!ZSwapEnabledEnv.empty()) WriteZSwapValue(ZSwapEnabled, ZSwapEnabledEnv);
    if (!ZSwapSameFilledPagesEnv.empty()) WriteZSwapValue(ZSwapSameFilledPages, ZSwapSameFilledPagesEnv);
    if (!ZSwapMaxPoolPercentEnv.empty()) WriteZSwapValue(ZSwapMaxPoolPercent, ZSwapMaxPoolPercentEnv);
    if (!ZSwapCompressorEnv.empty()) WriteZSwapValue(ZSwapCompressor, ZSwapCompressorEnv);
    if (!ZSwapZpoolEnv.empty()) WriteZSwapValue(ZSwapZpool, ZSwapZpoolEnv);
    if (!ZSwapAcceptThrehsoldPercentEnv.empty()) WriteZSwapValue(ZSwapAcceptThrehsoldPercent, ZSwapAcceptThrehsoldPercentEnv);
}

void Application::ExecuteCmdLine(cxxopts::ParseResult const& CmdLine)
{
    if (CmdLine.count("enabled")) WriteZSwapValue(ZSwapEnabled, CmdLine["enabled"].as<std::string>());
    if (CmdLine.count("same_filled_pages_enabled")) WriteZSwapValue(ZSwapSameFilledPages, CmdLine["same_filled_pages_enabled"].as<std::string>());
    if (CmdLine.count("max_pool_percent")) WriteZSwapValue(ZSwapMaxPoolPercent, CmdLine["max_pool_percent"].as<std::string>());
    if (CmdLine.count("compressor")) WriteZSwapValue(ZSwapCompressor, CmdLine["compressor"].as<std::string>());
    if (CmdLine.count("zpool")) WriteZSwapValue(ZSwapZpool, CmdLine["zpool"].as<std::string>());
    if (CmdLine.count("accept_threhsold_percent")) WriteZSwapValue(ZSwapAcceptThrehsoldPercent, CmdLine["accept_threhsold_percent"].as<std::string>());
}

void Application::Run(cxxopts::ParseResult const& CmdLine)
{
    if (CmdLine.count("env")) ExecuteEnv(); else ExecuteCmdLine(CmdLine);
}

Application::Application()
{
    ZSwapEnabled = ZSwapObject("enabled", "^[YN]$");
    ZSwapSameFilledPages = ZSwapObject("same_filled_pages_enabled", "^[YN]$");
    ZSwapMaxPoolPercent = ZSwapObject("max_pool_percent", "^\\d{1,3}$");
    ZSwapCompressor = ZSwapObject("compressor", "^.*$");
    ZSwapZpool = ZSwapObject("zpool", "^.*$");
    ZSwapAcceptThrehsoldPercent = ZSwapObject("accept_threhsold_percent", "^\\d{1,3}$");
}
