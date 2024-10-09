/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/** @file zswapobject/zswapobject.cpp
 *  Contains the ZSwapObject class implementation.
 */

#include <format>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

#include "zswapobject/zswapobject.hpp"

bool ZSwapObject::CheckPercent(const std::string& Value) const
{
    return !std::regex_match(Value, std::regex("^\\d{1,2}|100$"));
}

bool ZSwapObject::CheckEnabled(const std::string& Value) const
{
    return !std::regex_match(Value, std::regex("^[YN]$"));
}

void ZSwapObject::WriteLogEntry(const std::string& Name, const std::string& Value) const
{
    std::cout << std::vformat(ZSwapMessageLog, std::make_format_args(Name, Value)) << std::endl;
}

void ZSwapObject::WriteZSwapValue(const std::string& Name, const std::string& Value) const
{
    const std::string FullPath = ZSwapModuleParametersPath + Name;
    if (!std::filesystem::exists(FullPath)) throw std::runtime_error(std::vformat(ZSwapErrorKernel, std::make_format_args(Name)));
    std::ofstream ZSwapSysFs(FullPath);
    ZSwapSysFs << Value;
    ZSwapSysFs.close();
}

std::string ZSwapObject::ReadZSwapValue(const std::string& Name) const
{
    const std::string FullPath = ZSwapModuleParametersPath + Name;
    if (!std::filesystem::exists(FullPath)) return "N/A";
    std::string Result;
    std::ifstream ZSwapSysFs(FullPath);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}

std::string ZSwapObject::GetZSwapEnabled() const
{
    return ReadZSwapValue(ZSwapEnabledName);
}

void ZSwapObject::SetZSwapEnabled(const std::string& Value) const
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapEnabledName)));
    WriteZSwapValue(ZSwapEnabledName, Value);
    WriteLogEntry(ZSwapEnabledName, Value);
}

std::string ZSwapObject::GetZSwapSameFilledPages() const
{
    return ReadZSwapValue(ZSwapSameFilledPagesName);
}

void ZSwapObject::SetZSwapSameFilledPages(const std::string& Value) const
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapSameFilledPagesName)));
    WriteZSwapValue(ZSwapSameFilledPagesName, Value);
    WriteLogEntry(ZSwapSameFilledPagesName, Value);
}

std::string ZSwapObject::GetZSwapMaxPoolPercent() const
{
    return ReadZSwapValue(ZSwapMaxPoolPercentName);
}

void ZSwapObject::SetZSwapMaxPoolPercent(const std::string& Value) const
{
    if (CheckPercent(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorRange, std::make_format_args(ZSwapMaxPoolPercentName)));
    WriteZSwapValue(ZSwapMaxPoolPercentName, Value);
    WriteLogEntry(ZSwapMaxPoolPercentName, Value);
}

std::string ZSwapObject::GetZSwapCompressor() const
{
    return ReadZSwapValue(ZSwapCompressorName);
}

void ZSwapObject::SetZSwapCompressor(const std::string& Value) const
{
    if (Value.empty()) throw std::invalid_argument(std::vformat(ZSwapErrorEmpty, std::make_format_args(ZSwapCompressorName)));
    WriteZSwapValue(ZSwapCompressorName, Value);
    WriteLogEntry(ZSwapCompressorName, Value);
}

std::string ZSwapObject::GetZSwapZpool() const
{
    return ReadZSwapValue(ZSwapZpoolName);
}

void ZSwapObject::SetZSwapZpool(const std::string& Value) const
{
    if (Value.empty()) throw std::invalid_argument(std::vformat(ZSwapErrorEmpty, std::make_format_args(ZSwapZpoolName)));
    WriteZSwapValue(ZSwapZpoolName, Value);
    WriteLogEntry(ZSwapZpoolName, Value);
}

std::string ZSwapObject::GetZSwapAcceptThresholdPercent() const
{
    return ReadZSwapValue(ZSwapAcceptThresholdPercentName);
}

void ZSwapObject::SetZSwapAcceptThresholdPercent(const std::string& Value) const
{
    if (CheckPercent(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorRange, std::make_format_args(ZSwapAcceptThresholdPercentName)));
    WriteZSwapValue(ZSwapAcceptThresholdPercentName, Value);
    WriteLogEntry(ZSwapAcceptThresholdPercentName, Value);
}

std::string ZSwapObject::GetZSwapNonSameFilledPages() const
{
    return ReadZSwapValue(ZSwapNonSameFilledPagesName);
}

void ZSwapObject::SetZSwapNonSameFilledPages(const std::string& Value) const
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapNonSameFilledPagesName)));
    WriteZSwapValue(ZSwapNonSameFilledPagesName, Value);
    WriteLogEntry(ZSwapNonSameFilledPagesName, Value);
}

std::string ZSwapObject::GetZSwapExclusiveLoads() const
{
    return ReadZSwapValue(ZSwapExclusiveLoadsName);
}

void ZSwapObject::SetZSwapExclusiveLoads(const std::string& Value) const
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapExclusiveLoadsName)));
    WriteZSwapValue(ZSwapExclusiveLoadsName, Value);
    WriteLogEntry(ZSwapExclusiveLoadsName, Value);
}

std::string ZSwapObject::GetZSwapShrinkerEnabled() const
{
    return ReadZSwapValue(ZSwapShrinkerEnabledName);
}

void ZSwapObject::SetZSwapShrinkerEnabled(const std::string& Value) const
{
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapShrinkerEnabledName)));
    WriteZSwapValue(ZSwapShrinkerEnabledName, Value);
    WriteLogEntry(ZSwapShrinkerEnabledName, Value);
}

bool ZSwapObject::IsAvailable() const
{
    return std::filesystem::exists(ZSwapModuleParametersPath);
}
