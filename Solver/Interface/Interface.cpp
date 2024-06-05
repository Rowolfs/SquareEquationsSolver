#include "Interface.h"

void Interface::instruction()
{
    LogController::LOG("Show instruction");
    cout<<"Privet drug, eta programma reshaet kvadratnye yravnenia i yravnenia bolshey stepeni"<<endl;
    cout<<"Seichas ty videsh menu:"<<endl;
    cout<<"1. Discremenant - sposob reshenia cvadratnogo uravnenia rabotaet s tremy drobnnymi chislami (coefficentami)"<<endl;
    cout<<"2. Vieta - sposob reshenia cvadratnogo uravnenia rabotaet s tremy celami chislami (coefficentami)"<<endl;
    cout<<"3. Gorner - sposob reshenia uravnenia ot 2 - do n stepeni rabotaet s dvuma i bolle chislami(coefficentami)"<<endl;
    cout<<"4. Exit - vuchod is programmy"<<endl;
    cout<<"Napishite nomer punkta kotory hotite vypolnit"<<endl;
    cout<<"Dallee vedite coefficenty yravnenia"<<endl;
    cout<<"Posle etogo vy polychite otvet ili oshibky v resheni"<<endl;
    cout<<"Oshibka moshet vosniknut esli koefficentu nepravelno vvediny"<<endl;
    cout<<"Priatnogo polsovania programmoy"<<endl;
}


void Interface::start()

{
    LogController::LOG("Init interface");
    cout << "Welcome to EquationsSolver ";
    cout << "This Version:" << termcolor::cyan << " 0.1.0 alpha creek" << endl;
    cout << termcolor::reset << "If you have question contact me: " << termcolor::blue << "ro.volkov2018@yandex.ru" <<
        termcolor::reset << " /:) " << endl;
}


Menu Interface::menu()
{
    Menu menu;
    LogController::LOG("Init menu");
    menu.actions.push_back(new solverMethods::Discriminant());
    menu.actions.push_back(new solverMethods::Vieta());
    menu.actions.push_back(new solverMethods::Gorner());
    // add your solver methods
    menu.actions.push_back(new solverMethods::Exit());
    cout << menu.get_actions_titles();
    return menu;
}

void Interface::print_answer(vector<float> answer)
{
    for (auto element : answer)
    {
        cout << element << " ";
    }
    cout << "\n";
}
