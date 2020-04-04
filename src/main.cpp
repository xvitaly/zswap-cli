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

#include <iostream>
#include <cxxopts.hpp>

#include "application/application.hpp"

int main(int argc, char** argv)
{
    cxxopts::Options options("zswap-cli", "ZSwap command-line utility.");
    options.add_options()
            ("env", "Use environment options instead of cmdline.", cxxopts::value<bool>()->default_value("false"))
            ("e,enabled", "Enable or disable ZSwap module.", cxxopts::value<std::string>())
            ("s,same_filled_pages_enabled", "Enable or disable same filled pages deduplication.", cxxopts::value<std::string>())
            ("p,max_pool_percent", "Max pool percent.", cxxopts::value<std::string>())
            ("c,compressor", "Comression alghorithm.", cxxopts::value<std::string>())
            ("z,zpool", "Zpool type.", cxxopts::value<std::string>())
            ("a,accept_threhsold_percent", "Accept threhsold percent.", cxxopts::value<std::string>());

    if (argc < 2) std::cout << options.help() << std::endl;
    Application App = Application();
    App.Run(options.parse(argc, argv));

    return 0;
}
