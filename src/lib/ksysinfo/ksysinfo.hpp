/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef KSYSINFO_HPP
#define KSYSINFO_HPP

/** @file ksysinfo/ksysinfo.hpp
 *  This file gets memory information using the kernel API.
 */

/**
 *  Class with properties and methods for working with memory
 * information using the kernel API.
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
    long& GetUptime();

    /**
     *  Gets total usable main memory size in bytes.
     * @returns Total usable main memory size.
    */
    unsigned long& GetTotalRam();

    /**
     *  Gets available memory size in bytes.
     * @returns Available memory size.
    */
    unsigned long& GetFreeRam();

    /**
     *  Gets amount of shared memory in bytes.
     * @returns Amount of shared memory.
    */
    unsigned long& GetSharedRam();

    /**
     *  Gets amount of memory used by buffers in bytes.
     * @returns Amount of memory used by buffers.
    */
    unsigned long& GetBufferedRam();

    /**
     *  Gets total swap space size in bytes.
     * @returns Total swap space size.
    */
    unsigned long& GetTotalSwap();

    /**
     *  Gets available swap space in bytes.
     * @returns Available swap space.
    */
    unsigned long& GetFreeSwap();

    /**
     *  Gets the number of current processes.
     * @returns The number of current processes.
    */
    unsigned short& GetProcessesCount();

    /**
     *  Gets total high memory size in bytes.
     * @returns Total high memory size.
    */
    unsigned long& GetTotalHighMem();

    /**
     *  Gets available high memory size in bytes.
     * @returns Available high memory size.
    */
    unsigned long& GetFreeHighMem();

    /**
     *  Gets memory unit size in bytes.
     * @returns Memory unit size.
    */
    unsigned int& GetMemUnitSize();

    /**
     *  Gets system page size value.
     * @returns System page size value.
    */
    long& GetPageSize();
private:
    /**
     *  Reads the sysinfo structure into the class fields.
     * @exception Raises an instance of std::runtime_error on error.
    */
    void ReadSysInfo();

    /**
     *  Reads the SC_PAGESIZE system variable value.
    */
    void ReadPageSize();

    /**
     *  Stores current uptime (in seconds since boot) value.
    */
    long Uptime;

    /**
     *  Stores total usable main memory size in bytes value.
    */
    unsigned long TotalRam;

    /**
     *  Stores the available memory size in bytes value.
    */
    unsigned long FreeRam;

    /**
     *  Stores the amount of shared memory in bytes value.
    */
    unsigned long SharedRam;

    /**
     *  Stores the amount of memory used by buffers in bytes value.
    */
    unsigned long BufferedRam;

    /**
     *  Stores the amount of memory used by buffers in bytes value.
    */
    unsigned long TotalSwap;

    /**
     *  Stores available swap space in bytes value.
    */
    unsigned long FreeSwap;

    /**
     *  Stores the number of current processes value.
    */
    unsigned short ProcessesCount;

    /**
     *  Stores total high memory size in bytes value.
    */
    unsigned long TotalHighMem;

    /**
     *  Stores the available high memory size in bytes value.
    */
    unsigned long FreeHighMem;

    /**
     *  Stores memory unit size in bytes value.
    */
    unsigned int MemUnitSize;

    /**
     *  Stores the system page size value.
    */
    long PageSize;
};

#endif // KSYSINFO_HPP
