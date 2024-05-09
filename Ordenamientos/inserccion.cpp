//Su complejidad es:
//mejor de los casos: O(n)
//Caso promedio: O(n+d) ->d=cant inversiones
//Peor caso: O(n^2)

#include <iostream>

using namespace std;
using namespace System;

void inserccionOrdenamiento(int* arreglo, int n) {
	int k, aux;
	for (int i = 1; i < n; i++)
	{
		aux = arreglo[i];
		k = i-1;
		while (k>=0 && aux< arreglo[k])
		{
			arreglo[k + 1] = arreglo[k]; 
			k--;
		}
		arreglo[k + 1] = aux;
	}
}

int main() {

	int n = 9;
	int* arreglo = new int[n] { 4, 6, 1, 7, 3, 9, 8, 2, 5 };
	inserccionOrdenamiento(arreglo, n); 
	for (int i = 0; i < n; i++) {
		cout << arreglo[i] << " ";
	}
	cin.ignore();
	cin.get();
	return 0;
}
