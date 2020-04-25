/*
    Copyright (c) 2020 EasyCoding Team

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

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
