/**
 * SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/**
 * @file ksysinfo/ksysinfo.cpp
 * Contains the KSysInfo class implementation.
*/

#include <stdexcept>

#include <linux/sysinfo.h>
#include <sys/sysinfo.h>

#include "ksysinfo/ksysinfo.hpp"
#include "cwrappers/cwrappers.hpp"

long KSysInfo::GetUptime() const
{
    return Uptime;
}

unsigned long KSysInfo::GetTotalRam() const
{
    return TotalRam;
}

float KSysInfo::GetTotalRamF() const
{
    return static_cast<float>(TotalRam) * static_cast<float>(MemUnitSize);
}

unsigned long KSysInfo::GetFreeRam() const
{
    return FreeRam;
}

float KSysInfo::GetFreeRamF() const
{
    return static_cast<float>(FreeRam) * static_cast<float>(MemUnitSize);
}

unsigned long KSysInfo::GetSharedRam() const
{
    return SharedRam;
}

float KSysInfo::GetSharedRamF() const
{
    return static_cast<float>(SharedRam) * static_cast<float>(MemUnitSize);
}

unsigned long KSysInfo::GetBufferedRam() const
{
    return BufferedRam;
}

float KSysInfo::GetBufferedRamF() const
{
    return static_cast<float>(BufferedRam) * static_cast<float>(MemUnitSize);
}

unsigned long KSysInfo::GetTotalSwap() const
{
    return TotalSwap;
}

float KSysInfo::GetTotalSwapF() const
{
    return static_cast<float>(TotalSwap) * static_cast<float>(MemUnitSize);
}

unsigned long KSysInfo::GetFreeSwap() const
{
    return FreeSwap;
}

float KSysInfo::GetFreeSwapF() const
{
    return static_cast<float>(FreeSwap) * static_cast<float>(MemUnitSize);
}

unsigned short KSysInfo::GetProcessesCount() const
{
    return ProcessesCount;
}

unsigned long KSysInfo::GetTotalHighMem() const
{
    return TotalHighMem;
}

float KSysInfo::GetTotalHighMemF() const
{
    return static_cast<float>(TotalHighMem) * static_cast<float>(MemUnitSize);
}

unsigned long KSysInfo::GetFreeHighMem() const
{
    return FreeHighMem;
}

float KSysInfo::GetFreeHighMemF() const
{
    return static_cast<float>(FreeHighMem) * static_cast<float>(MemUnitSize);
}

unsigned int KSysInfo::GetMemUnitSize() const
{
    return MemUnitSize;
}

long KSysInfo::GetPageSize() const
{
    return PageSize;
}

bool KSysInfo::IsSwapAvailable() const
{
    return TotalSwap != 0UL;
}

void KSysInfo::ReadSysInfo()
{
    struct sysinfo SysInfo;
    if (sysinfo(&SysInfo) == -1) throw std::runtime_error("Got incorrect result from sysinfo() call.");
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
