/**
 * SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include "application/application.hpp"

int main(int argc, char** argv)
{
    // Initializing command-line arguments parser...
    boost::program_options::options_description options("Command-line tool to control ZSwap Linux kernel module");
    options.add_options()
        ("env", "Get options from environment variables instead of cmdline.")
        ("help", "Print this help message and exit.")
        ("stats", boost::program_options::value<int>()->implicit_value(0), "Get statistics and current settings of ZSwap kernel module.")
        ("enabled,e", boost::program_options::value<std::string>(), "Enable or disable ZSwap kernel module.")
        ("same_filled_pages_enabled,s", boost::program_options::value<std::string>(), "Get statistics and current settings of ZSwap kernel module.")
        ("max_pool_percent,p", boost::program_options::value<std::string>(), "The maximum percentage of memory that the compressed pool can occupy.")
        ("compressor,c", boost::program_options::value<std::string>(), "The default compression algorithm.")
        ("zpool,z", boost::program_options::value<std::string>(), "The kernel's zpool type.")
        ("accept_threhsold_percent,a", boost::program_options::value<std::string>(), "The threshold at which ZSwap would start accepting pages again after it became full.")
        ;

    // Parsing command-line arguments...
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(options).allow_unregistered().run(), vm);
    boost::program_options::notify(vm);

    // Running application...
    if (argc < 2 || vm.count("help")) options.print(std::cout); else return Application().Run(vm);
    return 0;
}
