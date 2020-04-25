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

#ifndef KSYSINFO_HPP
#define KSYSINFO_HPP

#include <stdexcept>
#include <sys/sysinfo.h>

class KSysInfo
{
public:
    KSysInfo();
    __kernel_long_t& GetUptime();
    __kernel_ulong_t& GetTotalRam();
    __kernel_ulong_t& GetFreeRam();
    __kernel_ulong_t& GetSharedRam();
    __kernel_ulong_t& GetBufferedRam();
    __kernel_ulong_t& GetTotalSwap();
    __kernel_ulong_t& GetFreeSwap();
    __u16& GetProcessesCount();
    __kernel_ulong_t& GetTotalHighMem();
    __kernel_ulong_t& GetFreeHighMem();
    __u32& GetMemUnitSize();
private:
    struct sysinfo SysInfo;
};

#endif // KSYSINFO_HPP
