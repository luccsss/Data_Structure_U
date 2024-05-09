//Al eliminar un elemento se elimina el ultimo elemento agregado en la pila
#include "Nodo.h"
using namespace std;

template<class T>
class Pila {
private:
    Nodo<T>* tope;
    size_t longitud;
public:
    Pila() : tope(NULL), longitud(0) {}

    void insertar(T valor) {
        auto estaVacia = [this]() -> bool {
            return tope == nullptr;
            };

        auto insertarEnPilaVacia = [this, &valor]() {
            tope = new Nodo<T>(valor);
            };

        auto insertarEnPilaNoVacia = [this, &valor]() {
            tope = new Nodo<T>(valor, tope);
            };

        if (estaVacia()) insertarEnPilaVacia();
        else insertarEnPilaNoVacia();
        longitud++;
    }

    bool estaVacia() { return this->longitud == 0; }
    size_t getLongitud() { return longitud; }

    Nodo<T>* getNodoEnPosicion(int posicion) const {
        if (posicion < 0 || static_cast<size_t>(posicion) >= longitud) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Nodo<T>* current = tope;
        for (int i = 0; i < posicion; ++i) {
            current = current->siguiente;
        }
        return current;
    }

    ~Pila() {
        while (tope != nullptr) {
            Nodo<T>* temp = tope;
            tope = tope->siguiente;
            delete temp;
        }
    }
};
