#include <iostream>
#include "ArbolBB.hpp"

using namespace std;

void imprimir(int e) {
	cout << e << " ";
}

int main() {
	ArbolBB<int> *objArbolBB = new ArbolBB<int>(imprimir);
	objArbolBB->Insertar(10);
	objArbolBB->Insertar(4);
	objArbolBB->Insertar(15);
	objArbolBB->Insertar(2);
	objArbolBB->Insertar(5);

	cout << "Buscar 15, existe?:" << objArbolBB->Buscar(15) << endl;
	cout << "Buscar 50, existe?:" << objArbolBB->Buscar(50) << endl;

	objArbolBB->EnOrden(); cout << endl;
	objArbolBB->PreOrden(); cout << endl;
	objArbolBB->PostOrden(); cout << endl;

	cin.get();
	return 0;
}
