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
#include "zswapdebug/zswapdebug.hpp"

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
    int Run() const;
private:
    /**
     *  Stores an instance of the ZSwapObject class.
    */
    std::unique_ptr<ZSwapObject> ZSwap;

    /**
     *  Stores an instance of the ZSwapDebug class.
    */
    std::unique_ptr<ZSwapDebug> ZSwapDebugger;

    /**
     *  Stores the list of available command-line arguments with
     * their descriptions.
    */
    std::unique_ptr<boost::program_options::options_description> CmdLineOptions;

    /**
     *  Stores the list of available configuration file options with
     * their descriptions.
    */
    std::unique_ptr<boost::program_options::options_description> ConfigOptions;

    /**
     *  Stores the parsed map of the specified command-line arguments.
    */
    std::unique_ptr<boost::program_options::variables_map> CmdLine;

    /**
     *  Stores the parsed map of the specified configuration file.
    */
    std::unique_ptr<boost::program_options::variables_map> Config;

    /**
     *  Initializes private class members.
    */
    void InitClassMembers();

    /**
     *  Initializes the list of available command-line options
     * with their descriptions.
    */
    void InitCmdLineOptions();

    /**
     *  Initializes the list of available configuration file options
     * with their descriptions.
    */
    void InitConfigOptions();

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
    void CheckIfRunningBySuperUser() const;

    /**
     *  Handles \-\-env command-line argument. Gets parameters from
     * the environment variables.
     * @returns Exit code.
    */
    int ExecuteEnv() const;

    /**
     *  Handles \-\-config command-line argument. Gets parameters from
     * the specified configuration file.
     * @param ConfigFile Full path to configuration file.
     * @exception Raises an instance of std::invalid_argument exception
     * if incorrect file path was specified.
     * @returns Exit code.
    */
    int ExecuteConfig(const std::string&) const;

    /**
     *  Gets parameters from command-line arguments.
     * @returns Exit code.
    */
    int ExecuteCmdLine() const;

    /**
     *  Prints ZSwap kernel module debug information.
    */
    void PrintDebugInfo() const;

    /**
     *  Prints ZSwap kernel module current settings.
    */
    void PrintSettings() const;

    /**
     *  Prints ZSwap kernel module usage summary.
    */
    void PrintSummary() const;

    /**
     *  Prints all available information about ZSwap kernel module.
    */
    void PrintCombined() const;

    /**
     *  Handles \-\-stats command-line argument. Prints requested by
     * user diagnostic information about ZSwap kernel module.
     * @param Value Request code: 0 - all; 1 - settings; 2 - usage stats;
     * 3 - debug.
     * @exception Raises an instance of std::invalid_argument exception
     * if incorrect request code was specified.
     * @returns Exit code.
    */
    int PrintStats(int) const;

    /**
     *  Handles \-\-help command-line argument. Prints useful documentation
     * about using this application.
     * @returns Exit code.
    */
    int PrintHelp() const;

    /**
     *  Handles \-\-version command-line argument. Prints version
     * information.
     * @returns Exit code.
    */
    int PrintVersion() const;
};

#endif // APPLICATION_HPP
