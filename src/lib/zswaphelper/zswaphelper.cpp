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

#include "zswaphelper/zswaphelper.hpp"

std::string ZSwapHelper::GetName() const
{
    return _Name;
}

std::string ZSwapHelper::GetValue() const
{
    return _Value;
}

void ZSwapHelper::SetValue(const std::string& NewValue)
{
    _Value = NewValue;
    ZSwapWorker::WriteZSwapValue(_Name, _Value);
}

bool ZSwapHelper::Validate(const std::string& CheckValue)
{
    return std::regex_match(CheckValue, _Regex);
}

ZSwapHelper::ZSwapHelper(const std::string& Name, const std::string& Regex)
{
    _Name = Name;
    _Regex = std::regex(Regex);
    _Value = ZSwapWorker::ReadZSwapValue(Name);
}
