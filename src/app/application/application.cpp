/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>

#ifndef FILESYSTEM_LEGACY
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#include <boost/program_options.hpp>
#include <fmt/format.h>

#include "appconstants/appconstants.hpp"
#include "application/application.hpp"
#include "cwrappers/cwrappers.hpp"
#include "zswapobject/zswapobject.hpp"
#include "zswapdebug/zswapdebug.hpp"
#include "ksysinfo/ksysinfo.hpp"

void Application::PrintDebugInfo()
{
    std::unique_ptr<ZSwapDebug> ZSwapDebugger = std::make_unique<ZSwapDebug>();
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
                             ZSwapDebugger -> GetDuplicateEntry(),
                             ZSwapDebugger -> GetPoolLimitHit(),
                             ZSwapDebugger -> GetPoolTotalSize(),
                             ZSwapDebugger -> GetRejectAllocFail(),
                             ZSwapDebugger -> GetRejectCompressPoor(),
                             ZSwapDebugger -> GetRejectKmemCacheFail(),
                             ZSwapDebugger -> GetRejectReclaimFail(),
                             ZSwapDebugger -> GetSameFilledPages(),
                             ZSwapDebugger -> GetSameFilledPages(),
                             ZSwapDebugger -> GetStoredPages(),
                             ZSwapDebugger -> GetWrittenBackPages())
              << std::endl;
}

void Application::PrintSettings()
{
    std::cout << fmt::format("ZSwap enabled: {0}.\n"
                             "Same filled pages enabled: {1}.\n"
                             "Maximum pool percentage: {2}.\n"
                             "Compression algorithm: {3}.\n"
                             "Kernel's zpool type: {4}.\n"
                             "Accept threshold percentage: {5}.",
                             ZSwap -> GetZSwapEnabled(),
                             ZSwap -> GetZSwapSameFilledPages(),
                             ZSwap -> GetZSwapMaxPoolPercent(),
                             ZSwap -> GetZSwapCompressor(),
                             ZSwap -> GetZSwapZpool(),
                             ZSwap -> GetZSwapAcceptThresholdPercent())
              << std::endl;
}

void Application::PrintSummary()
{
    std::unique_ptr<ZSwapDebug> ZSwapDebugger = std::make_unique<ZSwapDebug>();
    std::unique_ptr<KSysInfo> SysInfo = std::make_unique<KSysInfo>();

    if (ZSwapDebugger -> GetPoolTotalSize() == 0)
    {
        std::cout << "ZSwap is not working. The pool is empty." << std::endl;
        return;
    }

    constexpr const long Power = 1024 << 10;
    const float PoolSizeMB = static_cast<float>(ZSwapDebugger -> GetPoolTotalSize()) / Power;
    const float MemTotalPercent = static_cast<float>(ZSwapDebugger -> GetPoolTotalSize()) / static_cast<float>(SysInfo -> GetTotalRam()) * 100.f;
    const float StoredPagesMB = static_cast<float>(ZSwapDebugger -> GetStoredPages() * CWrappers::GetSCPageSize()) / Power;
    const float SwapUsedPercent = static_cast<float>(ZSwapDebugger -> GetStoredPages() * CWrappers::GetSCPageSize()) / static_cast<float>(SysInfo -> GetTotalSwap() - SysInfo -> GetFreeSwap()) * 100.f;
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
            throw std::invalid_argument("Incorrect value of --stats command-line option was specified.");
    }
    return 0;
}

int Application::PrintHelp()
{
    CmdLineOptions -> print(std::cout);
    return 0;
}

int Application::PrintVersion()
{
    std::cout << fmt::format("{0} project version: {1}.",
                             AppConstants::ProductNameInternal,
                             AppConstants::ProductVersion)
              << std::endl;
    return 0;
}

