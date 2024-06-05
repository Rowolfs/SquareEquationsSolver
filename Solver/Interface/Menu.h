#pragma once
#include <vector>
#include <string>
#include "../Input/InputController.h"
#include "../SolverMethods/solverMethods.h"
#include "../ErrorHandler/exceptions.hpp"

class Menu
{
public:
    std::vector<solverMethods::SolverMethod*> actions;
    std::string get_actions_titles();
    std::vector<float> execute(int action_number);
    static void exit_program();
    ~Menu();
};
