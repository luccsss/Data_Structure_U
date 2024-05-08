//Su complejidad es ser O(n^2) en el mejor y peor de los casos
#include <iostream>

using namespace std;
using namespace System;

void burbujaOrdenamiento(int* arreglo, int n) {
	bool ordenado;
	for (int i = 0; i < n-1; i++)
	{
		ordenado = true;
		for (int j = 0; j < n-(i+1); j++)
		{
			if(arreglo[j+1]<arreglo[j]) {
				int aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
				ordenado = false;
			}
		}
		if (ordenado) break;
	}
}

int main() {

	int n = 9;
	int* arreglo = new int[n] { 4, 6, 1, 7, 3, 9, 8, 2, 5 };
	burbujaOrdenamiento(arreglo, n);
	for (int i = 0; i < n; i++) {
		cout << arreglo[i] << " ";
	}
	cin.ignore();
	cin.get();
	return 0;
}
