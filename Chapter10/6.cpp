#include <iostream>

using namespace std;

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int &retSize) {
    T *arr = new T [sizeSrc];

    bool toggle = true;
    for (int i = 0; i < sizeSrc; ++i) {
        for (int j = 0; j < sizeMinus; ++j) {
            if (src[i] == minus[j]) {
                toggle = false;
                break;
            }
        }

        if (toggle) {
            *arr++ = src[i];
            retSize++;
        }
        else
            toggle = true;
    }

    return arr - retSize;
}

int main() {
    int x[] = {1, 10, 100, 5, 4};
    int y[] = {10, 2, 11, 4, 62};

    int retSize = 0;
    int *arr = remove(x, 5, y, 5, retSize);
    for (int i = 0; i < retSize; ++i)
        cout << arr[i] << ' ';
}
