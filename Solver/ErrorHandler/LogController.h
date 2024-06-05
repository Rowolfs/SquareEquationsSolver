#pragma once
#include <fstream>
#include <string>
using namespace std;

class LogController
{
    static std::ofstream fout;

public:
    static void begin()
    {
        fout.open("log.log", std::ios::out);
    }

    static void end()
    {
        fout.close();
    }

     enum LogTypes { Display, Warning, Error };

    static void LOG(string message, LogTypes LogType = LogTypes::Display)
    {
        switch (LogType)
        {
        case LogTypes::Error:
            fout << "[ERROR]: " << message << std::endl;
            break;
        case LogTypes::Warning:
            fout << "[WARNING]: " << message << std::endl;
            break;
        default:
            fout << "[DISPLAY]: " << message << std::endl;
            break;
        }
    }

    static void LOG(const char* message, LogTypes LogType = LogTypes::Display)
    {
        switch (LogType)
        {
        case LogTypes::Error:
            fout << "[ERROR]: " << message << std::endl;
            break;
        case LogTypes::Warning:
            fout << "[WARNING]: " << message << std::endl;
            break;
        default:
            fout << "[DISPLAY]: " << message << std::endl;
            break;
        }
    }
};
