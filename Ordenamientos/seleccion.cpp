//Su complejidad suele ser O(n^2)
// sea el mejor de los casos, casos promedios o el peor
#include <iostream>

using namespace std;
using namespace System;

void seleccion(int* arreglo, int n) {
	int k, menor;
	for (int i = 0; i < n-1; i++)
	{
		k = i;
		menor = arreglo[i];
		for (int j = i+1; j < n; j++)
		{
			if(arreglo[j]<menor) {
				menor = arreglo[j];
				k = j;
			}
		}
		arreglo[k] = arreglo[i];
		arreglo[i] = menor;
	}
}

int main() {

	int n = 9;
	int* arreglo = new int[n] { 4, 6, 1, 7, 3, 9, 8, 2, 5 };
	seleccion(arreglo, n);
	for (int i = 0; i < n; i++) {
		cout << arreglo[i] << " ";
	}
	cin.ignore();
	cin.get();
	return 0;
}
