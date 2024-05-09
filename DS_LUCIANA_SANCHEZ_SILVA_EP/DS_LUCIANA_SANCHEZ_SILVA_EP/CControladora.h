#pragma once
#include <vector>
#include <iostream>
#include "Cerditos.h"
#include "ListaSimple.h"
#include "Cola.h"

using namespace std;

class Ccontroladora
{
private:
	ListaSimple<Cerditos<float>*>* objetoListaSimpleCerditos;
	//Cola<Cerditos<float>*>* objetoColaCerditos;
	Cola<int>* objetoColaCerditos;

public:
	Ccontroladora() {
		objetoListaSimpleCerditos = new ListaSimple<Cerditos<float>*>;
		objetoColaCerditos = new Cola<int>;

	};
	~Ccontroladora() {
		delete objetoListaSimpleCerditos;
		delete objetoColaCerditos;
	};

	void GenerarCerditos(int cant, int i) { //FUNCION RECURSIVA
		if (i < cant) {
			Cerditos<float>* nuevoCerdito = new Cerditos<float>();
			nuevoCerdito->setCodigoID(cant - i);
			objetoListaSimpleCerditos->push_front(nuevoCerdito);
			objetoColaCerditos->enqueue(nuevoCerdito->getEdad());
			GenerarCerditos(cant, i + 1);
		}		
	}
	void mostrarCerditos(int cant, int i) { //FUNCION RECURSIVA
		if (i < cant) {
			objetoListaSimpleCerditos->getNodoEnPosicion(i)->elemento->MostrarDatosCerdo(i);
			mostrarCerditos(cant, i+1);
		}
	}
	void ordenarCerditos() {
		ListaSimple<Cerditos<float>*> lista = *objetoListaSimpleCerditos;
		for (int i = 1; i < lista.getLongitud(); ++i) {
			Cerditos<float>* aux = lista.getNodoEnPosicion(i)->elemento;
			int j = i - 1;
			while (j >= 0 && lista.getNodoEnPosicion(j)->elemento->getEdad() > aux->getEdad()) {
				lista.getNodoEnPosicion(j + 1)->elemento = lista.getNodoEnPosicion(j)->elemento;
				--j;
			}
			lista.getNodoEnPosicion(j + 1)->elemento = aux;
		}
	}
	
};
