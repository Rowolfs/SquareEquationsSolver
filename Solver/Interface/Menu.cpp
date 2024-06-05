#include "Menu.h"


std::string Menu::get_actions_titles()
{
    std::string result;
    for (int i = 0; i < actions.size(); ++i)
    {
        result += std::to_string(i + 1) + ". ";
        result += actions[i]->title + "\n";
    }
    return result;
}

std::vector<float> Menu::execute(int action_number)
{
    if (action_number < 1 || actions.size() - 1 < action_number)
    {
        throw InvalidMenuNumber("Invalid number in menu");
    }
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    while (true)
    {
        try
        {
            std::vector<float> coffs = InputController::get_coffs();
            std::vector<float> answer = actions[action_number - 1]->execute(coffs);
            return answer;
        }
        catch (IncorrectInput&)
        {
            cout << "Your input is incorrect" << endl;
            std::istringstream("3");
        }
    }
}

void Menu::exit_program()
{
    LogController::LOG("Program end");
    LogController::end();
    exit(0);
}

Menu::~Menu()
{
    for (auto element : actions)
    {
        delete element;
    }
    actions.clear();
}
