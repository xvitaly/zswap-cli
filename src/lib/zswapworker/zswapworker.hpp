/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef ZSWAPWORKER_HPP
#define ZSWAPWORKER_HPP

/** @file zswapworker/zswapworker.hpp
 *  This file contains methods for working with ZSwap kernel module.
 */

#include <string>

/**
 *  Static class with methods for working with ZSwap kernel module.
*/
class ZSwapWorker
{
public:
    /**
     *  Writes the ZSwap kernel module value.
     * @param Name Name.
     * @param Value Value.
    */
    static void WriteZSwapValue(const std::string&, const std::string&);

    /**
     *  Reads the value of the ZSwap kernel module by specified name.
     * @param Name Value name.
     * @returns Value.
    */
    static std::string ReadZSwapValue(const std::string&);

    /**
     *  Reads the debug value of the ZSwap kernel module by specified name.
     * @param Name Debug value name.
     * @returns Value.
    */
    static long ReadZSwapDebugValue(const std::string&);
private:
    /**
     *  Default constructor of the ZSwapWorker class. No one should use it.
    */
    ZSwapWorker() = default;
};

#endif // ZSWAPWORKER_HPP
