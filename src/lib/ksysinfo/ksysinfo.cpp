/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <stdexcept>
#include <sys/sysinfo.h>

#include "ksysinfo/ksystype.hpp"
#include "ksysinfo/ksysinfo.hpp"

ksystype::long_t& KSysInfo::GetUptime()
{
    return SysInfo.uptime;
}

ksystype::ulong_t& KSysInfo::GetTotalRam()
{
    return SysInfo.totalram;
}

ksystype::ulong_t& KSysInfo::GetFreeRam()
{
    return SysInfo.freeram;
}

ksystype::ulong_t& KSysInfo::GetSharedRam()
{
    return SysInfo.sharedram;
}

ksystype::ulong_t& KSysInfo::GetBufferedRam()
{
    return SysInfo.bufferram;
}

ksystype::ulong_t& KSysInfo::GetTotalSwap()
{
    return SysInfo.totalswap;
}

ksystype::ulong_t& KSysInfo::GetFreeSwap()
{
    return SysInfo.freeswap;
}

ksystype::ushort_t& KSysInfo::GetProcessesCount()
{
    return SysInfo.procs;
}

ksystype::ulong_t& KSysInfo::GetTotalHighMem()
{
    return SysInfo.totalhigh;
}

ksystype::ulong_t& KSysInfo::GetFreeHighMem()
{
    return SysInfo.freehigh;
}

ksystype::uint_t& KSysInfo::GetMemUnitSize()
{
    return SysInfo.mem_unit;
}

KSysInfo::KSysInfo()
{
    if (sysinfo(&SysInfo) == -1) throw std::runtime_error("Got incorrect result by sysinfo() call.");
}
