#pragma once
#include<iostream>
#include "Menu.h"
#include "../termcolor.hpp"
#include "../ErrorHandler/LogController.h"

using namespace std;

class Interface
{
public:
    void start();
    void instruction();
    Menu menu();
    static void print_answer(vector<float> answer);
};
