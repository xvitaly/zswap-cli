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

/** @file application/application.hpp
 *  This file is a part of zswap-cli application.
 */

#include <iostream>
#include <cxxopts.hpp>
#include <fmt/format.h>

#include "cwrappers/cwrappers.hpp"
#include "zswapobject/zswapobject.hpp"
#include "zswapdebug/zswapdebug.hpp"
#include "ksysinfo/ksysinfo.hpp"

/**
 *  Main class of application.
*/
class Application
{
public:
    /**
     *  Default constructor of the Application class.
    */
    Application() = default;

    /**
     *  Runs an application and return exit code.
     * @param CmdLine Instance of command-line arguments parser.
     * @returns Exit code.
    */
    int Run(const cxxopts::ParseResult&);
private:
    /**
     *  Stores an instance of ZSwapObject class.
    */
    ZSwapObject ZSwap;

    /**
     *  Checks of current application is running with super-user
     * privileges.
     * @returns Check results.
     * @retval true No super-user privileges were detected.
     * @retval false Otherwise.
    */
    bool CheckIfRunningBySuperUser();

    /**
     *  Gets parameters from environment variables.
    */
    void ExecuteEnv();

    /**
     *  Gets parameters from command-line arguments.
     * @param CmdLine Instance of command-line arguments parser.
    */
    void ExecuteCmdLine(const cxxopts::ParseResult&);

    /**
     *  Prints ZSwap kernel module debug information.
    */
    void PrintDebugInfo();

    /**
     *  Prints ZSwap kernel module current settings.
    */
    void PrintSettings();

    /**
     *  Prints ZSwap kernel module usage summary.
    */
    void PrintSummary();

    /**
     *  Prints all available information about ZSwap kernel module.
    */
    void PrintCombined();

    /**
     *  Handles \-\-stats command-line argument. Prints requested by
     * user diagnostic information about ZSwap kernel module.
     * @param Value Request code: 0 - all; 1 - settings; 2 - usage stats;
     * 3 - debug.
     * @returns Exit code.
    */
    int PrintStats(int);
};

#endif // APPLICATION_H
