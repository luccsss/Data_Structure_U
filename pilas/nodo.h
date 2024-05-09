#pragma once

template<class T>
class Nodo {
public:
    T valor;
    Nodo<T>* anterior;
    Nodo<T>* siguiente;

    Nodo(T valor, Nodo<T>* anterior = nullptr, Nodo<T>* siguiente = nullptr) {
        this->valor = valor;
        this->anterior = anterior;
        this->siguiente = siguiente;
    }
};
