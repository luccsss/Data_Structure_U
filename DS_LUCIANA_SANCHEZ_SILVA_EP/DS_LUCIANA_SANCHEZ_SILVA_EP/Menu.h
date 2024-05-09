#pragma once
#include <iostream>
#include <conio.h>
#include "CControladora.h"

using namespace std;

int genAlea() {
    return (rand() % 298 + 501);
}

void salir() {
    cout << "Saliendo de la granja Cerditos...";
}
short menuPrincipal() {
    system("cls"); 
    short opc = 0;
    cout << "\tBIENVENIDO A LA GRANJA CERDITOS\n";
    cout << "\t\t1.Mostrar animales adquiridos            \n";
    cout << "\t\t2.Ordenar de forma ascendente por edad    \n";
    cout << "\t\t3.Salir                                   \n";
    cout << "\t\tIngrese una opcion: "; cin >> opc;
    return opc;
}

short menuSecundario(Ccontroladora* objControladora, int cant) {
    short opcion;
    do
    {
        opcion = menuPrincipal();
    } while (opcion < 1 || opcion>7);
    system("cls");
    switch (opcion) {
    case 1:
        
        cout << "\n\n\n\n\t\t\tLISTA DE  CERDOS:" << endl << endl;
        objControladora->mostrarCerditos(cant,0);
        break;
    case 2:
        cout << "\n\n\n\n\t\t\tLISTA DE  CERDOS ORDENADOS ASCENDENTEMENTE POR EDAD:" << endl << endl;
        objControladora->ordenarCerditos();
        objControladora->mostrarCerditos(cant, 0);
        break;
    case 3:
        salir();
        return 1;
        break;
    }
    return 0;
}
