#pragma once
#include <cstdlib> 
#include <ctime> 

using namespace std;

template<class T>
class Cerditos
{
private:
	T edad;
	T altura;
	float temperatura;
	int codigoID;
public:
	Cerditos() {		
		edad = (rand() % 16);
		altura = ((rand() % 150 + 50) / 100.0f);
		temperatura= (rand() % 500 + 3600) / 100.0f;
		codigoID= 0;
	};
	~Cerditos() {};
	void setCodigoID(int n) {
		codigoID = n;
	}
	int getCodigoID() {
		return codigoID;
	}
	int getEdad() {
		return edad;
	}
	void MostrarDatosCerdo(int i) {
		cout << "+++++++++++++  Cerdito NRO " << i + 1 << "  +++++++++++++++++"<<endl;
		cout << "Edad: " << edad << " anos" << endl; 
		cout << "Altura: " << altura << " metros" << endl;
		cout << "Temperatura: " << temperatura << " grados Celsius" << endl;
		cout << "Codigo ID: " << codigoID << endl;
		cout << endl<<endl;
	}
};
