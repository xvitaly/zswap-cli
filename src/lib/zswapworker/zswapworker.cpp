/**
 * SPDX-FileCopyrightText: 2020-2021 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: MIT
*/

#include "zswapworker/zswapworker.hpp"

void ZSwapWorker::WriteZSwapValue(const std::string& Name, const std::string& Value)
{
    std::ofstream ZSwapSysFs("/sys/module/zswap/parameters/" + Name);
    ZSwapSysFs << Value;
    ZSwapSysFs.close();
}

std::string ZSwapWorker::ReadZSwapValue(const std::string& Name)
{
    std::string Result;
    std::ifstream ZSwapSysFs("/sys/module/zswap/parameters/" + Name);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}

long ZSwapWorker::ReadZSwapDebugValue(const std::string& Name)
{
    long Result;
    std::ifstream ZSwapSysFs("/sys/kernel/debug/zswap/" + Name);
    ZSwapSysFs >> Result;
    ZSwapSysFs.close();
    return Result;
}
