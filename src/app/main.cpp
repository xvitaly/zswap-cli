/**
 * SPDX-FileCopyrightText: 2020-2024 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <boost/program_options.hpp>

#include "application/application.hpp"

/**
 * The main entry point.
 * @param argc Command-line arguments count.
 * @param argv Command-line arguments array.
*/
int main(int argc, char** argv)
{
    try
    {
        return std::make_unique<Application>(argc, argv) -> Run();
    }
    catch (boost::program_options::required_option& e)
    {
        std::cerr << "Missing command-line argument: " << e.what() << std::endl;
    }
    catch (boost::program_options::error& e)
    {
        std::cerr << "Command-line argument error: " << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "An error occured: " << e.what() << std::endl;
    }
    return 1;
}
