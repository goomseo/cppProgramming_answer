#include <iostream>

using namespace std;

class Circle {
private:
    int radius;
public:
    Circle(int radius = 0);

    friend Circle operator+(int op1, Circle op2);

    void show() {cout << "radius = " << radius << " 인 원" << endl;}
};

Circle::Circle(int radius) {
    this -> radius = radius;
}

Circle operator+(int op1, Circle op2) {
    op2.radius += op1;

    return op2;
}

int main() {
    Circle a(5), b(4);

    b = 1 + a;

    a.show();
    b.show();
}