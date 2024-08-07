/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <algorithm>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

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
    if (!fs::exists(ZSwapDebug::GetModulePath()))
    {
        std::cout << "ZSwap is not running or access to debug is denied." << std::endl;
        return;
    }

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
                             "Accept threshold percentage: {5}.\n"
                             "Non same filled pages enabled: {6}.\n"
                             "Exclusive loads: {7}.\n"
                             "Shrinker enabled: {8}.",
                             ZSwap -> GetZSwapEnabled(),
                             ZSwap -> GetZSwapSameFilledPages(),
                             ZSwap -> GetZSwapMaxPoolPercent(),
                             ZSwap -> GetZSwapCompressor(),
                             ZSwap -> GetZSwapZpool(),
                             ZSwap -> GetZSwapAcceptThresholdPercent(),
                             ZSwap -> GetZSwapNonSameFilledPages(),
                             ZSwap -> GetZSwapExclusiveLoads(),
                             ZSwap -> GetZSwapShrinkerEnabled())
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
    bool Result = true;
    const std::vector<std::pair<std::string, std::function<void(const std::string&)>>> Handlers
    {
        { "ZSWAP_ENABLED_VALUE", [this] (const std::string& Value) { ZSwap -> SetZSwapEnabled(Value); } },
        { "ZSWAP_SAME_FILLED_PAGES_ENABLED_VALUE", [this] (const std::string& Value) { ZSwap -> SetZSwapSameFilledPages(Value); } },
        { "ZSWAP_MAX_POOL_PERCENT_VALUE", [this] (const std::string& Value) { ZSwap -> SetZSwapMaxPoolPercent(Value); } },
        { "ZSWAP_COMPRESSOR_VALUE", [this] (const std::string& Value) { ZSwap -> SetZSwapCompressor(Value); } },
        { "ZSWAP_ZPOOL_VALUE", [this] (const std::string& Value) { ZSwap -> SetZSwapZpool(Value); } },
        { "ZSWAP_ACCEPT_THRESHOLD_PERCENT_VALUE", [this] (const std::string& Value) { ZSwap -> SetZSwapAcceptThresholdPercent(Value); } },
        { "ZSWAP_NON_SAME_FILLED_PAGES_ENABLED_VALUE", [this] (const std::string& Value) { ZSwap -> SetZSwapNonSameFilledPages(Value); } },
        { "ZSWAP_EXCLUSIVE_LOADS_VALUE", [this] (const std::string& Value) { ZSwap -> SetZSwapExclusiveLoads(Value); } },
        { "ZSWAP_SHRINKER_ENABLED_VALUE", [this] (const std::string& Value) { ZSwap -> SetZSwapShrinkerEnabled(Value); } },
    };

    for (const auto& [Key, Handler] : Handlers)
    {
        try
        {
            const std::string EnvValue = CWrappers::GetEnv(Key);
            if (!EnvValue.empty()) Handler(EnvValue);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            Result &= false;
        }
    }

    return !Result;
}

