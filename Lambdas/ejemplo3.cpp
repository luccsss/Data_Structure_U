#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void negarTodo(vector<T>& v) {
    // Utilizamos for_each con una lambda para negar cada elemento en el vector
    for_each(v.begin(), v.end(), [](T& n) { n = -n; });
}

template <typename T>
void print_all(const vector<T>& v) {
    // Utilizamos for_each con una lambda para imprimir cada elemento en el vector
    for_each(v.begin(), v.end(), [](const T& n) { cout << n << endl; });
}

int main() {
    vector<int> v;
    v.push_back(34);
    v.push_back(-43);
    v.push_back(56);

    cout << "Antes de negarTodo():" << endl;
    print_all(v);

    negarTodo(v);

    cout << "Después de negarTodo():" << endl;
    print_all(v);

    return 0;
}
