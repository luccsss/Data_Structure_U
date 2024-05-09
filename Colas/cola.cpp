//Al eliminar un elemento se elimina el primer elemento agregado en la cola
#include "Nodo.h"
#include <iostream>
using namespace std;

template<class T>
class Cola {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
	size_t longitud;

public:
	Cola() : inicio(NULL), fin(NULL), longitud(0) {}

	void enqueue(T valor) {
		Nodo<T>* nuevoNodo = new Nodo<T>(valor);
		if (estaVacia()) {
			inicio = nuevoNodo;
			fin = inicio;
		}
		else {
			fin->siguiente = nuevoNodo;
			fin = nuevoNodo;
		}
		longitud++;
		nuevoNodo = NULL;
	}


	T dequeue() {
		if (estaVacia()) return NULL;
		T dato = inicio->valor;

		if (inicio == fin) {
			delete inicio;
			inicio = NULL;
			fin = NULL;
		}
		else {
			Nodo<T>* aux = inicio;
			inicio = inicio->siguiente;
			delete aux;
		}
		longitud--;
		return dato;
	}

	bool estaVacia() { return this->longitud == 0; }
	size_t getLongitud() { return longitud; }

	Nodo<T>* getNodoEnPosicion(int posicion) {
		if (posicion < 0 || estaVacia()) throw "Posición inválida o cola vacía";

		int contador = 0;
		Nodo<T>* actual = inicio;

		while (actual != NULL) {
			if (contador == posicion) return actual;
			contador++;
			actual = actual->siguiente;
		}
		throw "Posición fuera de rango";
	}
};
