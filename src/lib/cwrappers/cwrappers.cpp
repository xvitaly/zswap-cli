/**
 * SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <string>
#include <unistd.h>

#include "cwrappers/cwrappers.hpp"

std::string CWrappers::GetEnv(const std::string& KeyName)
{
    char const* EnvValue = getenv(KeyName.c_str());
    return EnvValue != nullptr ? std::string(EnvValue) : std::string();
}

bool CWrappers::CheckRoot()
{
    return getuid();
}

long CWrappers::GetSCPageSize()
{
    return sysconf(_SC_PAGESIZE);
}
