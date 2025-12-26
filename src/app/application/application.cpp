/**
 * SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/**
 * @file application/application.cpp
 * Contains the Application class implementation.
*/

#include <algorithm>
#include <exception>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include <boost/program_options.hpp>

#include "appconstants/appconstants.hpp"
#include "application/application.hpp"
#include "cwrappers/cwrappers.hpp"
#include "zswapobject/zswapobject.hpp"
#include "zswapdebug/zswapdebug.hpp"
#include "ksysinfo/ksysinfo.hpp"
#include "ksysversion/ksysversion.hpp"

void Application::PrintDebugInfo() const
{
    if (!ZSwapDebugger -> IsDebugAvailable())
    {
        std::cout << "ZSwap is not running or access to debugfs is denied." << std::endl;
        return;
    }

    const std::vector<std::pair<std::string_view, std::optional<unsigned long>>> Handlers
    {
        { "Pool limit hit", ZSwapDebugger -> GetPoolLimitHit() },
        { "Pool total size", ZSwapDebugger -> GetPoolTotalSize() },
        { "Reject allocation failures", ZSwapDebugger -> GetRejectAllocFail() },
        { "Reject compression poor", ZSwapDebugger -> GetRejectCompressPoor() },
        { "Reject Kmemcache failures", ZSwapDebugger -> GetRejectKmemCacheFail() },
        { "Reject reclaim failures", ZSwapDebugger -> GetRejectReclaimFail() },
        { "Reject compression failures", ZSwapDebugger -> GetRejectCompressFail() },
        { "Decompression failures", ZSwapDebugger -> GetDecompressFail() },
        { "Same filled pages count", ZSwapDebugger -> GetSameFilledPages() },
        { "Stored pages count", ZSwapDebugger -> GetStoredPages() },
        { "Written back pages count", ZSwapDebugger -> GetWrittenBackPages() },
        { "Incompressible pages count", ZSwapDebugger -> GetIncompressiblePages() },
    };

    for (const auto& [Name, Value] : Handlers)
    {
        if (Value) std::cout << std::format("{0}: {1}.", Name, Value.value()) << std::endl;
    }
}

void Application::PrintSettings() const
{
    if (!ZSwap -> IsAvailable())
    {
        std::cout << "ZSwap kernel module is not loaded." << std::endl;
        return;
    }

    const std::vector<std::pair<std::string_view, std::optional<std::string>>> Handlers
    {
        { "ZSwap enabled", ZSwap -> GetZSwapEnabled() },
        { "Same filled pages enabled", ZSwap -> GetZSwapSameFilledPages() },
        { "Maximum pool percentage", ZSwap -> GetZSwapMaxPoolPercent() },
        { "Compression algorithm", ZSwap -> GetZSwapCompressor() },
        { "Kernel's zpool type", ZSwap -> GetZSwapZpool() },
        { "Accept threshold percentage", ZSwap -> GetZSwapAcceptThresholdPercent() },
        { "Non same filled pages enabled", ZSwap -> GetZSwapNonSameFilledPages() },
        { "Exclusive loads", ZSwap -> GetZSwapExclusiveLoads() },
        { "Shrinker enabled", ZSwap -> GetZSwapShrinkerEnabled() },
    };

    for (const auto& [Name, Value] : Handlers)
    {
        if (Value) std::cout << std::format("{0}: {1}.", Name, Value.value()) << std::endl;
    }
}

