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

#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <fmt/format.h>
#include <cxxopts.hpp>

#include "cwrappers/cwrappers.hpp"
#include "zswapworker/zswapworker.hpp"
#include "zswapobject/zswapobject.hpp"

class Application
{
public:
    Application();
    int Run(cxxopts::ParseResult const&);
protected:
    ZSwapObject ZSwapEnabled;
    ZSwapObject ZSwapSameFilledPages;
    ZSwapObject ZSwapMaxPoolPercent;
    ZSwapObject ZSwapCompressor;
    ZSwapObject ZSwapZpool;
    ZSwapObject ZSwapAcceptThrehsoldPercent;
private:
    void WriteLogEntry(std::string const&, std::string const&, std::string const&);
    void WriteZSwapValue(ZSwapObject&, std::string const&);
    bool CheckIfRunningBySuperUser();
    void ExecuteEnv();
    void ExecuteCmdLine(cxxopts::ParseResult const&);
};

#endif // APPLICATION_H
