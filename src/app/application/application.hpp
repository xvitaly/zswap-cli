/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

/** @file application/application.hpp
 *  This file is a part of zswap-cli application.
 */

#include <memory>
#include <string>

#include <boost/program_options.hpp>

#include "zswapobject/zswapobject.hpp"

/**
 *  Main class of application.
*/
class Application
{
public:
    /**
     *  Main constructor of the Application class.
     * @param argc Command-line arguments count.
     * @param argv Command-line arguments array.
    */
    Application(int, char**);

    /**
     *  Runs an application and return exit code.
     * @returns Exit code.
    */
    int Run();
private:
    /**
     *  Stores an instance of ZSwapObject class.
    */
    std::unique_ptr<ZSwapObject> ZSwap;

    /**
     *  Stores the list of available command-line arguments with
     * their descriptions.
    */
    std::unique_ptr<boost::program_options::options_description> CmdLineOptions;

    /**
     *  Stores the parsed map of the specified command-line arguments.
    */
    std::unique_ptr<boost::program_options::variables_map> CmdLine;

    /**
     *  Initializes private class members.
    */
    void InitClassMembers();

    /**
     *  Initializes the list of available command-line options
     * with full descriptions.
    */
    void InitCmdLineOptions();

    /**
     *  Parses command-line arguments to the map.
     * @param argc Command-line arguments count.
     * @param argv Command-line arguments array.
    */
    void ParseCmdLine(int, char**);

    /**
     *  Checks of current application is running with super-user
     * privileges.
     * @exception Raises an instance of std::runtime_error on missing
     * super-user privileges.
    */
    void CheckIfRunningBySuperUser();

    /**
     *  Handles \-\-env command-line argument. Gets parameters from
     * the environment variables.
     * @returns Exit code.
    */
    int ExecuteEnv();

    /**
     *  Handles \-\-config command-line argument. Gets parameters from
     * the specified configuration file.
     * @param ConfigFile Full path to configuration file.
     * @exception Raises an instance of std::invalid_argument exception
     * if incorrect file path was specified.
     * @returns Exit code.
    */
    int ExecuteConfig(const std::string&);

    /**
     *  Gets parameters from command-line arguments.
     * @returns Exit code.
    */
    int ExecuteCmdLine();

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
     * @exception Raises an instance of std::invalid_argument exception
     * if incorrect request code was specified.
     * @returns Exit code.
    */
    int PrintStats(int);

    /**
     *  Handles \-\-help command-line argument. Prints useful documentation
     * about using this application.
     * @returns Exit code.
    */
    int PrintHelp();

    /**
     *  Handles \-\-version command-line argument. Prints version
     * information.
     * @returns Exit code.
    */
    int PrintVersion();
};

#endif // APPLICATION_HPP
