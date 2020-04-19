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

bool Application::CheckIfRunningBySuperUser()
{
    if (CWrappers::CheckRoot())
    {
        std::cerr << "This program must be run by the super-user. Terminating." << std::endl;
        return true;
    }
    return false;
}

int Application::PrintUsageStats()
{
    ZSwapDebug ZSwapDebugger;
    std::cout << fmt::format("Duplicate entries count: {0}.", ZSwapDebugger.GetDuplicateEntry()) << std::endl;
    std::cout << fmt::format("Pool limit hit: {0}.", ZSwapDebugger.GetPoolLimitHit()) << std::endl;
    std::cout << fmt::format("Pool total size: {0}.", ZSwapDebugger.GetPoolTotalSize()) << std::endl;
    std::cout << fmt::format("Reject allocation failures: {0}.", ZSwapDebugger.GetRejectAllocFail()) << std::endl;
    std::cout << fmt::format("Reject compression poor: {0}.", ZSwapDebugger.GetRejectCompressPoor()) << std::endl;
    std::cout << fmt::format("Reject Kmemcache failures: {0}.", ZSwapDebugger.GetRejectKmemCacheFail()) << std::endl;
    std::cout << fmt::format("Reject reclaim failures: {0}.", ZSwapDebugger.GetRejectReclaimFail()) << std::endl;
    std::cout << fmt::format("Same filled pages count: {0}.", ZSwapDebugger.GetSameFilledPages()) << std::endl;
    std::cout << fmt::format("Stored pages count: {0}.", ZSwapDebugger.GetStoredPages()) << std::endl;
    std::cout << fmt::format("Written back pages count: {0}.", ZSwapDebugger.GetWrittenBackPages()) << std::endl;
    return 0;
}

int Application::PrintSettings()
{
    std::cout << fmt::format("ZSwap enabled: {0}.", ZSwap.GetZSwapEnabled()) << std::endl;
    std::cout << fmt::format("Same filled pages enabled: {0}.", ZSwap.GetZSwapSameFilledPages()) << std::endl;
    std::cout << fmt::format("Maximum pool percentage: {0}.", ZSwap.GetZSwapMaxPoolPercent()) << std::endl;
    std::cout << fmt::format("Comression algorithm: {0}.", ZSwap.GetZSwapCompressor()) << std::endl;
    std::cout << fmt::format("Kernel's zpool type: {0}.", ZSwap.GetZSwapZpool()) << std::endl;
    std::cout << fmt::format("Accept threhsold percentage: {0}.", ZSwap.GetZSwapAcceptThrehsoldPercent()) << std::endl;
    return 0;
}

void Application::ExecuteEnv()
{
    const std::string ZSwapEnabledEnv = CWrappers::GetEnv("ZSWAP_ENABLED_VALUE");
    const std::string ZSwapSameFilledPagesEnv = CWrappers::GetEnv("ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE");
    const std::string ZSwapMaxPoolPercentEnv = CWrappers::GetEnv("ZSWAP_MAX_POOL_PERCENT_VALUE");
    const std::string ZSwapCompressorEnv = CWrappers::GetEnv("ZSWAP_COMPRESSOR_VALUE");
    const std::string ZSwapZpoolEnv = CWrappers::GetEnv("ZSWAP_ZPOOL_VALUE");
    const std::string ZSwapAcceptThrehsoldPercentEnv = CWrappers::GetEnv("ZSWAP_ACCEPT_THREHSOLD_PERCENT_VALUE");

    if (!ZSwapEnabledEnv.empty()) ZSwap.SetZSwapEnabled(ZSwapEnabledEnv);
    if (!ZSwapSameFilledPagesEnv.empty()) ZSwap.SetZSwapSameFilledPages(ZSwapSameFilledPagesEnv);
    if (!ZSwapMaxPoolPercentEnv.empty()) ZSwap.SetZSwapMaxPoolPercent(ZSwapMaxPoolPercentEnv);
    if (!ZSwapCompressorEnv.empty()) ZSwap.SetZSwapCompressor(ZSwapCompressorEnv);
    if (!ZSwapZpoolEnv.empty()) ZSwap.SetZSwapZpool(ZSwapZpoolEnv);
    if (!ZSwapAcceptThrehsoldPercentEnv.empty()) ZSwap.SetZSwapAcceptThrehsoldPercent(ZSwapAcceptThrehsoldPercentEnv);
}

void Application::ExecuteCmdLine(const cxxopts::ParseResult& CmdLine)
{
    if (CmdLine.count("enabled")) ZSwap.SetZSwapEnabled(CmdLine["enabled"].as<std::string>());
    if (CmdLine.count("same_filled_pages_enabled")) ZSwap.SetZSwapSameFilledPages(CmdLine["same_filled_pages_enabled"].as<std::string>());
    if (CmdLine.count("max_pool_percent")) ZSwap.SetZSwapMaxPoolPercent(CmdLine["max_pool_percent"].as<std::string>());
    if (CmdLine.count("compressor")) ZSwap.SetZSwapCompressor(CmdLine["compressor"].as<std::string>());
    if (CmdLine.count("zpool")) ZSwap.SetZSwapZpool(CmdLine["zpool"].as<std::string>());
    if (CmdLine.count("accept_threhsold_percent")) ZSwap.SetZSwapAcceptThrehsoldPercent(CmdLine["accept_threhsold_percent"].as<std::string>());
}

int Application::Run(const cxxopts::ParseResult& CmdLine)
{
    if (CheckIfRunningBySuperUser()) return 1;
    if (CmdLine.count("stats")) return PrintUsageStats();
    if (CmdLine.count("settings")) return PrintSettings();
    if (CmdLine.count("env")) ExecuteEnv(); else ExecuteCmdLine(CmdLine);
    return 0;
}