int Application::ExecuteEnv()
{
    const std::string ZSwapEnabledEnv = CWrappers::GetEnv("ZSWAP_ENABLED_VALUE");
    const std::string ZSwapSameFilledPagesEnv = CWrappers::GetEnv("ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE");
    const std::string ZSwapMaxPoolPercentEnv = CWrappers::GetEnv("ZSWAP_MAX_POOL_PERCENT_VALUE");
    const std::string ZSwapCompressorEnv = CWrappers::GetEnv("ZSWAP_COMPRESSOR_VALUE");
    const std::string ZSwapZpoolEnv = CWrappers::GetEnv("ZSWAP_ZPOOL_VALUE");
    const std::string ZSwapAcceptThresholdPercentEnv = CWrappers::GetEnv("ZSWAP_ACCEPT_THRESHOLD_PERCENT_VALUE");

    if (!ZSwapEnabledEnv.empty()) ZSwap -> SetZSwapEnabled(ZSwapEnabledEnv);
    if (!ZSwapSameFilledPagesEnv.empty()) ZSwap -> SetZSwapSameFilledPages(ZSwapSameFilledPagesEnv);
    if (!ZSwapMaxPoolPercentEnv.empty()) ZSwap -> SetZSwapMaxPoolPercent(ZSwapMaxPoolPercentEnv);
    if (!ZSwapCompressorEnv.empty()) ZSwap -> SetZSwapCompressor(ZSwapCompressorEnv);
    if (!ZSwapZpoolEnv.empty()) ZSwap -> SetZSwapZpool(ZSwapZpoolEnv);
    if (!ZSwapAcceptThresholdPercentEnv.empty()) ZSwap -> SetZSwapAcceptThresholdPercent(ZSwapAcceptThresholdPercentEnv);
    return 0;
}

int Application::ExecuteConfig(const std::string& ConfigFile)
{
    std::unique_ptr<boost::program_options::variables_map> Config = std::make_unique<boost::program_options::variables_map>();
    std::unique_ptr<boost::program_options::options_description> ConfigOptions = std::make_unique<boost::program_options::options_description>("Configuration file options.");
    ConfigOptions -> add_options()
        ("zswap.enabled", boost::program_options::value<std::string>(), "Enable or disable ZSwap kernel module.")
        ("zswap.same_filled_pages_enabled", boost::program_options::value<std::string>(), "Enable or disable memory pages deduplication.")
        ("zswap.max_pool_percent", boost::program_options::value<std::string>(), "The maximum percentage of memory that the compressed pool can occupy.")
        ("zswap.compressor", boost::program_options::value<std::string>(), "The default compression algorithm.")
        ("zswap.zpool", boost::program_options::value<std::string>(), "The kernel's zpool type.")
        ("zswap.accept_threshold_percent", boost::program_options::value<std::string>(), "The threshold at which ZSwap would start accepting pages again after it became full.")
        ;

    if (!fs::exists(ConfigFile)) throw std::invalid_argument("Configuration file does not exist!");
    std::ifstream ConfigFileFs(ConfigFile);
    boost::program_options::store(boost::program_options::parse_config_file(ConfigFileFs, *ConfigOptions), *Config);
    Config -> notify();
    ConfigFileFs.close();

    if (Config -> count("zswap.enabled")) ZSwap -> SetZSwapEnabled(Config -> at("zswap.enabled").as<std::string>());
    if (Config -> count("zswap.same_filled_pages_enabled")) ZSwap -> SetZSwapSameFilledPages(Config -> at("zswap.same_filled_pages_enabled").as<std::string>());
    if (Config -> count("zswap.max_pool_percent")) ZSwap -> SetZSwapMaxPoolPercent(Config -> at("zswap.max_pool_percent").as<std::string>());
    if (Config -> count("zswap.compressor")) ZSwap -> SetZSwapCompressor(Config -> at("zswap.compressor").as<std::string>());
    if (Config -> count("zswap.zpool")) ZSwap -> SetZSwapZpool(Config -> at("zswap.zpool").as<std::string>());
    if (Config -> count("zswap.accept_threshold_percent")) ZSwap -> SetZSwapAcceptThresholdPercent(Config -> at("zswap.accept_threshold_percent").as<std::string>());
    return 0;
}

