#ifndef __ARBOLBB_HPP__
#define __ARBOLBB_HPP__
#include <functional>
using namespace std;

template<class T>
class Nodo {
public:
	T elemento;
	Nodo* izq;
	Nodo* der;
};

template<class T>
class ArbolBB {
	//Función lambda: Función de comparación
	typedef function<int(T, T)> Comp;
	//puntero a función
	void(*procesar)(T);
	Nodo<T>* raiz;
	Comp comparar;

private:
	bool _buscar(Nodo<T> *nodo, T e) {
		if (nodo == nullptr) return false;
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0)return true;
			else if (r < 0) {
				return _buscar(nodo->der, e);
			}
			else {
				return _buscar(nodo->izq, e);
			}
		}
	}
	bool _insertar(Nodo<T> *&nodo, T e) {
		if (nodo == nullptr) {
			nodo = new Nodo<T>();
			nodo->elemento = e;
			return true;
		}
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0)return false; //no se acepta nodos con elemento igual
			else if (r < 0) {
				return _insertar(nodo->der, e);
			}
			else {
				return _insertar(nodo->izq, e);
			}
		}
	}
	void _enOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_enOrden(nodo->izq);
		procesar(nodo->elemento);
		_enOrden(nodo->der);
	}
	void _preOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		procesar(nodo->elemento);
		_preOrden(nodo->izq);
		_preOrden(nodo->der);
	}
	void _postOrden(Nodo<T>* nodo) {
		if (nodo == nullptr)return;
		_postOrden(nodo->izq);
		_postOrden(nodo->der);
		procesar(nodo->elemento);
	}
public:
	ArbolBB(void(*nuevoProcesar)(T)) {
		this->procesar = nuevoProcesar;
		this->comparar = [](T a, T b)->int {return a - b;};
		this->raiz = nullptr;
	}
	bool Buscar(T e) {
		return _buscar(raiz, e);
	}
	bool Insertar(T e) {
		return _insertar(raiz, e);
	}
	void EnOrden() {
		_enOrden(raiz);
	}
	void PreOrden() {
		_preOrden(raiz);
	}
	void PostOrden() {
		_postOrden(raiz);
	}
};

#endif // !__ARBOLBB_HPP__

