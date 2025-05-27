/**
 * SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/**
 * @file zswapobject/zswapobject.cpp
 * Contains the ZSwapObject class implementation.
*/

#include <format>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <regex>
#include <stdexcept>
#include <string>

#include "zswapobject/zswapobject.hpp"

void ZSwapObject::CheckValueBool(const std::string& Name, const std::string& Value) const
{
    if (!std::regex_match(Value, std::regex("^[YN]$"))) throw std::invalid_argument(std::format("The requested value for the option \"{0}\" is incorrect (only Y or N are supported)!", Name));
}

void ZSwapObject::CheckValueEmpty(const std::string& Name, const std::string& Value) const
{
    if (Value.empty()) throw std::invalid_argument(std::format("The requested value for the option \"{0}\" is empty!", Name));
}

void ZSwapObject::CheckValueRange(const std::string& Name, const std::string& Value) const
{
    if (!std::regex_match(Value, std::regex("^\\d{1,2}|100$"))) throw std::invalid_argument(std::format("The requested value for the option \"{0}\" is out of range [0..100]!", Name));
}

void ZSwapObject::WriteLogEntry(const std::string& Name, const std::string& Value) const
{
    std::cout << std::format("The option \"{0}\" has been set to a new value of \"{1}\".", Name, Value) << std::endl;
}

void ZSwapObject::WriteZSwapValue(const std::string& Name, const std::string& Value) const
{
    const std::string FullPath = ZSwapModuleParametersPath + Name;
    if (!std::filesystem::exists(FullPath)) throw std::runtime_error(std::format("Configuring the option \"{0}\" is not possible on the current kernel!", Name));
    std::ofstream ZSwapSysFs(FullPath);
    ZSwapSysFs << Value;
}

std::optional<std::string> ZSwapObject::ReadZSwapValue(const std::string& Name) const
{
    const std::string FullPath = ZSwapModuleParametersPath + Name;
    if (!std::filesystem::exists(FullPath)) return std::nullopt;
    std::string Result;
    std::ifstream ZSwapSysFs(FullPath);
    ZSwapSysFs >> Result;
    return Result;
}

std::optional<std::string> ZSwapObject::GetZSwapEnabled() const
{
    return ReadZSwapValue(ZSwapEnabledName);
}

void ZSwapObject::SetZSwapEnabled(const std::string& Value) const
{
    CheckValueBool(ZSwapEnabledName, Value);
    WriteZSwapValue(ZSwapEnabledName, Value);
    WriteLogEntry(ZSwapEnabledName, Value);
}

std::optional<std::string> ZSwapObject::GetZSwapSameFilledPages() const
{
    return ReadZSwapValue(ZSwapSameFilledPagesName);
}

void ZSwapObject::SetZSwapSameFilledPages(const std::string& Value) const
{
    CheckValueBool(ZSwapSameFilledPagesName, Value);
    WriteZSwapValue(ZSwapSameFilledPagesName, Value);
    WriteLogEntry(ZSwapSameFilledPagesName, Value);
}

std::optional<std::string> ZSwapObject::GetZSwapMaxPoolPercent() const
{
    return ReadZSwapValue(ZSwapMaxPoolPercentName);
}

void ZSwapObject::SetZSwapMaxPoolPercent(const std::string& Value) const
{
    CheckValueRange(ZSwapMaxPoolPercentName, Value);
    WriteZSwapValue(ZSwapMaxPoolPercentName, Value);
    WriteLogEntry(ZSwapMaxPoolPercentName, Value);
}

std::optional<std::string> ZSwapObject::GetZSwapCompressor() const
{
    return ReadZSwapValue(ZSwapCompressorName);
}

void ZSwapObject::SetZSwapCompressor(const std::string& Value) const
{
    CheckValueEmpty(ZSwapCompressorName, Value);
    WriteZSwapValue(ZSwapCompressorName, Value);
    WriteLogEntry(ZSwapCompressorName, Value);
}

std::optional<std::string> ZSwapObject::GetZSwapZpool() const
{
    return ReadZSwapValue(ZSwapZpoolName);
}

void ZSwapObject::SetZSwapZpool(const std::string& Value) const
{
    CheckValueEmpty(ZSwapZpoolName, Value);
    WriteZSwapValue(ZSwapZpoolName, Value);
    WriteLogEntry(ZSwapZpoolName, Value);
}

std::optional<std::string> ZSwapObject::GetZSwapAcceptThresholdPercent() const
{
    return ReadZSwapValue(ZSwapAcceptThresholdPercentName);
}

void ZSwapObject::SetZSwapAcceptThresholdPercent(const std::string& Value) const
{
    CheckValueRange(ZSwapAcceptThresholdPercentName, Value);
    WriteZSwapValue(ZSwapAcceptThresholdPercentName, Value);
    WriteLogEntry(ZSwapAcceptThresholdPercentName, Value);
}

std::optional<std::string> ZSwapObject::GetZSwapNonSameFilledPages() const
{
    return ReadZSwapValue(ZSwapNonSameFilledPagesName);
}

void ZSwapObject::SetZSwapNonSameFilledPages(const std::string& Value) const
{
    CheckValueBool(ZSwapNonSameFilledPagesName, Value);
    WriteZSwapValue(ZSwapNonSameFilledPagesName, Value);
    WriteLogEntry(ZSwapNonSameFilledPagesName, Value);
}

std::optional<std::string> ZSwapObject::GetZSwapExclusiveLoads() const
{
    return ReadZSwapValue(ZSwapExclusiveLoadsName);
}

void ZSwapObject::SetZSwapExclusiveLoads(const std::string& Value) const
{
    CheckValueBool(ZSwapExclusiveLoadsName, Value);
    WriteZSwapValue(ZSwapExclusiveLoadsName, Value);
    WriteLogEntry(ZSwapExclusiveLoadsName, Value);
}

std::optional<std::string> ZSwapObject::GetZSwapShrinkerEnabled() const
{
    return ReadZSwapValue(ZSwapShrinkerEnabledName);
}

void ZSwapObject::SetZSwapShrinkerEnabled(const std::string& Value) const
{
    CheckValueBool(ZSwapShrinkerEnabledName, Value);
    WriteZSwapValue(ZSwapShrinkerEnabledName, Value);
    WriteLogEntry(ZSwapShrinkerEnabledName, Value);
}

bool ZSwapObject::IsAvailable() const
{
    return std::filesystem::exists(ZSwapModuleParametersPath);
}
