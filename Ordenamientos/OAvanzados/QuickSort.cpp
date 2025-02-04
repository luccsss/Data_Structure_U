//Su complejidad es generalmente lineal, pero puede llegar a ser cuadrática en el peor de los casos.
//#Ejemplo 1
//Complejidad lineal:

#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

int particion(int* A, int p, int r) {
	int x = A[r]; //el pivote
	int i = p - 1; //indice de los menores
	for (int j = p; j < r; j++) {
		if (A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quicksort(int* A, int p, int r) {
	int q; //para almacenar el indice del pivote

	if (p < r) {
		q = particion(A, p, r); //devuelve el indice del pivote
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

int main()
{
	//int a[] = {10, 5, 2, 6, 8, 9, 1, 3};
	int *a = new int[8]{10, 5, 2, 6, 8, 9, 1, 3};
	int n = 8;
	quicksort(a, 0,n-1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	delete[] a;
	system("pause");
	return 0;
}