int Application::ExecuteCmdLine()
{
    if (CmdLine -> count("enabled")) ZSwap -> SetZSwapEnabled(CmdLine -> at("enabled").as<std::string>());
    if (CmdLine -> count("same_filled_pages_enabled")) ZSwap -> SetZSwapSameFilledPages(CmdLine -> at("same_filled_pages_enabled").as<std::string>());
    if (CmdLine -> count("max_pool_percent")) ZSwap -> SetZSwapMaxPoolPercent(CmdLine -> at("max_pool_percent").as<std::string>());
    if (CmdLine -> count("compressor")) ZSwap -> SetZSwapCompressor(CmdLine -> at("compressor").as<std::string>());
    if (CmdLine -> count("zpool")) ZSwap -> SetZSwapZpool(CmdLine -> at("zpool").as<std::string>());
    if (CmdLine -> count("accept_threshold_percent")) ZSwap -> SetZSwapAcceptThresholdPercent(CmdLine -> at("accept_threshold_percent").as<std::string>());
    return 0;
}

int Application::Run()
{
    if (CmdLine -> empty() || CmdLine -> count("help")) return PrintHelp();
    if (CmdLine -> count("version")) return PrintVersion();
    if (CmdLine -> count("stats")) return PrintStats(CmdLine -> at("stats").as<int>());
    if (CmdLine -> count("config")) return ExecuteConfig(CmdLine -> at("config").as<std::string>());
    if (CmdLine -> count("env")) return ExecuteEnv();
    return ExecuteCmdLine();
}

void Application::CheckIfRunningBySuperUser()
{
    if (CWrappers::CheckRoot())
    {
        throw std::runtime_error("This program must be run by the super-user. Terminating.");
    }
}

void Application::InitClassMembers()
{
    CmdLineOptions = std::make_unique<boost::program_options::options_description>("Command-line tool to control ZSwap Linux kernel module");
    CmdLine = std::make_unique<boost::program_options::variables_map>();
    ZSwap = std::make_unique<ZSwapObject>();
}

void Application::InitCmdLineOptions()
{
    boost::program_options::options_description OptionsGeneral("General options");
    OptionsGeneral.add_options()
        ("help,h", "Print this help message and exit.")
        ("version,v", "Print version information and exit.")
        ;

    boost::program_options::options_description OptionsConfiguration("Application configuration options");
    OptionsConfiguration.add_options()
        ("config", boost::program_options::value<std::string>(), "Get options from the configuration file instead of the cmdline.")
        ("env", "Get options from the environment variables instead of the cmdline.")
        ("stats", boost::program_options::value<int>() -> implicit_value(0), "Get statistics and current settings of ZSwap kernel module.")
        ;

    boost::program_options::options_description OptionsZSwap("Kernel module configuration options");
    OptionsZSwap.add_options()
        ("enabled,e", boost::program_options::value<std::string>(), "Enable or disable ZSwap kernel module.")
        ("same_filled_pages_enabled,s", boost::program_options::value<std::string>(), "Enable or disable memory pages deduplication.")
        ("max_pool_percent,p", boost::program_options::value<std::string>(), "The maximum percentage of memory that the compressed pool can occupy.")
        ("compressor,c", boost::program_options::value<std::string>(), "The default compression algorithm.")
        ("zpool,z", boost::program_options::value<std::string>(), "The kernel's zpool type.")
        ("accept_threshold_percent,a", boost::program_options::value<std::string>(), "The threshold at which ZSwap would start accepting pages again after it became full.")
        ;

    CmdLineOptions -> add(OptionsGeneral).add(OptionsConfiguration).add(OptionsZSwap);
}

void Application::ParseCmdLine(int argc, char** argv)
{
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, *CmdLineOptions), *CmdLine);
    CmdLine -> notify();
}

Application::Application(int argc, char** argv)
{
    CheckIfRunningBySuperUser();
    InitClassMembers();
    InitCmdLineOptions();
    ParseCmdLine(argc, argv);
}
