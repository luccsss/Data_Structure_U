#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Alumno
{
public:
	string nombre;
	int edad;
	int nota;
	Alumno() {
	}
	string toString() {
		ostringstream s;
		s << "Nombre:\t" << nombre << endl
			<< "Edad:\t" << edad << endl
			<< "Nota:\t" << nota << endl;
		return s.str();
	}
};

