#include <iostream>
#include <functional>

using namespace std;

int main() {
	int x1 = 1; 
	int y1 = 2;

	//Caso 1: paso todo por copia
	auto f1 = [=]() {return x1 + y1; };
	cout << "\t\t"<<f1() << endl; //imprime 3

	//Caso 2: paso todo por referencia
	x1 = 2; 
	y1 = 2;
	auto f2 = [&]() {return x1 + y1; };
	cout << "\t\t" << f2() << endl; //imprime 4

	//Caso 3: combinado
	 x1 = 2;  y1 = 3;
	auto f3 = [=,&y1]() {return x1 + y1; };
	cout << "\t\t" << f3() << endl; //imprime 5

	//Caso 4:
	auto f4 = [](int x, int y) {return x + y; };
	cout << "\t\t" << f4(3,3) << endl; //imprime 6

	//Caso 5:
	auto f5 = [](int x) {return x * x; }(6);
	cout << "\t\t" << f5 << endl; //imprime 36

	//Caso 6: asignar lambda a un objeto funcion
	function<int(int, int)> f6 = [](int x, int y) {return x * y; };
	int resultado = f6(5, 4);
	cout << "\t\t" << resultado << endl; //imprime 20

	cin.ignore();
	cin.get();
	return 0;
}
