#include <iostream>

using namespace std;

template <class T>
void reverseArray(T *arr, int size) {
    T tmp[size];
    for (int i = 0; i < size; ++i)
        tmp[i] = arr[size - i - 1];

    for (int i = 0; i < size; ++i)
        arr[i] = tmp[i];
}

int main() {
    int x[] = {1, 10, 100, 5, 4};
    reverseArray(x, 5);
    for (int i = 0; i < 5; ++i)
        cout << x[i] << ' ';
}
