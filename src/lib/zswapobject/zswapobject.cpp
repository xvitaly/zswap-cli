/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <stdexcept>
#include <string>

#include <fmt/format.h>
#include <semver.hpp>

#include "ksysversion/ksysversion.hpp"
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

bool ZSwapObject::CheckKernelVersion(const std::string& RequiredKernelVersion)
{
    return semver::from_string(KernelVersion) < semver::from_string(RequiredKernelVersion);
}

void ZSwapObject::WriteLogEntry(const std::string& Name, const std::string& NewValue, const std::string& OldValue)
{
    std::cout << fmt::format("Writing a new value \"{1}\" to the \"{0}\" variable. The old value was: \"{2}\".", Name, NewValue, OldValue) << std::endl;
}

void ZSwapObject::WriteZSwapValue(const std::string& Name, const std::string& Value)
{
    std::ofstream ZSwapSysFs(ZSwapModuleParametersPath + Name);
    ZSwapSysFs << Value;
    ZSwapSysFs.close();
}

std::string ZSwapObject::ReadZSwapValue(const std::string& Name)
{
    std::string Result;
    std::ifstream ZSwapSysFs(ZSwapModuleParametersPath + Name);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}

std::string& ZSwapObject::GetZSwapEnabled()
{
    return ZSwapEnabled;
}

void ZSwapObject::SetZSwapEnabled(const std::string& Value)
{
    if (CheckEnabled(Value)) throw std::invalid_argument("The value of ZSwapEnabled is incorrect (only Y or N are supported).");
    WriteLogEntry(ZSwapEnabledName, Value, ZSwapEnabled);
    ZSwapEnabled = Value;
    WriteZSwapValue(ZSwapEnabledName, Value);
}

std::string& ZSwapObject::GetZSwapSameFilledPages()
{
    return ZSwapSameFilledPages;
}

void ZSwapObject::SetZSwapSameFilledPages(const std::string& Value)
{
    if (CheckEnabled(Value)) throw std::invalid_argument("The value of ZSwapSameFilledPages is incorrect (only Y or N are supported).");
    WriteLogEntry(ZSwapSameFilledPagesName, Value, ZSwapSameFilledPages);
    ZSwapSameFilledPages = Value;
    WriteZSwapValue(ZSwapSameFilledPagesName, Value);
}

std::string& ZSwapObject::GetZSwapMaxPoolPercent()
{
    return ZSwapMaxPoolPercent;
}

void ZSwapObject::SetZSwapMaxPoolPercent(const std::string& Value)
{
    if (CheckPercent(Value)) throw std::invalid_argument("The value of ZSwapMaxPoolPercent is out of range [0..100].");
    WriteLogEntry(ZSwapMaxPoolPercentName, Value, ZSwapMaxPoolPercent);
    ZSwapMaxPoolPercent = Value;
    WriteZSwapValue(ZSwapMaxPoolPercentName, Value);
}

std::string& ZSwapObject::GetZSwapCompressor()
{
    return ZSwapCompressor;
}

void ZSwapObject::SetZSwapCompressor(const std::string& Value)
{
    if (Value.empty()) throw std::invalid_argument("The value of ZSwapCompressor is empty.");
    WriteLogEntry(ZSwapCompressorName, Value, ZSwapCompressor);
    ZSwapCompressor = Value;
    WriteZSwapValue(ZSwapCompressorName, Value);
}

std::string& ZSwapObject::GetZSwapZpool()
{
    return ZSwapZpool;
}

void ZSwapObject::SetZSwapZpool(const std::string& Value)
{
    if (Value.empty()) throw std::invalid_argument("The value of ZSwapZpool is empty.");
    WriteLogEntry(ZSwapZpoolName, Value, ZSwapZpool);
    ZSwapZpool = Value;
    WriteZSwapValue(ZSwapZpoolName, Value);
}

std::string& ZSwapObject::GetZSwapAcceptThresholdPercent()
{
    return ZSwapAcceptThresholdPercent;
}

void ZSwapObject::SetZSwapAcceptThresholdPercent(const std::string& Value)
{
    if (CheckKernelVersion(ZSwapAcceptThresholdRequiredKernelVersion)) throw std::runtime_error("Configuring ZSwapAcceptThresholdPercent requires kernel 5.6 or later.");
    if (CheckPercent(Value)) throw std::invalid_argument("The value of ZSwapAcceptThresholdPercent is out of range [0..100].");
    WriteLogEntry(ZSwapAcceptThresholdPercentName, Value, ZSwapAcceptThresholdPercent);
    ZSwapAcceptThresholdPercent = Value;
    WriteZSwapValue(ZSwapAcceptThresholdPercentName, Value);
}