int Application::ExecuteConfig(const std::string& ConfigFile)
{
    std::unique_ptr<boost::program_options::variables_map> Config = std::make_unique<boost::program_options::variables_map>();
    std::unique_ptr<boost::program_options::options_description> ConfigOptions = std::make_unique<boost::program_options::options_description>("Configuration file options.");
    ConfigOptions -> add_options()
        ("zswap.enabled", boost::program_options::value<std::string>(), "Enable or disable the ZSwap kernel module.")
        ("zswap.same_filled_pages_enabled", boost::program_options::value<std::string>(), "Enable or disable memory pages deduplication.")
        ("zswap.max_pool_percent", boost::program_options::value<std::string>(), "The maximum percentage of memory that the compressed pool can occupy.")
        ("zswap.compressor", boost::program_options::value<std::string>(), "The algorithm used to compress memory pages.")
        ("zswap.zpool", boost::program_options::value<std::string>(), "The kernel's zpool type.")
        ("zswap.accept_threshold_percent", boost::program_options::value<std::string>(), "The threshold at which ZSwap would start accepting pages again after it became full.")
        ("zswap.non_same_filled_pages_enabled", boost::program_options::value<std::string>(), "Enable or disable accepting non same filled memory pages.")
        ("zswap.exclusive_loads", boost::program_options::value<std::string>(), "Enable or disable entries invalidation when memory pages are loaded from compressed pool.")
        ("zswap.shrinker_enabled", boost::program_options::value<std::string>(), "Enable or disable pool shrinking based on memory pressure.")
        ;

    if (!fs::exists(ConfigFile)) throw std::invalid_argument("Configuration file does not exist!");
    std::ifstream ConfigFileFs(ConfigFile);
    boost::program_options::store(boost::program_options::parse_config_file(ConfigFileFs, *ConfigOptions), *Config);
    Config -> notify();
    ConfigFileFs.close();

    bool Result = true;
    const std::vector<std::pair<std::string, std::function<void(const std::string&)>>> Handlers
    {
        { "zswap.enabled", [this] (const std::string& Value) { ZSwap -> SetZSwapEnabled(Value); } },
        { "zswap.same_filled_pages_enabled", [this] (const std::string& Value) { ZSwap -> SetZSwapSameFilledPages(Value); } },
        { "zswap.max_pool_percent", [this] (const std::string& Value) { ZSwap -> SetZSwapMaxPoolPercent(Value); } },
        { "zswap.compressor", [this] (const std::string& Value) { ZSwap -> SetZSwapCompressor(Value); } },
        { "zswap.zpool", [this] (const std::string& Value) { ZSwap -> SetZSwapZpool(Value); } },
        { "zswap.accept_threshold_percent", [this] (const std::string& Value) { ZSwap -> SetZSwapAcceptThresholdPercent(Value); } },
        { "zswap.non_same_filled_pages_enabled", [this] (const std::string& Value) { ZSwap -> SetZSwapNonSameFilledPages(Value); } },
        { "zswap.exclusive_loads", [this] (const std::string& Value) { ZSwap -> SetZSwapExclusiveLoads(Value); } },
        { "zswap.shrinker_enabled", [this] (const std::string& Value) { ZSwap -> SetZSwapShrinkerEnabled(Value); } },
    };

    for (const auto& [Key, Handler] : Handlers)
    {
        try
        {
            if (Config -> count(Key)) Handler(CmdLine -> at(Key).as<std::string>());
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            Result &= false;
        }
    }

    return !Result;
}

int Application::ExecuteCmdLine()
{
    bool Result = true;
    const std::vector<std::pair<std::string, std::function<void(const std::string&)>>> Handlers
    {
        { "enabled", [this] (const std::string& Value) { ZSwap -> SetZSwapEnabled(Value); } },
        { "same_filled_pages_enabled", [this] (const std::string& Value) { ZSwap -> SetZSwapSameFilledPages(Value); } },
        { "max_pool_percent", [this] (const std::string& Value) { ZSwap -> SetZSwapMaxPoolPercent(Value); } },
        { "compressor", [this] (const std::string& Value) { ZSwap -> SetZSwapCompressor(Value); } },
        { "zpool", [this] (const std::string& Value) { ZSwap -> SetZSwapZpool(Value); } },
        { "accept_threshold_percent", [this] (const std::string& Value) { ZSwap -> SetZSwapAcceptThresholdPercent(Value); } },
        { "non_same_filled_pages_enabled", [this] (const std::string& Value) { ZSwap -> SetZSwapNonSameFilledPages(Value); } },
        { "exclusive_loads", [this] (const std::string& Value) { ZSwap -> SetZSwapExclusiveLoads(Value); } },
        { "shrinker_enabled", [this] (const std::string& Value) { ZSwap -> SetZSwapShrinkerEnabled(Value); } },
    };

    for (const auto& [Key, Handler] : Handlers)
    {
        try
        {
            if (CmdLine -> count(Key)) Handler(CmdLine -> at(Key).as<std::string>());
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            Result &= false;
        }
    }

    return !Result;
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
    CmdLineOptions = std::make_unique<boost::program_options::options_description>("Command-line tool to control the ZSwap kernel module");
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
        ("enabled,e", boost::program_options::value<std::string>(), "Enable or disable the ZSwap kernel module.")
        ("same_filled_pages_enabled,s", boost::program_options::value<std::string>(), "Enable or disable memory pages deduplication.")
        ("max_pool_percent,p", boost::program_options::value<std::string>(), "The maximum percentage of memory that the compressed pool can occupy.")
        ("compressor,c", boost::program_options::value<std::string>(), "The algorithm used to compress memory pages.")
        ("zpool,z", boost::program_options::value<std::string>(), "The kernel's zpool type.")
        ("accept_threshold_percent,a", boost::program_options::value<std::string>(), "The threshold at which ZSwap would start accepting pages again after it became full.")
        ("non_same_filled_pages_enabled,n", boost::program_options::value<std::string>(), "Enable or disable accepting non same filled memory pages.")
        ("exclusive_loads,x", boost::program_options::value<std::string>(), "Enable or disable entries invalidation when memory pages are loaded from compressed pool.")
        ("shrinker_enabled,r", boost::program_options::value<std::string>(), "Enable or disable pool shrinking based on memory pressure.")
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
