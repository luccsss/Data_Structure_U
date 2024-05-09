#include <iostream>
#include <functional>

using namespace std;

int main() {
	int x1 = 1; 
	int y1 = 2;

	//Caso 7: anidando funciones lambdas
	int duplicado = [](int x) {
		return [](int y) {return y * 2; }(x) * 2;
	}(5);
	cout << "\t\t" << duplicado << endl; //imprime 20


	//Caso 8: funciones lambdas orden superior
	//-> explica el returno del lambda;
	auto add2intg = [](int x)-> function<int(int)> {
		return [=](int y) {return x + y; };
	};
	auto altoOrden = [](const function<int(int)>& f, int z) {
		return f(z) * 2;
	};
	auto rpta = altoOrden(add2intg(7), 8);
	cout << "\t\t" << rpta << endl; //imprime (7+8)*2=30

	cin.ignore();
	cin.get();
	return 0;
}
