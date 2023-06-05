#include <iostream>

using namespace std;

class Circle {
private:
    int radius;
public:
    Circle(int radius = 0);

    int getRadius() {return radius;}
    void setRadius(int radius) {this -> radius = radius;}
    double getArea() {return 3.14 * radius * radius;}
};

Circle::Circle(int radius) {
    this -> radius = radius;
}

class NamedCircle : public Circle {
private:
    string name;
public:
    NamedCircle(int radius, string name);
    void show() {cout << "반지름이 " << getRadius() << "인 " << name << endl;}
};

NamedCircle::NamedCircle(int radius, string name) : Circle(radius) {
    this -> name = name;
}

int main() {
    NamedCircle waffle(3, "waffle");
    waffle.show();
}
