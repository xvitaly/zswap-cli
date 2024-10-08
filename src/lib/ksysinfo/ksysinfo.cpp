/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/** @file ksysinfo/ksysinfo.cpp
 *  Contains the KSysInfo class implementation.
 */

#include <stdexcept>

#include <linux/sysinfo.h>
#include <sys/sysinfo.h>

#include "ksysinfo/ksysinfo.hpp"
#include "cwrappers/cwrappers.hpp"

long& KSysInfo::GetUptime()
{
    return Uptime;
}

unsigned long& KSysInfo::GetTotalRam()
{
    return TotalRam;
}

unsigned long& KSysInfo::GetFreeRam()
{
    return FreeRam;
}

unsigned long& KSysInfo::GetSharedRam()
{
    return SharedRam;
}

unsigned long& KSysInfo::GetBufferedRam()
{
    return BufferedRam;
}

unsigned long& KSysInfo::GetTotalSwap()
{
    return TotalSwap;
}

unsigned long& KSysInfo::GetFreeSwap()
{
    return FreeSwap;
}

unsigned short& KSysInfo::GetProcessesCount()
{
    return ProcessesCount;
}

unsigned long& KSysInfo::GetTotalHighMem()
{
    return TotalHighMem;
}

unsigned long& KSysInfo::GetFreeHighMem()
{
    return FreeHighMem;
}

unsigned int& KSysInfo::GetMemUnitSize()
{
    return MemUnitSize;
}

long& KSysInfo::GetPageSize()
{
    return PageSize;
}

void KSysInfo::ReadSysInfo()
{
    struct sysinfo SysInfo;
    if (sysinfo(&SysInfo) == -1) throw std::runtime_error("Got incorrect result by sysinfo() call.");
    Uptime = static_cast<long>(SysInfo.uptime);
    TotalRam = static_cast<unsigned long>(SysInfo.totalram);
    FreeRam = static_cast<unsigned long>(SysInfo.freeram);
    SharedRam = static_cast<unsigned long>(SysInfo.sharedram);
    BufferedRam = static_cast<unsigned long>(SysInfo.bufferram);
    TotalSwap = static_cast<unsigned long>(SysInfo.totalswap);
    FreeSwap = static_cast<unsigned long>(SysInfo.freeswap);
    ProcessesCount = static_cast<unsigned short>(SysInfo.procs);
    TotalHighMem = static_cast<unsigned long>(SysInfo.totalhigh);
    FreeHighMem = static_cast<unsigned long>(SysInfo.freehigh);
    MemUnitSize = static_cast<unsigned int>(SysInfo.mem_unit);
}

void KSysInfo::ReadPageSize()
{
    PageSize = CWrappers::GetSCPageSize();
}

KSysInfo::KSysInfo()
{
    ReadSysInfo();
    ReadPageSize();
}
