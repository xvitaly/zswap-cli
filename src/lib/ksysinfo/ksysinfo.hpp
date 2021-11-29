/**
 * SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef KSYSINFO_HPP
#define KSYSINFO_HPP

/** @file ksysinfo/ksysinfo.hpp
 *  This file gets memory information using Linux kernel API.
 */

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
     * @exception Raises an instance of std::runtime_error on error.
    */
    struct sysinfo SysInfo;
};

#endif // KSYSINFO_HPP
