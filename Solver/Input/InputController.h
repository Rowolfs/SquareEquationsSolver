#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include "../ErrorHandler/exceptions.hpp"


class InputController
{
    static float stringToNumber(const std::string& s)
    {
        std::istringstream iss(s);
        float number;
        if (!(iss >> number))
        {
            throw IncorrectInput("This not digit");
        }
        return number;
    }

public:
    static std::vector<float> get_coffs()
    {
        LogController::LOG("Input coefficients init");
        std::cout << "Type coefficients like in order (from adult degree to young)" << std::endl;
        std::vector<float> coffs;
        std::string input;
        std::getline(std::cin, input);
        input += ' ';
        std::string temp;
        for (auto value : input)
        {
            if (value != ' ')
            {
                temp += value;
            }
            else
            {
                float coff = stringToNumber(temp);
                temp = "";
                coffs.push_back(coff);
            }
        }
        return coffs;
    }

    static int get_int()
    {
        LogController::LOG("Input int init");
        int number;
        if (!(std::cin >> number))
        {
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            throw IncorrectInput("It is not digit");
        }
        return number;
    }
};