std::string& ZSwapObject::GetZSwapNonSameFilledPages()
{
    return ZSwapNonSameFilledPages;
}

void ZSwapObject::SetZSwapNonSameFilledPages(const std::string& Value)
{
    if (CheckKernelVersion(ZSwapNonSameFilledPagesRequiredKernelVersion)) throw std::runtime_error("Configuring ZSwapNonSameFilledPages requires kernel 5.18 or later.");
    if (CheckEnabled(Value)) throw std::invalid_argument("The value of ZSwapNonSameFilledPages is incorrect (only Y or N are supported).");
    WriteLogEntry(ZSwapNonSameFilledPagesName, Value, ZSwapNonSameFilledPages);
    ZSwapNonSameFilledPages = Value;
    WriteZSwapValue(ZSwapNonSameFilledPagesName, Value);
}

std::string& ZSwapObject::GetZSwapExclusiveLoads()
{
    return ZSwapExclusiveLoads;
}

void ZSwapObject::SetZSwapExclusiveLoads(const std::string& Value)
{
    if (CheckKernelVersion(ZSwapExclusiveLoadsRequiredKernelVersion)) throw std::runtime_error("Configuring ZSwapExclusiveLoads requires kernel 6.5 or later.");
    if (CheckEnabled(Value)) throw std::invalid_argument("The value of ZSwapExclusiveLoads is incorrect (only Y or N are supported).");
    WriteLogEntry(ZSwapExclusiveLoadsName, Value, ZSwapExclusiveLoads);
    ZSwapExclusiveLoads = Value;
    WriteZSwapValue(ZSwapExclusiveLoadsName, Value);
}

std::string& ZSwapObject::GetZSwapShrinkerEnabled()
{
    return ZSwapShrinkerEnabled;
}

void ZSwapObject::SetZSwapShrinkerEnabled(const std::string& Value)
{
    if (CheckKernelVersion(ZSwapShrinkerEnabledRequiredKernelVersion)) throw std::runtime_error("Configuring ZSwapShrinkerEnabled requires kernel 6.8 or later.");
    if (CheckEnabled(Value)) throw std::invalid_argument("The value of ZSwapNonSameFilledPages is incorrect (only Y or N are supported).");
    WriteLogEntry(ZSwapShrinkerEnabledName, Value, ZSwapShrinkerEnabled);
    ZSwapShrinkerEnabled = Value;
    WriteZSwapValue(ZSwapShrinkerEnabledName, Value);
}

void ZSwapObject::ReadKernelVersion()
{
    KernelVersion = std::make_unique<KSysVersion>() -> GetKernelVersion();
}

void ZSwapObject::ReadValues()
{
    ZSwapEnabled = ReadZSwapValue(ZSwapEnabledName);
    ZSwapSameFilledPages = ReadZSwapValue(ZSwapSameFilledPagesName);
    ZSwapMaxPoolPercent = ReadZSwapValue(ZSwapMaxPoolPercentName);
    ZSwapCompressor = ReadZSwapValue(ZSwapCompressorName);
    ZSwapZpool = ReadZSwapValue(ZSwapZpoolName);
    ZSwapAcceptThresholdPercent = CheckKernelVersion(ZSwapAcceptThresholdRequiredKernelVersion) ? "N/A" : ReadZSwapValue(ZSwapObject::ZSwapAcceptThresholdPercentName);
    ZSwapNonSameFilledPages = CheckKernelVersion(ZSwapNonSameFilledPagesRequiredKernelVersion) ? "N/A" : ReadZSwapValue(ZSwapObject::ZSwapNonSameFilledPagesName);
    ZSwapExclusiveLoads = CheckKernelVersion(ZSwapExclusiveLoadsRequiredKernelVersion) ? "N/A" : ReadZSwapValue(ZSwapObject::ZSwapExclusiveLoadsName);
    ZSwapShrinkerEnabled = CheckKernelVersion(ZSwapShrinkerEnabledRequiredKernelVersion) ? "N/A" : ReadZSwapValue(ZSwapObject::ZSwapShrinkerEnabledName);
}

ZSwapObject::ZSwapObject()
{
    ReadKernelVersion();
    ReadValues();
}
