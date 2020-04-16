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

#include "zswapworker/zswapworker.hpp"

void ZSwapWorker::WriteZSwapValue(const std::string& Name, const std::string& Value)
{
    std::ofstream ZSwapSysFs("/sys/module/zswap/parameters/" + Name);
    ZSwapSysFs << Value;
    ZSwapSysFs.close();
}

std::string ZSwapWorker::ReadZSwapValue(const std::string& Name)
{
    std::string Result;
    std::ifstream ZSwapSysFs("/sys/module/zswap/parameters/" + Name);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}

std::string ZSwapWorker::ReadZSwapDebugValue(const std::string& Name)
{
    std::string Result;
    std::ifstream ZSwapSysFs("/sys/kernel/debug/zswap/" + Name);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}
