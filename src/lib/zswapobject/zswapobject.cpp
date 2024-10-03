/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <format>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

#include "zswapobject/zswapobject.hpp"

bool ZSwapObject::CheckPercent(const std::string& Value)
{
    if (Value.empty()) return true;
    const int ValueInt = std::stoi(Value);
    return (ValueInt < 0) || (ValueInt > 100);
}

bool ZSwapObject::CheckEnabled(const std::string& Value)
{
    return !std::regex_match(Value, std::regex("^[YN]$"));
}

void ZSwapObject::WriteLogEntry(const std::string& Name, const std::string& Value)
{
    std::cout << std::vformat(ZSwapMessageLog, std::make_format_args(Name, Value)) << std::endl;
}

void ZSwapObject::WriteZSwapValue(const std::string& Name, const std::string& Value)
{
    const std::string FullPath = ZSwapModuleParametersPath + Name;
    if (!std::filesystem::exists(FullPath)) throw std::runtime_error(std::vformat(ZSwapErrorKernel, std::make_format_args(Name)));
    std::ofstream ZSwapSysFs(FullPath);
    ZSwapSysFs << Value;
    ZSwapSysFs.close();
}

std::string ZSwapObject::ReadZSwapValue(const std::string& Name)
{
    const std::string FullPath = ZSwapModuleParametersPath + Name;
    if (!std::filesystem::exists(FullPath)) return "N/A";
    std::string Result;
    std::ifstream ZSwapSysFs(FullPath);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}

std::string ZSwapObject::GetZSwapEnabled()
{
    return ReadZSwapValue(ZSwapEnabledName);
}

void ZSwapObject::SetZSwapEnabled(const std::string& Value)
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapEnabledName)));
    WriteLogEntry(ZSwapEnabledName, Value);
    WriteZSwapValue(ZSwapEnabledName, Value);
}

std::string ZSwapObject::GetZSwapSameFilledPages()
{
    return ReadZSwapValue(ZSwapSameFilledPagesName);
}

void ZSwapObject::SetZSwapSameFilledPages(const std::string& Value)
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapSameFilledPagesName)));
    WriteLogEntry(ZSwapSameFilledPagesName, Value);
    WriteZSwapValue(ZSwapSameFilledPagesName, Value);
}

std::string ZSwapObject::GetZSwapMaxPoolPercent()
{
    return ReadZSwapValue(ZSwapMaxPoolPercentName);
}

void ZSwapObject::SetZSwapMaxPoolPercent(const std::string& Value)
{
    if (CheckPercent(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorRange, std::make_format_args(ZSwapMaxPoolPercentName)));
    WriteLogEntry(ZSwapMaxPoolPercentName, Value);
    WriteZSwapValue(ZSwapMaxPoolPercentName, Value);
}

std::string ZSwapObject::GetZSwapCompressor()
{
    return ReadZSwapValue(ZSwapCompressorName);
}

void ZSwapObject::SetZSwapCompressor(const std::string& Value)
{
    if (Value.empty()) throw std::invalid_argument(std::vformat(ZSwapErrorEmpty, std::make_format_args(ZSwapCompressorName)));
    WriteLogEntry(ZSwapCompressorName, Value);
    WriteZSwapValue(ZSwapCompressorName, Value);
}

std::string ZSwapObject::GetZSwapZpool()
{
    return ReadZSwapValue(ZSwapZpoolName);
}

void ZSwapObject::SetZSwapZpool(const std::string& Value)
{
    if (Value.empty()) throw std::invalid_argument(std::vformat(ZSwapErrorEmpty, std::make_format_args(ZSwapZpoolName)));
    WriteLogEntry(ZSwapZpoolName, Value);
    WriteZSwapValue(ZSwapZpoolName, Value);
}

std::string ZSwapObject::GetZSwapAcceptThresholdPercent()
{
    return ReadZSwapValue(ZSwapAcceptThresholdPercentName);
}

void ZSwapObject::SetZSwapAcceptThresholdPercent(const std::string& Value)
{
    if (CheckPercent(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorRange, std::make_format_args(ZSwapAcceptThresholdPercentName)));
    WriteLogEntry(ZSwapAcceptThresholdPercentName, Value);
    WriteZSwapValue(ZSwapAcceptThresholdPercentName, Value);
}

std::string ZSwapObject::GetZSwapNonSameFilledPages()
{
    return ReadZSwapValue(ZSwapNonSameFilledPagesName);
}

void ZSwapObject::SetZSwapNonSameFilledPages(const std::string& Value)
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapNonSameFilledPagesName)));
    WriteLogEntry(ZSwapNonSameFilledPagesName, Value);
    WriteZSwapValue(ZSwapNonSameFilledPagesName, Value);
}

std::string ZSwapObject::GetZSwapExclusiveLoads()
{
    return ReadZSwapValue(ZSwapExclusiveLoadsName);
}

void ZSwapObject::SetZSwapExclusiveLoads(const std::string& Value)
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapExclusiveLoadsName)));
    WriteLogEntry(ZSwapExclusiveLoadsName, Value);
    WriteZSwapValue(ZSwapExclusiveLoadsName, Value);
}

std::string ZSwapObject::GetZSwapShrinkerEnabled()
{
    return ReadZSwapValue(ZSwapShrinkerEnabledName);
}

void ZSwapObject::SetZSwapShrinkerEnabled(const std::string& Value)
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapShrinkerEnabledName)));
    WriteLogEntry(ZSwapShrinkerEnabledName, Value);
    WriteZSwapValue(ZSwapShrinkerEnabledName, Value);
}

bool ZSwapObject::IsAvailable()
{
    return std::filesystem::exists(ZSwapModuleParametersPath);
}
