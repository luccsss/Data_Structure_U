#pragma once
#include <iostream>
template <typename T>

struct Nodo1 {
    Nodo1<T>* next;
    T elemento;
    Nodo1(T e) {
        elemento = e;
        next = nullptr;
    }
};

template <class T>
class ListaSimple {
    Nodo1<T>* head;
    size_t size;
public:
    ListaSimple() { head = nullptr; size = 0; }

    void push_frontV1(T e) {
        //caso 0
        if (head == nullptr) {
            Nodo1<T>* _new = new Nodo1<T>(e);
            head = _new;
            ++size;
        }

        //caso 1
        else if (head->next == nullptr) {
            Nodo1<T>* _new = new Nodo1<T>(e);
            _new->next = head;
            head = _new;
        }

        //caso n
        else {
            Nodo1<T>* _new = new Nodo1<T>(e);
            _new->next = head;
            head = _new;
        }
    }

    void push_front(T e) {
        Nodo1<T>* _new = new Nodo1<T>(e);
        if (head != nullptr)
            _new->next = head;
        head = _new;
        ++size;
    }

    void print() {
        Nodo1<T>* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->elemento << " ";
            tmp = tmp->next;
        }
    }
    size_t getLongitud() { return size; }

    Nodo1<T>* getNodoEnPosicion(int posicion) {
        if (posicion >= 0 && posicion < size) {
            Nodo1<T>* auxiliar = head;
            for (int i = 0; i < posicion; i++) auxiliar = auxiliar->next; 
            return auxiliar;
        }
        else throw "Posición fuera de rango";
    }
};
