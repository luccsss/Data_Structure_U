//Su complejidad suele ser O(n)
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;
using namespace System;

void Fisher_yates_Shuffle(int* arreglo, int n) {
	Random ra;
	for (int i = n-1; i > 0; i--)
	{
		int j = (rand() % (i + 1));
		swap(arreglo[j], arreglo[i]);
	}
	/*for (int i = 0; i <n-1; i++)
	{
		int j = ra.Next(i,n);
		swap(arreglo[j], arreglo[i]);
	}*/
}

int main() {

	int n = 9;
	int* arreglo = new int[n]{ 1,2,3,4,5,6,7,8,9 };
	srand(time(0));
	do
	{
		Fisher_yates_Shuffle(arreglo, n);
		for (int i = 0; i < n; i++) {
			cout << arreglo[i] << " ";
		}
		cout << endl;
		cin.get();
	} while (true);
	cin.ignore();
	cin.get();
	return 0;
}
