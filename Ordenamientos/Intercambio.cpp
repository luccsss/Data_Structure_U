//Su complejidad es ser O(n^2) en el mejor y peor de los casos
#include <iostream>

using namespace std;
using namespace System;

void intercambio(int* arreglo, int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if(arreglo[j]<arreglo[i]) {
				int aux = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = aux;
			}
		}
	}
}

int main() {

	int n = 9;
	int* arreglo = new int[n] { 4, 6, 1, 7, 3, 9, 8, 2, 5 };
	intercambio(arreglo, n);
	for (int i = 0; i < n; i++) {
		cout << arreglo[i] << " ";
	}
	cin.ignore();
	cin.get();
	return 0;
}
