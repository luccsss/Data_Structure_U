#include "ArbolBB.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Alumno.h"

using namespace std;

void imprimir(Alumno e) {
	cout << e.toString();
}

int main() {
	//ArbolBB<int>* arbol = new ArbolBB<int>(imprimir);
	Alumno alumno1;
	alumno1.nombre = "Juan Perez";
	alumno1.edad = 18;
	alumno1.nota = 18;

	Alumno alumno2;
	alumno2.nombre = "Jose Diaz";
	alumno2.edad = 20;
	alumno2.nota = 15;

	Alumno alumno3;
	alumno3.nombre = "Enrique Gutierrez";
	alumno3.edad = 17;
	alumno3.nota = 7;

	Alumno alumno4;
	alumno4.nombre = "Maria Mendez";
	alumno4.edad = 25;
	alumno4.nota = 19;
	

	ArbolBB<Alumno>* arbol = new ArbolBB<Alumno>(imprimir, [](Alumno a1, Alumno a2) {return a1.nombre.compare(a2.nombre); });
	arbol->insertar(alumno1);
	arbol->insertar(alumno2);
	arbol->insertar(alumno3);
	arbol->insertar(alumno4);
	arbol->enOrden();
	cin.get();
	return 0;
}
int main2() {
	//srand(time(0));
	//ArbolBB<int>* arbol = new ArbolBB<int>(imprimir);
	/*
	for (int i = 0; i < 30; ++i) {
	arbol->insertar(rand() % 100);
	}*/

	//***Pruebas***
	//Ingreso manual
	//Caso 1:
	//arbol->insertar(6);
	//arbol->insertar(16);
	//arbol->insertar(26);
	/*
	//Caso 2:
	arbol->insertar(10);
	arbol->insertar(6);
	arbol->insertar(26);
	arbol->insertar(4);
	arbol->insertar(8);
	arbol->insertar(7);
	arbol->insertar(9);


	cout << "EnOrden";
	arbol->enOrden();
	cout << endl;

	cout << "PreOrden";
	arbol->preOrden();
	cout << endl;

	cout << "PostOrden";
	arbol->postOrden();
	cout << endl;

	cout << "Altura: " << arbol->altura() << endl;
	cout << "Cantidad: " << arbol->cantidad() << endl;

	cout << "Encontrar 26: " << arbol->Buscar(26) << endl;
	cout << "Encontrar 100: " << arbol->Buscar(100) << endl;



	cout << "Minimo: " << arbol->Minimo() << endl;
	cout << "Maximo: " << arbol->Maximo() << endl;

	arbol->Eliminar(6);

	cout << "EnOrden:";
	arbol->enOrden();
	cout << endl;

	cout << "EnPreOrden:";
	arbol->preOrden();
	cout << endl;

	cin.get();
	*/
	return 0;
}
