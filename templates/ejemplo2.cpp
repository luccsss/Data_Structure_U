#include <iostream>
using namespace std;

template<typename T>
T suma(T a, T b) {
  return a + b;
}
template<typename T>
T resta (T a, T b){
    return a-b;
}
template<typename T>
T multiplicacion(T a, T b){
    return a*b;
}

int main() {
  auto x = 105, y = 5;
  printf("suma: %d\n", suma<int>(x, y));
  printf("resta: %d\n", resta<int>(x, y));
  printf("multiplicacion: %d\n", multiplicacion<int>(x, y));
  return 0;
}
