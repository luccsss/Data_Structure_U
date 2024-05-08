//Su complejidad suele ser O(n)
#include <iostream>
using namespace std;

void Fisher_yates_Shuffle(int* arreglo, int n) {
	for (int i = n-1; i > 0; i--)
	{
		int j = (rand() % (i + 1));
		swap(arreglo[j], arreglo[i]);
	}
}

int main() {
	int n = 9;
	int* arreglo = new int[n]{ 1,2,3,4,5,6,7,8,9 };

	Fisher_yates_Shuffle(arreglo,n);

	for (int i = 0; i < n; i++) {
		cout << arreglo[i] << " ";
	}
	cin.ignore();
	cin.get();
	return 0;
}
