/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/**
 * @file ksysversion/ksysversion.cpp
 * Contains the KSysVersion class implementation.
*/

#include <format>
#include <string>
#include <stdexcept>

#include <linux/version.h>
#include <sys/utsname.h>

#include "ksysversion/ksysversion.hpp"

std::string KSysVersion::ParseKernelVersion(const std::string& Version) const
{
    return Version.substr(0, Version.find("-"));
}

std::string KSysVersion::GetHeadersVersion() const
{
    return std::format("{0}.{1}.{2}", LINUX_VERSION_MAJOR, LINUX_VERSION_PATCHLEVEL, LINUX_VERSION_SUBLEVEL);
}

std::string KSysVersion::GetKernelVersion() const
{
    struct utsname UTSName;
    if (uname(&UTSName) == -1) throw std::runtime_error("Got incorrect result from uname() call.");
    return ParseKernelVersion(UTSName.release);
}
