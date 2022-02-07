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

#include "ksysinfo/ksystype.hpp"

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
    ksystype::long_t& GetUptime();

    /**
     *  Gets total usable main memory size in bytes.
     * @returns Total usable main memory size.
    */
    ksystype::ulong_t& GetTotalRam();

    /**
     *  Gets available memory size in bytes.
     * @returns Available memory size.
    */
    ksystype::ulong_t& GetFreeRam();

    /**
     *  Gets amount of shared memory in bytes.
     * @returns Amount of shared memory.
    */
    ksystype::ulong_t& GetSharedRam();

    /**
     *  Gets amount of memory used by buffers in bytes.
     * @returns Amount of memory used by buffers.
    */
    ksystype::ulong_t& GetBufferedRam();

    /**
     *  Gets total swap space size in bytes.
     * @returns Total swap space size.
    */
    ksystype::ulong_t& GetTotalSwap();

    /**
     *  Gets available swap space in bytes.
     * @returns Available swap space.
    */
    ksystype::ulong_t& GetFreeSwap();

    /**
     *  Gets the number of current processes.
     * @returns The number of current processes.
    */
    ksystype::ushort_t& GetProcessesCount();

    /**
     *  Gets total high memory size in bytes.
     * @returns Total high memory size.
    */
    ksystype::ulong_t& GetTotalHighMem();

    /**
     *  Gets available high memory size in bytes.
     * @returns Available high memory size.
    */
    ksystype::ulong_t& GetFreeHighMem();

    /**
     *  Gets memory unit size in bytes.
     * @returns Memory unit size.
    */
    ksystype::uint_t& GetMemUnitSize();
private:
    /**
     *  Stores instance of sysinfo structure.
     * @exception Raises an instance of std::runtime_error on error.
    */
    struct sysinfo SysInfo;
};

#endif // KSYSINFO_HPP
