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
    NamedCircle();
    NamedCircle(int radius, string name);
    void set();
    void show() {cout << "반지름이 " << getRadius() << "인 " << name << endl;}
    string getName() {return name;}
};

NamedCircle::NamedCircle() : Circle() {
    this -> name = "";
}

NamedCircle::NamedCircle(int radius, string name) : Circle(radius) {
    this -> name = name;
}

void NamedCircle::set() {
    int radius;
    string name;
    cin >> radius >> name;
    setRadius(radius);
    this -> name = name;
}

int main() {
    NamedCircle pizza[5];

    int max = 0;
    cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ">> ";
        pizza[i].set();

        if (pizza[i].getArea() >= pizza[max].getArea())
            max = i;
    }

    cout << "가장 면적이 큰 피자는 " << pizza[max].getName() << "입니다";
}
