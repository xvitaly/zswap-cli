/**
 * SPDX-FileCopyrightText: 2020-2026 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

/**
 * @file main.cpp
 * Contains the main entry point implementation.
*/

#include <exception>
#include <iostream>
#include <memory>

#include <boost/program_options.hpp>

#include "application/application.hpp"
#include "logger/logger.hpp"

/**
 * The main entry point.
 * @param argc Command-line arguments count.
 * @param argv Command-line arguments array.
*/
int main(int argc, char** argv)
{
    try
    {
        return std::make_unique<Application>(argc, argv)->Run();
    }
    catch (const boost::program_options::required_option& e)
    {
        Logger::Error("Missing command-line argument: ", e.what());
    }
    catch (const boost::program_options::error& e)
    {
        Logger::Error("Command-line argument error: ", e.what());
    }
    catch (const std::exception& e)
    {
        Logger::Error("An error occurred: ", e.what());
    }
    return 1;
}
