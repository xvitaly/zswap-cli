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

void Application::PrintDebugInfo()
{
    ZSwapDebug ZSwapDebugger;
    std::cout << fmt::format("Duplicate entries count: {0}.\n"
                             "Pool limit hit: {1}.\n"
                             "Pool total size: {2}.\n"
                             "Reject allocation failures: {3}.\n"
                             "Reject compression poor: {4}.\n"
                             "Reject Kmemcache failures: {5}.\n"
                             "Reject reclaim failures: {6}.\n"
                             "Same filled pages count: {7}.\n"
                             "Stored pages count: {8}.\n"
                             "Written back pages count: {9}.",
                             ZSwapDebugger.GetDuplicateEntry(),
                             ZSwapDebugger.GetPoolLimitHit(),
                             ZSwapDebugger.GetPoolTotalSize(),
                             ZSwapDebugger.GetRejectAllocFail(),
                             ZSwapDebugger.GetRejectCompressPoor(),
                             ZSwapDebugger.GetRejectKmemCacheFail(),
                             ZSwapDebugger.GetRejectReclaimFail(),
                             ZSwapDebugger.GetSameFilledPages(),
                             ZSwapDebugger.GetSameFilledPages(),
                             ZSwapDebugger.GetStoredPages(),
                             ZSwapDebugger.GetWrittenBackPages())
              << std::endl;
}

void Application::PrintSettings()
{
    std::cout << fmt::format("ZSwap enabled: {0}.\n"
                             "Same filled pages enabled: {1}.\n"
                             "Maximum pool percentage: {2}.\n"
                             "Compression algorithm: {3}.\n"
                             "Kernel's zpool type: {4}.\n"
                             "Accept threhsold percentage: {5}.",
                             ZSwap.GetZSwapEnabled(),
                             ZSwap.GetZSwapSameFilledPages(),
                             ZSwap.GetZSwapMaxPoolPercent(),
                             ZSwap.GetZSwapCompressor(),
                             ZSwap.GetZSwapZpool(),
                             ZSwap.GetZSwapAcceptThrehsoldPercent())
              << std::endl;
}

void Application::PrintSummary()
{
    ZSwapDebug ZSwapDebugger;
    KSysInfo SysInfo;

    if (ZSwapDebugger.GetPoolTotalSize() == 0)
    {
        std::cout << "ZSwap is not working. The pool is empty." << std::endl;
        return;
    }

    constexpr const long Power = 1024 << 10;
    const float PoolSizeMB = static_cast<float>(ZSwapDebugger.GetPoolTotalSize()) / Power;
    const float MemTotalPercent = static_cast<float>(ZSwapDebugger.GetPoolTotalSize()) / static_cast<float>(SysInfo.GetTotalRam()) * 100.f;
    const float StoredPagesMB = static_cast<float>(ZSwapDebugger.GetStoredPages() * CWrappers::GetSCPageSize()) / Power;
    const float SwapUsedPercent = static_cast<float>(ZSwapDebugger.GetStoredPages() * CWrappers::GetSCPageSize()) / static_cast<float>(SysInfo.GetTotalSwap() - SysInfo.GetFreeSwap()) * 100.f;
    const float CompressionRatio = StoredPagesMB / PoolSizeMB;

    std::cout << fmt::format("Pool: {0:.2f} MiB ({1:.1f}% of MemTotal).\n"
                             "Stored: {2:.2f} MiB ({3:.1f}% of SwapUsed).\n"
                             "Compression ratio: {4:.2f}.",
                             PoolSizeMB,
                             MemTotalPercent,
                             StoredPagesMB,
                             SwapUsedPercent,
                             CompressionRatio)
              << std::endl;
}

void Application::PrintCombined()
{
    std::cout << "ZSWAP KERNEL MODULE SETTINGS:" << std::endl;
    PrintSettings();
    std::cout << std::endl;
    std::cout << "ZSWAP KERNEL MODULE USAGE SUMMARY:" << std::endl;
    PrintSummary();
    std::cout << std::endl;
    std::cout << "ZSWAP KERNEL MODULE DEBUG INFO:" << std::endl;
    PrintDebugInfo();
}

int Application::PrintStats(const int Value)
{
    switch (Value)
    {
        case 0:
            PrintCombined();
            break;
        case 1:
            PrintSettings();
            break;
        case 2:
            PrintSummary();
            break;
        case 3:
            PrintDebugInfo();
            break;
        default:
            std::cout << "Incorrect value of --stats command-line option was specified." << std::endl;
    }
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

void Application::ExecuteCmdLine(const boost::program_options::variables_map& CmdLine)
{
    if (CmdLine.count("enabled")) ZSwap.SetZSwapEnabled(CmdLine["enabled"].as<std::string>());
    if (CmdLine.count("same_filled_pages_enabled")) ZSwap.SetZSwapSameFilledPages(CmdLine["same_filled_pages_enabled"].as<std::string>());
    if (CmdLine.count("max_pool_percent")) ZSwap.SetZSwapMaxPoolPercent(CmdLine["max_pool_percent"].as<std::string>());
    if (CmdLine.count("compressor")) ZSwap.SetZSwapCompressor(CmdLine["compressor"].as<std::string>());
    if (CmdLine.count("zpool")) ZSwap.SetZSwapZpool(CmdLine["zpool"].as<std::string>());
    if (CmdLine.count("accept_threhsold_percent")) ZSwap.SetZSwapAcceptThrehsoldPercent(CmdLine["accept_threhsold_percent"].as<std::string>());
}

int Application::Run(const boost::program_options::variables_map& CmdLine)
{
    if (CheckIfRunningBySuperUser()) return 1;
    if (CmdLine.count("stats")) return PrintStats(CmdLine["stats"].as<int>());
    if (CmdLine.count("env")) ExecuteEnv(); else ExecuteCmdLine(CmdLine);
    return 0;
}
