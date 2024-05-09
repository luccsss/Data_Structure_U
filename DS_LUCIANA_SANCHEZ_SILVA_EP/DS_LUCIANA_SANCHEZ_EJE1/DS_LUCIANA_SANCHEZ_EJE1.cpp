#include <iostream>
#include <string>
using namespace std;
bool esDecreciente(int n) {
    if (n > 9) {
        if (n % 10 < (n % 100) / 10)
            esDecreciente(n/10);
        else
            return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    int n;
    cout << "Ingrese un numero => ";
    cin >> n;
    if (esDecreciente(n)) cout << "RESULTADO: Si, esta ordenado de forma decreciente";
    else cout << "RESULTADO: No esta ordenado de forma decreciente";
    cin.get();
    return 0;
}
