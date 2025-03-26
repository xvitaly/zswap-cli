/**
 * SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/**
 * @file cwrappers/cwrappers.cpp
 * Contains the CWrappers class implementation.
*/

#include <string>
#include <stdlib.h>
#include <unistd.h>

#include "cwrappers/cwrappers.hpp"

std::string CWrappers::GetEnv(const std::string& KeyName)
{
    const char* EnvValue = getenv(KeyName.c_str());
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