void Application::PrintSummary() const
{
    if (!ZSwapDebugger -> IsDebugAvailable())
    {
        std::cout << "ZSwap is not running or access to debugfs is denied." << std::endl;
        return;
    }

    std::unique_ptr<KSysInfo> SysInfo = std::make_unique<KSysInfo>();
    const unsigned long PoolSize = ZSwapDebugger -> GetPoolTotalSize().value_or(0UL);
    const unsigned long StoredPages = ZSwapDebugger -> GetStoredPages().value_or(0UL);

    if (!SysInfo -> IsSwapAvailable())
    {
        std::cout << "ZSwap is not functional due to missing swap file or partition." << std::endl;
        return;
    }

    if (PoolSize == 0)
    {
        std::cout << "ZSwap is not working. The pool is empty." << std::endl;
        return;
    }

    const float StoredSize = static_cast<float>(StoredPages) * static_cast<float>(SysInfo -> GetPageSize());
    const float PoolSizeMB = static_cast<float>(PoolSize) / 1048576.f;
    const float MemTotalPercent = static_cast<float>(PoolSize) / SysInfo -> GetTotalRamF() * 100.f;
    const float StoredSizeMB = StoredSize / 1048576.f;
    const float SwapUsedPercent = StoredSize / (SysInfo -> GetTotalSwapF() - SysInfo -> GetFreeSwapF()) * 100.f;
    const float CompressionRatio = StoredSizeMB / PoolSizeMB;

    std::cout << std::format("Pool: {0:.2f} MiB ({1:.1f}% of MemTotal).\n"
                             "Stored: {2:.2f} MiB ({3:.1f}% of SwapUsed).\n"
                             "Compression ratio: {4:.2f}.",
                             PoolSizeMB,
                             MemTotalPercent,
                             StoredSizeMB,
                             SwapUsedPercent,
                             CompressionRatio)
              << std::endl;
}

void Application::PrintCombined() const
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

int Application::PrintStats(const int Value) const
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
            throw std::invalid_argument("Incorrect value of the --stats command-line option was specified.");
    }
    return 0;
}

int Application::PrintHelp() const
{
    CmdLineOptions -> print(std::cout);
    return 0;
}

int Application::PrintVersion() const
{
    std::unique_ptr<KSysVersion> SysVersion = std::make_unique<KSysVersion>();
    std::cout << std::format("{0} version: {1}\n"
                             "Kernel API version:\n"
                             "  build: {2}\n"
                             "  runtime: {3}",
                             AppConstants::ProductNameInternal,
                             AppConstants::ProductVersion,
                             SysVersion -> GetHeadersVersion(),
                             SysVersion -> GetKernelVersion())
              << std::endl;
    return 0;
}

int Application::ExecuteEnv() const
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

int Application::ExecuteConfig(const std::string& ConfigFile) const
{
    ParseConfigFile(ConfigFile);

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
            if (Config -> count(Key)) Handler(Config -> at(Key).as<std::string>());
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            Result &= false;
        }
    }

    return !Result;
}

int Application::ExecuteCmdLine() const
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

int Application::Run() const
{
    if (CmdLine -> empty() || CmdLine -> count("help")) return PrintHelp();
    if (CmdLine -> count("version")) return PrintVersion();
    if (CmdLine -> count("stats")) return PrintStats(CmdLine -> at("stats").as<int>());
    if (CmdLine -> count("config")) return ExecuteConfig(CmdLine -> at("config").as<std::string>());
    if (CmdLine -> count("env")) return ExecuteEnv();
    return ExecuteCmdLine();
}

void Application::CheckIfRunningBySuperUser() const
{
    if (CWrappers::CheckRoot())
    {
        throw std::runtime_error("This program must be run by the super-user. Terminating.");
    }
}

void Application::InitClassMembers()
{
    CmdLineOptions = std::make_unique<boost::program_options::options_description>("Command-line tool to control the ZSwap kernel module options");
    ConfigOptions = std::make_unique<boost::program_options::options_description>("Configuration file options");
    CmdLine = std::make_unique<boost::program_options::variables_map>();
    Config = std::make_unique<boost::program_options::variables_map>();
    ZSwap = std::make_unique<ZSwapObject>();
    ZSwapDebugger = std::make_unique<ZSwapDebug>();
}

void Application::InitCmdLineOptions() const
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

void Application::InitConfigOptions() const
{
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
}

void Application::ParseCmdLine(int argc, char** argv) const
{
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, *CmdLineOptions), *CmdLine);
    CmdLine -> notify();
}

void Application::ParseConfigFile(const std::string& ConfigFile) const
{
    if (!std::filesystem::exists(ConfigFile)) throw std::invalid_argument("The specified configuration file does not exist!");
    std::ifstream ConfigFileFs(ConfigFile);
    boost::program_options::store(boost::program_options::parse_config_file(ConfigFileFs, *ConfigOptions), *Config);
    Config -> notify();
}

Application::Application(int argc, char** argv)
{
    CheckIfRunningBySuperUser();
    InitClassMembers();
    InitCmdLineOptions();
    InitConfigOptions();
    ParseCmdLine(argc, argv);
}
