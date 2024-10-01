/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <format>
#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <stdexcept>
#include <string>

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
    return semver::from_string(KernelVersion) >= semver::from_string(RequiredKernelVersion);
}

bool ZSwapObject::CheckKernelVersionRange(const std::string& MinKernelVersion, const std::string& MaxKernelVersion)
{
    return semver::from_string(KernelVersion) >= semver::from_string(MinKernelVersion) &&
           semver::from_string(KernelVersion) < semver::from_string(MaxKernelVersion);
}

void ZSwapObject::WriteLogEntry(const std::string& Name, const std::string& Value)
{
    std::cout << std::vformat(ZSwapMessageLog, std::make_format_args(Name, Value)) << std::endl;
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
    if (!ZSwapSameFilledPagesAvailable) throw std::runtime_error(std::vformat(ZSwapErrorKernelRange, std::make_format_args(ZSwapSameFilledPagesName, ZSwapSameFilledPagesRequiredKernelVersion, ZSwapSameFilledPagesUnavailableKernelVersion)));
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
    return ZSwapAcceptThresholdPercentAvailable ? ReadZSwapValue(ZSwapObject::ZSwapAcceptThresholdPercentName) : "N/A";
}

void ZSwapObject::SetZSwapAcceptThresholdPercent(const std::string& Value)
{
    if (!ZSwapAcceptThresholdPercentAvailable) throw std::runtime_error(std::vformat(ZSwapErrorKernel, std::make_format_args(ZSwapAcceptThresholdPercentName, ZSwapAcceptThresholdRequiredKernelVersion)));
    if (CheckPercent(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorRange, std::make_format_args(ZSwapAcceptThresholdPercentName)));
    WriteLogEntry(ZSwapAcceptThresholdPercentName, Value);
    WriteZSwapValue(ZSwapAcceptThresholdPercentName, Value);
}

std::string ZSwapObject::GetZSwapNonSameFilledPages()
{
    return ZSwapNonSameFilledPagesAvailable ? ReadZSwapValue(ZSwapObject::ZSwapNonSameFilledPagesName) : "N/A";
}

void ZSwapObject::SetZSwapNonSameFilledPages(const std::string& Value)
{
    if (!ZSwapNonSameFilledPagesAvailable) throw std::runtime_error(std::vformat(ZSwapErrorKernelRange, std::make_format_args(ZSwapNonSameFilledPagesName, ZSwapNonSameFilledPagesRequiredKernelVersion, ZSwapNonSameFilledPagesUnavailableKernelVersion)));
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapNonSameFilledPagesName)));
    WriteLogEntry(ZSwapNonSameFilledPagesName, Value);
    WriteZSwapValue(ZSwapNonSameFilledPagesName, Value);
}

std::string ZSwapObject::GetZSwapExclusiveLoads()
{
    return ZSwapExclusiveLoadsAvailable ? ReadZSwapValue(ZSwapObject::ZSwapExclusiveLoadsName) : "N/A";
}

void ZSwapObject::SetZSwapExclusiveLoads(const std::string& Value)
{
    if (!ZSwapExclusiveLoadsAvailable) throw std::runtime_error(std::vformat(ZSwapErrorKernelRange, std::make_format_args(ZSwapExclusiveLoadsName, ZSwapExclusiveLoadsRequiredKernelVersion, ZSwapExclusiveLoadsUnavailableKernelVersion)));
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapExclusiveLoadsName)));
    WriteLogEntry(ZSwapExclusiveLoadsName, Value);
    WriteZSwapValue(ZSwapExclusiveLoadsName, Value);
}

std::string ZSwapObject::GetZSwapShrinkerEnabled()
{
    return ZSwapShrinkerEnabledAvailable ? ReadZSwapValue(ZSwapObject::ZSwapShrinkerEnabledName) : "N/A";
}

void ZSwapObject::SetZSwapShrinkerEnabled(const std::string& Value)
{
    if (!ZSwapShrinkerEnabledAvailable) throw std::runtime_error(std::vformat(ZSwapErrorKernel, std::make_format_args(ZSwapShrinkerEnabledName, ZSwapShrinkerEnabledRequiredKernelVersion)));
    if (CheckEnabled(Value)) throw std::invalid_argument(std::vformat(ZSwapErrorBool, std::make_format_args(ZSwapShrinkerEnabledName)));
    WriteLogEntry(ZSwapShrinkerEnabledName, Value);
    WriteZSwapValue(ZSwapShrinkerEnabledName, Value);
}

void ZSwapObject::ReadAvailability()
{
    ZSwapEnabledAvailable = true;
    ZSwapSameFilledPagesAvailable = CheckKernelVersionRange(ZSwapSameFilledPagesRequiredKernelVersion, ZSwapSameFilledPagesUnavailableKernelVersion);
    ZSwapMaxPoolPercentAvailable = true;
    ZSwapCompressorAvailable = true;
    ZSwapZpoolAvailable = true;
    ZSwapAcceptThresholdPercentAvailable = CheckKernelVersion(ZSwapAcceptThresholdRequiredKernelVersion);
    ZSwapNonSameFilledPagesAvailable = CheckKernelVersionRange(ZSwapNonSameFilledPagesRequiredKernelVersion, ZSwapNonSameFilledPagesUnavailableKernelVersion);
    ZSwapExclusiveLoadsAvailable = CheckKernelVersionRange(ZSwapExclusiveLoadsRequiredKernelVersion, ZSwapExclusiveLoadsUnavailableKernelVersion);
    ZSwapShrinkerEnabledAvailable = CheckKernelVersion(ZSwapShrinkerEnabledRequiredKernelVersion);
}

void ZSwapObject::ReadKernelVersion()
{
    KernelVersion = std::make_unique<KSysVersion>() -> GetKernelVersion();
}

ZSwapObject::ZSwapObject()
{
    ReadKernelVersion();
    ReadAvailability();
}
