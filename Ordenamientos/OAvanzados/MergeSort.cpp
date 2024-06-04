//Su complejidad generalmente es => nlog(n)
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

void Merge(int* A1, int* A2, int* A, int n) {
	int i = 0, j = 0, k = 0;
	int mitad = n / 2;
	while (i < mitad && j < n - mitad) {
		if (A1[i] < A2[j]) {
			A[k] = A1[i];
			i++; k++;
		}
		else {
			A[k] = A2[j];
			j++; k++;
		}
	}
	while (i < mitad) {
		A[k] = A1[i];
		i++; k++;
	}
	while (j < n - mitad) {
		A[k] = A2[j];
		j++; k++;
	}
}

void mergeSort(int* A, int n) {
	if (n > 1) {
		int mitad = n / 2;
		int* A1 = new int[mitad];
		int* A2 = new int[n - mitad];

		for (int i = 0; i < mitad; i++) {
			A1[i] = A[i];
		}
		for (int i = mitad; i < n; i++) {
			A2[i - mitad] = A[i];
		}
		mergeSort(A1, mitad);
		mergeSort(A2, n - mitad);
		Merge(A1, A2, A, n);
		delete[] A1;
		delete[] A2;
	}
}

int main()
{
	//int a[] = {10, 5, 2, 6, 8, 9, 1, 3};
	int *a = new int[8]{10, 5, 2, 6, 8, 9, 1, 3};
	int n = 8;
	mergeSort(a, n); 
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	delete[] a;
	system("pause");
	return 0;
}
