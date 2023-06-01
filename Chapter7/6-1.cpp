#include <iostream>

using namespace std;

class Matrix {
private:
    int arr[4];
public:
    Matrix();
    Matrix(int a, int b, int c, int d);

    Matrix operator+(Matrix op2);
    Matrix &operator+=(Matrix op2);
    bool operator==(Matrix op2);

    void show();
};

Matrix::Matrix() {
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;
}

Matrix::Matrix(int a, int b, int c, int d) {
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
}

Matrix Matrix::operator+(Matrix op2) {
    Matrix tmp;

    for (int i = 0; i < 4; ++i)
        tmp.arr[i] = arr[i] + op2.arr[i];

    return tmp;
}

Matrix &Matrix::operator+=(Matrix op2) {
    for (int i = 0; i < 4; ++i)
        arr[i] += op2.arr[i];

    return *this;
}

bool Matrix::operator==(Matrix op2) {
    for (int i = 0; i < 4; ++i)
        if (arr[i] != op2.arr[i])
            return false;

    return true;
}

void Matrix::show() {
    cout << "Matrix = { ";
    for (int i = 0; i < 4; ++i)
        cout << arr[i] << ' ';
    cout << "}" << endl;
}

int main() {
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b;
    a += b;
    a.show(); b.show(); c.show();

    if (a == c)
        cout << "a and c are the same" << endl;
}