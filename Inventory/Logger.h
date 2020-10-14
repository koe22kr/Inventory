#pragma once
#include <Windows.h>
#include <string>

class Logger
{
public:
    static void writeLogW(std::wstring msg);
    static void writeLog(std::string msg);
};

