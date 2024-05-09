#include <iostream>
using namespace std;
// Función recursiva para calcular el factorial
long long factorial( int n) {
    // Caso base: factorial de 0 es 1
    if (n == 0) {
        return 1;
    }
    // Caso recursivo: n * factorial(n-1)
    return n * factorial(n - 1);
}

int main() {
    int num;

    cout << "Ingrese un número entero no negativo: ";
    cin >> num;

    if (num < 0) {
        cout << "El número debe ser no negativo." << endl;
    } else {
         long long fact = factorial(num);
        cout << "El factorial de " << num << " es: " << fact << endl;
    }

    return 0;
}
