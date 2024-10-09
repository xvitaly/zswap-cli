/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef KSYSINFO_HPP
#define KSYSINFO_HPP

/**
 * @file ksysinfo/ksysinfo.hpp
 * Contains the KSysInfo class definition.
*/

/**
 * Class for working with memory information using the
 * kernel API.
*/
class KSysInfo
{
public:
    /**
     * Constructor of the KSysInfo class.
    */
    KSysInfo();

    /**
     * Gets current uptime (in seconds since boot).
     * @returns Current uptime.
    */
    long& GetUptime();

    /**
     * Gets the total amount of usable memory size in bytes.
     * @returns Total usable memory size.
    */
    unsigned long& GetTotalRam();

    /**
     * Gets the amount of free memory in bytes.
     * @returns Free memory size.
    */
    unsigned long& GetFreeRam();

    /**
     * Gets the amount of shared memory in bytes.
     * @returns Shared memory size.
    */
    unsigned long& GetSharedRam();

    /**
     * Gets the amount of memory used by buffers in bytes.
     * @returns Memory used by buffers size.
    */
    unsigned long& GetBufferedRam();

    /**
     * Gets the total size of the swap space in bytes.
     * @returns Total size of the swap space.
    */
    unsigned long& GetTotalSwap();

    /**
     * Gets the amount of free swap space in bytes.
     * @returns Available swap space.
    */
    unsigned long& GetFreeSwap();

    /**
     * Gets the number of current processes.
     * @returns The number of current processes.
    */
    unsigned short& GetProcessesCount();

    /**
     * Gets the amount of total high memory size in bytes.
     * @returns Total high memory size.
    */
    unsigned long& GetTotalHighMem();

    /**
     * Gets the amount of free high memory in bytes.
     * @returns Free high memory size.
    */
    unsigned long& GetFreeHighMem();

    /**
     * Gets the memory unit size in bytes.
     * @returns Memory unit size.
    */
    unsigned int& GetMemUnitSize();

    /**
     * Gets the value of the system memory page size.
     * @returns System memory page size.
    */
    long& GetPageSize();
private:
    /**
     * Reads the sysinfo structure into the class fields.
     * @exception Raises an instance of std::runtime_error on error.
    */
    void ReadSysInfo();

    /**
     * Reads the SC_PAGESIZE system variable value.
    */
    void ReadPageSize();

    /**
     * Stores current uptime (in seconds since boot) value.
    */
    long Uptime;

    /**
     * Stores the total amount of usable memory size in bytes value.
    */
    unsigned long TotalRam;

    /**
     * Stores the amount of free memory in bytes value.
    */
    unsigned long FreeRam;

    /**
     * Stores the amount of shared memory in bytes value.
    */
    unsigned long SharedRam;

    /**
     * Stores the amount of memory used by buffers in bytes value.
    */
    unsigned long BufferedRam;

    /**
     * Stores the total size of the swap space in bytes value.
    */
    unsigned long TotalSwap;

    /**
     * Stores the amount of free swap space in bytes value.
    */
    unsigned long FreeSwap;

    /**
     * Stores the number of current processes value value.
    */
    unsigned short ProcessesCount;

    /**
     * Stores the amount of total high memory size in bytes value.
    */
    unsigned long TotalHighMem;

    /**
     * Stores the amount of free high memory in bytes value.
    */
    unsigned long FreeHighMem;

    /**
     * Stores the memory unit size in bytes value.
    */
    unsigned int MemUnitSize;

    /**
     * Stores the system memory page size value.
    */
    long PageSize;
};

#endif // KSYSINFO_HPP
