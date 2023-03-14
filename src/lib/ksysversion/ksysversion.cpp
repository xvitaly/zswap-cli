/**
 * SPDX-FileCopyrightText: 2020-2023 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <string>
#include <stdexcept>

#include "ksysversion/ksysversion.hpp"

std::string KSysVersion::ParseKernelVersion(const std::string& Version) const
{
    return Version.substr(0, Version.find("-"));
}

std::string KSysVersion::GetKernelVersion() const
{
    return ParseKernelVersion(UTSName.release);
}

KSysVersion::KSysVersion()
{
    if (uname(&UTSName) == -1) throw std::runtime_error("Got incorrect result by uname() call.");
}
