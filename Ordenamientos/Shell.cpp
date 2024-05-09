//Su complejidad suele ser => n.log_2(n)
#include <iostream>

using namespace std;
using namespace System;

void shellOrden(int* a, int n) {
    int intervalo, j, k;
    for (intervalo = n / 2; intervalo > 0; intervalo = intervalo / 2) { //initially gap = n/2, decreasing by gap /2
        for (j = intervalo; j < n; j++) {
            for (k = j - intervalo; k >= 0; k -= intervalo) {
                if (a[k + intervalo] >= a[k])
                    break;
                else {
                    int temp; 
                    temp = a[k + intervalo];
                    a[k + intervalo] = a[k];
                    a[k] = temp;
                }
            }
        }
    }
}

int main() {

	int n = 9;
	int* arreglo = new int[n] { 4, 6, 1, 7, 3, 9, 8, 2, 5 };
	shellOrden(arreglo, n);
	for (int i = 0; i < n; i++) {
		cout << arreglo[i] << " ";
	}
	cin.ignore();
	cin.get();
	return 0;
}
