#pragma once
#include <iostream>
#include <exception>
#include <string>
#include "LogController.h"
#include "../termcolor.hpp"


class InvalidMenuNumber : public std::exception
{
public:
    explicit InvalidMenuNumber(const std::string& str) : msg(str)
    {
        LogController::LOG(msg, LogController::Warning);
        std::cout << termcolor::yellow << "Warning: " << msg << termcolor::reset << "\n";
    }

    const char* what() const noexcept override { return msg.c_str(); }

private:
    std::string msg;
};

class IncorrectInput : public std::exception
{
public:
    explicit IncorrectInput(const std::string& str) : msg(str)
    {
        LogController::LOG(msg, LogController::Warning);
        std::cout << termcolor::yellow << "Warning: " << msg << termcolor::reset << "\n";
    }

    const char* what() const noexcept override { return msg.c_str(); }

private:
    std::string msg;
};

class IncorrectCoefficents : public std::exception
{
public:
    explicit IncorrectCoefficents(const std::string& str) : msg(str)
    {        LogController::LOG(msg, LogController::Error);

        std::cout << termcolor::red << "Error: " << msg << termcolor::reset << "\n";
    }

    const char* what() const noexcept override { return msg.c_str(); }

private:
    std::string msg;
};
