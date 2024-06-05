#include <iostream>
using namespace std;

#include "Heap.hpp"

int main() {
	int A[10] = { 16,14,10,8,7,19,3,2,4,1 };
	buildMaxHeap(A, 10);
	//DESORDENADO
	print(A, 10);
	cout << endl;
	heapsortMax(A, 10);
	//MAX HEAPIFY
	print(A, 10);
	cout << endl;
	//MIN HEAPIFY
	buildMinHeap(A, 10);
	heapsortMin(A, 10);
	print(A, 10);
	cin.ignore();
	cin.get();
	return 0;
}
