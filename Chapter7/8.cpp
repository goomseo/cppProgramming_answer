#include <iostream>

using namespace std;

class Circle {
private:
    int radius;
public:
    Circle(int radius = 0);

    friend Circle &operator++(Circle &op1);
    friend Circle operator++(Circle &op1, int x);

    void show() {cout << "radius = " << radius << " 인 원" << endl;}
};

Circle::Circle(int radius) {
    this -> radius = radius;
}

Circle &operator++(Circle &op1) {
    op1.radius++;

    return op1;
}

Circle operator++(Circle &op1, int x) {
    Circle tmp = op1;
    op1.radius++;

    return tmp;
}

int main() {
    Circle a(5), b(4);

    ++a;
    b = a++;

    a.show();
    b.show();
}