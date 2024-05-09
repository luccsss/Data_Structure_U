#include <vector>
#include <functional>
#include <cstdint>
#include "Nodo.h"


template<class T>
class ListaDoblementeEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    size_t longitud;
public:
    ListaDoblementeEnlazada() : cabeza(nullptr), cola(nullptr), longitud(0) {}

    ~ListaDoblementeEnlazada() {
        if (cabeza != nullptr) {
            Nodo<T>* temporal = cabeza;
            Nodo<T>* siguiente;
            do {
                siguiente = temporal->siguiente;
                delete temporal;
                temporal = siguiente;
            } while (temporal != cabeza);
        }
    }

    void limpiarLista() {
        while (cabeza != nullptr) {
            Nodo<T>* temporal = cabeza;
            cabeza = cabeza->siguiente;
            delete temporal;
        }
        cola = nullptr;
        longitud = 0;
    }

    void insertarFinal(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);

        if (cabeza == nullptr) {
            cabeza = cola = nuevoNodo;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        }
        else {
            nuevoNodo->anterior = cola;
            nuevoNodo->siguiente = cabeza;

            cola->siguiente = nuevoNodo;
            cabeza->anterior = nuevoNodo;
            cola = nuevoNodo;
        }
        longitud++;
    }

    bool estaVacia() { return longitud == 0; }
    size_t getLongitud() { return longitud; }


    Nodo<T>* getNodoEnPosicion(int posicion) {
        if (posicion >= 0 && posicion < longitud) {
            Nodo<T>* auxiliar = cabeza;
            for (int i = 0; i < posicion; i++) auxiliar = auxiliar->siguiente;
            return auxiliar;
        }
        else throw "Posición fuera de rango";
    }

    void ordenamientoBurbuja(int posicion) {
        if (posicion < 0 || posicion >= longitud - 1) throw "Posición fuera de rango";

        Nodo<T>* nodo1 = cabeza;
        for (int i = 0; i < posicion; i++) nodo1 = nodo1->siguiente;
        Nodo<T>* nodo2 = nodo1->siguiente;

        swap(nodo1->valor, nodo2->valor);
    }

   
    Nodo<Usuario*>* particion(Nodo<Usuario*>* inicio, Nodo<Usuario*>* fin) {
        int pivote = fin->valor->getIdentificador();
        Nodo<Usuario*>* posicionMenor = inicio->anterior;

        for (Nodo<Usuario*>* i = inicio; i != fin; i = i->siguiente) {
            if (i->valor->getIdentificador() <= pivote) {
                posicionMenor = (posicionMenor == nullptr) ? cabeza : posicionMenor->siguiente;
                swap(posicionMenor->valor, i->valor);
            }
        }
        posicionMenor = (posicionMenor == nullptr) ? cabeza : posicionMenor->siguiente;
        swap(posicionMenor->valor, fin->valor);
        return posicionMenor;
    }

    Usuario* quickselect(Nodo<Usuario*>* inicio, Nodo<Usuario*>* fin, int posicionBuscada) {
        if (inicio == fin) return inicio->valor;

        Nodo<Usuario*>* nodoPivote = particion(inicio, fin);

        int longitudIzquierda = 0;
        Nodo<Usuario*>* temp = inicio;
        while (temp != nodoPivote) {
            longitudIzquierda++;
            temp = temp->siguiente;
        }

        if (longitudIzquierda == posicionBuscada) return nodoPivote->valor;
        if (longitudIzquierda > posicionBuscada) return quickselect(inicio, nodoPivote->anterior, posicionBuscada);
        return quickselect(nodoPivote->siguiente, fin, posicionBuscada - longitudIzquierda - 1);
    }

    Usuario* ordenamientoQuickselect(int posicionBuscada) {
        if (posicionBuscada < 0 || posicionBuscada >= longitud) throw "Índice fuera de rango";
        return quickselect(cabeza, cola, posicionBuscada);
    }

    void Merge(vector<int>& A1, vector<int>& A2, vector<int>& A, int n) {
        int i = 0, j = 0, k = 0;
        int mitad = n / 2;
        while (i < mitad && j < n - mitad) {
            if (A1[i] < A2[j]) {
                A[k] = A1[i];
                i++; k++;
            }
            else {
                A[k] = A2[j];
                j++; k++;
            }
        }
        while (i < mitad) {
            A[k] = A1[i];
            i++; k++;
        }
        while (j < n - mitad) {
            A[k] = A2[j];
            j++; k++;
        }
    }

    void mergeSort(vector<int>& A, int n) {
        if (n > 1) {
            int mitad = n / 2;
            vector<int> A1(A.begin(), A.begin() + mitad);
            vector<int> A2(A.begin() + mitad, A.end());

            mergeSort(A1, mitad);
            mergeSort(A2, n - mitad);
            Merge(A1, A2, A, mitad + n - mitad);
        }
    }
};
