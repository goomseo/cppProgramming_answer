#include <iostream>

using namespace std;

template <class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
    int newSize = sizea + sizeb;
    T *arr = new T[newSize];
    for (int i = 0; i < sizea; ++i)
        arr[i] = a[i];
    for (int i = 0; i < sizeb; ++i)
        arr[i + sizea] = b[i];

    return arr;
}

int main() {
    int x[] = {1, 10, 100, 5, 4};
    int y[] = {7, 2, 11, 23, 62};

    int *arr = concat(x, 5, y, 5);
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << ' ';
    }
}
