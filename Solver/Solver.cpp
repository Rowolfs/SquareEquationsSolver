#include <vector>
#include "Interface/Interface.h"
#include "Input/InputController.h"

using namespace std;


int main(int argc, char* argv[])
{
    Interface inter;
    LogController::begin();
    inter.start();
    inter.instruction();
    while (true)
    {
        Menu menu = inter.menu();


        try
        {
            int point = InputController::get_int();
            if (point == menu.actions.size())
            {
                menu.exit_program();
            }
            vector<float> answer = menu.execute(point);
            inter.print_answer(answer);
        }
        catch (...)
        {
        }
    }
}
