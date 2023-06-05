#include <iostream>

using namespace std;

class Matrix {
private:
    int arr[4]{};
public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0);

    friend int* operator>>(Matrix op1, int *op2);
    friend Matrix operator<<(Matrix &op1, int *op2);

    void show();
};

Matrix::Matrix(int a, int b, int c, int d) {
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
}

int* operator>>(Matrix op1, int *op2) {
    for (int i = 0; i < 4; ++i)
        op2[i] = op1.arr[i];

    return op2;
}

Matrix operator<<(Matrix &op1, int *op2) {
    for (int i = 0; i < 4; ++i)
        op1.arr[i] = op2[i];
    
    return op1;
}

void Matrix::show() {
    cout << "Matrix = { ";
    for (int i = 0; i < 4; ++i)
        cout << arr[i] << ' ';
    cout << "}" << endl;
}

int main() {
    Matrix a(4, 3, 2, 1), b;
    int x[4], y[4] = {1, 2, 3, 4};
    a >> x;
    b << y;

    for (int i = 0; i < 4; ++i)
        cout << x[i] << ' ';
    cout << endl;

    b.show();
}