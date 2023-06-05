#include <iostream>

using namespace std;

class Matrix {
private:
    int arr[4];
public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0);

    friend Matrix operator+(Matrix op1, Matrix op2);
    friend Matrix &operator+=(Matrix &op1, Matrix op2);
    friend bool operator==(Matrix op1, Matrix op2);

    void show();
};

Matrix::Matrix(int a, int b, int c, int d) {
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
}

Matrix operator+(Matrix op1, Matrix op2) {
    Matrix tmp;

    for (int i = 0; i < 4; ++i)
        tmp.arr[i] = op1.arr[i] + op2.arr[i];

    return tmp;
}

Matrix &operator+=(Matrix &op1, Matrix op2) {
    for (int i = 0; i < 4; ++i)
        op1.arr[i] += op2.arr[i];

    return op1;
}

bool operator==(Matrix op1, Matrix op2) {
    for (int i = 0; i < 4; ++i)
        if (op1.arr[i] != op2.arr[i])
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