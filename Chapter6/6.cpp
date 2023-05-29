#include<iostream>

using namespace std;

class ArrayUtility2{
public:
    static int* concat(int s1[], int s2[], int size);
    static int* remove(int s1[], int s2[], int size, int& newSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
    int* arr = new int [size];
    for (int i = 0; i < size / 2; ++i)
        arr[i] = s1[i];

    for (int i = 0; i < size / 2; ++i)
        arr[i + 5] = s2[i];

    return arr;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& newSize) {
    int* arr = new int [size / 2];

    bool onlyInS1 = true;
    for (int i = 0; i < size / 2; ++i) {
        for (int j = 0; j < size / 2; ++j) {
            if (s2[j] == s1[i]) {
                onlyInS1 = false;
                break;
            }
        }

        if (onlyInS1) {
            *(arr) = s1[i];
            arr++;
            newSize++;
        }
        else
            onlyInS1 = true;
    }

    if (newSize == 0)
        return nullptr;

    return arr;
}

int main() {
    int x[5], y[5];
    int newSize = 0;

    cout << "정수 5 개 입력하라. 배열 x에 삽입한다>> ";
    for (int i = 0; i < 5; ++i)
        cin >> x[i];

    cout << "정수 5 개 입력하라. 배열 y에 삽입한다>> ";
    for (int i = 0; i < 5; ++i)
        cin >> y[i];

    int *p1 = ArrayUtility2::concat(x,y,10);
    cout << "합친 정수 배열을 출력한다" << endl;
    for (int i = 0; i < 10; ++i)
        cout << p1[i] << ' ';

    int *p2 = ArrayUtility2::remove(x, y, 10, newSize);
    cout << endl << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << newSize << endl;
    for (int i = 0; i < newSize; ++i)
        cout << p2[i] << ' ';
}