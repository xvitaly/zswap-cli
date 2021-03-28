/**
 * SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef APPLICATION_H
#define APPLICATION_H

/** @file application/application.hpp
 *  This file is a part of zswap-cli application.
 */

#include <iostream>
#include <memory>

#include <boost/program_options.hpp>
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
     *  Main constructor of the Application class.
    */
    Application();

    /**
     *  Runs an application and return exit code.
     * @param CmdLine Instance of command-line arguments parser.
     * @returns Exit code.
    */
    int Run(const boost::program_options::variables_map&);
private:
    /**
     *  Stores an instance of ZSwapObject class.
    */
    std::unique_ptr<ZSwapObject> ZSwap;

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
    void ExecuteCmdLine(const boost::program_options::variables_map&);

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
