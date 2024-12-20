#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <functional> 

class Utils
{
public: 
    static std::string GetTimeNow();
    static void PauseTerminal();
    static std::string GenerateId(std::string const & str1, std::string const & str2);
    static std::string GetInput();
    static int SafeStringToInt(const std::string& str);
};