/**
 * SPDX-FileCopyrightText: 2020-2025 EasyCoding Team and contributors
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
 *
 * Attention! The return values of all methods that operate
 * on RAM and swap values must be multiplied by MemUnitSize
 * before use.
 *
 * We don't do this automatically because some architectures
 * may have more memory than the unsigned long type can
 * address.
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
    long GetUptime() const;

    /**
     * Gets the total amount of usable memory size in bytes.
     * @returns Total usable memory size.
    */
    unsigned long GetTotalRam() const;

    /**
     * Gets the total amount of usable memory size in bytes
     * as a floating point number.
     * @returns Total usable memory size.
    */
    float GetTotalRamF() const;

    /**
     * Gets the amount of free memory in bytes.
     * @returns Free memory size.
    */
    unsigned long GetFreeRam() const;

    /**
     * Gets the amount of free memory in bytes as a floating
     * point number.
     * @returns Free memory size.
    */
    float GetFreeRamF() const;

    /**
     * Gets the amount of shared memory in bytes.
     * @returns Shared memory size.
    */
    unsigned long GetSharedRam() const;

    /**
     * Gets the amount of shared memory in bytes as a floating
     * point number.
     * @returns Shared memory size.
    */
    float GetSharedRamF() const;

    /**
     * Gets the amount of memory used by buffers in bytes.
     * @returns Memory used by buffers size.
    */
    unsigned long GetBufferedRam() const;

    /**
     * Gets the amount of memory used by buffers in bytes
     * as a floating point number.
     * @returns Memory used by buffers size.
    */
    float GetBufferedRamF() const;

    /**
     * Gets the total size of the swap space in bytes.
     * @returns Total size of the swap space.
    */
    unsigned long GetTotalSwap() const;

    /**
     * Gets the total size of the swap space in bytes as
     * a floating point number.
     * @returns Total size of the swap space.
    */
    float GetTotalSwapF() const;

    /**
     * Gets the amount of free swap space in bytes.
     * @returns Available swap space.
    */
    unsigned long GetFreeSwap() const;

    /**
     * Gets the amount of free swap space in bytes as a
     * floating point number.
     * @returns Available swap space.
    */
    float GetFreeSwapF() const;

    /**
     * Gets the number of current processes.
     * @returns The number of current processes.
    */
    unsigned short GetProcessesCount() const;

    /**
     * Gets the amount of total high memory size in bytes.
     * @returns Total high memory size.
    */
    unsigned long GetTotalHighMem() const;

    /**
     * Gets the amount of total high memory size in bytes
     * as a floating point number.
     * @returns Total high memory size.
    */
    float GetTotalHighMemF() const;

    /**
     * Gets the amount of free high memory in bytes.
     * @returns Free high memory size.
    */
    unsigned long GetFreeHighMem() const;

    /**
     * Gets the amount of free high memory in bytes as
     * a floating point number.
     * @returns Free high memory size.
    */
    float GetFreeHighMemF() const;

    /**
     * Gets the memory unit size in bytes.
     * @returns Memory unit size.
    */
    unsigned int GetMemUnitSize() const;

    /**
     * Gets the value of the system memory page size.
     * @returns System memory page size.
    */
    long GetPageSize() const;
private:
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

    /**
     * Reads the sysinfo structure into the class fields.
     * @exception Raises an instance of std::runtime_error on error.
    */
    void ReadSysInfo();

    /**
     * Reads the SC_PAGESIZE system variable value.
    */
    void ReadPageSize();
};

#endif // KSYSINFO_HPP
