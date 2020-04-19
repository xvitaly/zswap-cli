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

#include "application/application.hpp"

int main(int argc, char** argv)
{
    // Initializing command-line arguments parser...
    cxxopts::Options options("zswap-cli", "Command-line tool to control ZSwap Linux kernel module.");
    options.add_options()
            ("env", "Get options from environment variables instead of cmdline.", cxxopts::value<bool>()->default_value("false"))
            ("stats", "Get statistics of ZSwap kernel module usage.", cxxopts::value<bool>()->default_value("false"))
            ("settings", "Get current configuration of ZSwap kernel module.", cxxopts::value<bool>()->default_value("false"))
            ("e,enabled", "Enable or disable ZSwap kernel module.", cxxopts::value<std::string>())
            ("s,same_filled_pages_enabled", "Enable or disable memory pages deduplication.", cxxopts::value<std::string>())
            ("p,max_pool_percent", "The maximum percentage of memory that the compressed pool can occupy.", cxxopts::value<std::string>())
            ("c,compressor", "The default comression algorithm.", cxxopts::value<std::string>())
            ("z,zpool", "The kernel's zpool type.", cxxopts::value<std::string>())
            ("a,accept_threhsold_percent", "The threshold at which ZSwap would start accepting pages again after it became full.", cxxopts::value<std::string>())
            ("h,help", "Print this help message and exit.");

    // Workaround to known cxxopts bug #224.
    bool argchk = argc < 2;

    // Parsing command-line arguments...
    cxxopts::ParseResult CmdLine = options.parse(argc, argv);
    if (argchk || CmdLine.count("help")) std::cout << options.help() << std::endl; else return Application().Run(CmdLine);
    return 0;
}
