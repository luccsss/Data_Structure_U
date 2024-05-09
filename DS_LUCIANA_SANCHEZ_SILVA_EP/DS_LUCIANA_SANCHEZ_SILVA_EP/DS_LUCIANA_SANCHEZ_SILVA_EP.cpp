#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <ctime> 

#include "Menu.h"
#include "CControladora.h"

using namespace std;
int main()
{
    srand(time(NULL)); 
    int num;
    int cant = genAlea();
    Ccontroladora* objcontroladora= new Ccontroladora;
    objcontroladora->GenerarCerditos(cant, 0);
    do
    {
        //FUNCION LAMBDA
        auto mylambda=[&]() { return menuSecundario(objcontroladora, cant); };
        num = mylambda();
        _getch();
    } while (num == 0);
    system("pause>0");
    delete objcontroladora;
}
