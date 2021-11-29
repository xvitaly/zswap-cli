/**
 * SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <stdexcept>
#include <sys/sysinfo.h>

#include "ksysinfo/ksysinfo.hpp"

__kernel_long_t& KSysInfo::GetUptime()
{
    return SysInfo.uptime;
}

__kernel_ulong_t& KSysInfo::GetTotalRam()
{
    return SysInfo.totalram;
}

__kernel_ulong_t& KSysInfo::GetFreeRam()
{
    return SysInfo.freeram;
}

__kernel_ulong_t& KSysInfo::GetSharedRam()
{
    return SysInfo.sharedram;
}

__kernel_ulong_t& KSysInfo::GetBufferedRam()
{
    return SysInfo.bufferram;
}

__kernel_ulong_t& KSysInfo::GetTotalSwap()
{
    return SysInfo.totalswap;
}

__kernel_ulong_t& KSysInfo::GetFreeSwap()
{
    return SysInfo.freeswap;
}

__u16& KSysInfo::GetProcessesCount()
{
    return SysInfo.procs;
}

__kernel_ulong_t& KSysInfo::GetTotalHighMem()
{
    return SysInfo.totalhigh;
}

__kernel_ulong_t& KSysInfo::GetFreeHighMem()
{
    return SysInfo.freehigh;
}

__u32& KSysInfo::GetMemUnitSize()
{
    return SysInfo.mem_unit;
}

KSysInfo::KSysInfo()
{
    if (sysinfo(&SysInfo) == -1) throw std::runtime_error("Got incorrect result by sysinfo() call.");
}
