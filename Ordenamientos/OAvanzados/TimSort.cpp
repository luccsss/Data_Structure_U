// Tiene una complejidad de O(nlog (n))
#include <iostream>
#include <vector>
#include <algorithm>

// Define el tamaño mínimo del run
const int MIN_RUN = 32;

// Función para ordenar usando Insertion Sort
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Función para fusionar dos subarrays ordenados
void merge(std::vector<int>& arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    std::vector<int> left(len1);
    std::vector<int> right(len2);

    for (int i = 0; i < len1; ++i) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < len2; ++i) {
        right[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

// Función principal de Timsort
void timSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i += MIN_RUN) {
        insertionSort(arr, i, std::min((i + MIN_RUN - 1), (n - 1)));
    }

    for (int size = MIN_RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = std::min(n - 1, left + size - 1);
            int right = std::min((left + 2 * size - 1), (n - 1));

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

// Función de ayuda para imprimir el array
void printArray(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {5, 21, 7, 23, 0,19, 10, 12, 30, 15, 2, 9, 25};
    std::cout << "Array original: ";
    printArray(arr);
    timSort(arr);
    std::cout << "Array ordenado: ";
    printArray(arr);
    return 0;
}
