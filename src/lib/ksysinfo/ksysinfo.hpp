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

/** @file ksysinfo/ksysinfo.hpp
 *  This file gets memory information using Linux kernel API.
 */

#include <stdexcept>
#include <sys/sysinfo.h>

/**
 *  Class with properties and methods for working with memory
 * information using Linux kernel API.
*/
class KSysInfo
{
public:
    /**
     *  Constructor of the KSysInfo class.
    */
    KSysInfo();

    /**
     *  Gets current uptime (in seconds since boot).
     * @returns Current uptime.
    */
    __kernel_long_t& GetUptime();

    /**
     *  Gets total usable main memory size in bytes.
     * @returns Total usable main memory size.
    */
    __kernel_ulong_t& GetTotalRam();

    /**
     *  Gets available memory size in bytes.
     * @returns Available memory size.
    */
    __kernel_ulong_t& GetFreeRam();

    /**
     *  Gets amount of shared memory in bytes.
     * @returns Amount of shared memory.
    */
    __kernel_ulong_t& GetSharedRam();

    /**
     *  Gets amount of memory used by buffers in bytes.
     * @returns Amount of memory used by buffers.
    */
    __kernel_ulong_t& GetBufferedRam();

    /**
     *  Gets total swap space size in bytes.
     * @returns Total swap space size.
    */
    __kernel_ulong_t& GetTotalSwap();

    /**
     *  Gets available swap space in bytes.
     * @returns Available swap space.
    */
    __kernel_ulong_t& GetFreeSwap();

    /**
     *  Gets the number of current processes.
     * @returns The number of current processes.
    */
    __u16& GetProcessesCount();

    /**
     *  Gets total high memory size in bytes.
     * @returns Total high memory size.
    */
    __kernel_ulong_t& GetTotalHighMem();

    /**
     *  Gets available high memory size in bytes.
     * @returns Available high memory size.
    */
    __kernel_ulong_t& GetFreeHighMem();

    /**
     *  Gets memory unit size in bytes.
     * @returns Memory unit size.
    */
    __u32& GetMemUnitSize();
private:
    /**
     *  Stores instance of sysinfo structure.
    */
    struct sysinfo SysInfo;
};

#endif // KSYSINFO_HPP
