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

#ifndef ZSWAPWORKER_H
#define ZSWAPWORKER_H

/** @file zswapworker/zswapworker.hpp
 *  This file contains methods for working with ZSwap kernel module.
 */

#include <iostream>
#include <fstream>

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

#endif // ZSWAPWORKER_H
