#include <iostream>
using namespace std;

template<typename T>
T suma(T a, T b) {
  return a + b;
}

int main() {
  double x = 10.5, y = 20.75;
  printf("Entero: %d\n", suma<int>(x, y));
  printf(" Float: %f\n", suma<float>(x, y));
  printf("Double: %lf\n", suma<double>(x, y));
  return 0;
}
