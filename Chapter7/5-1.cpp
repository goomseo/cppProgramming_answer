#include <iostream>

using namespace std;

class Color {
private:
    int red, green, blue;
public:
    Color();
    Color(int red, int green, int blue);

    Color operator +(Color op2);
    bool operator ==(Color op2);

    void show() {cout << red << ' ' << green << ' ' << blue << endl;}
};

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

Color::Color(int red, int green, int blue) {
    this -> red = red;
    this -> green = green;
    this -> blue = blue;
}

Color Color::operator+(Color op2) {
    Color tmp;
    tmp.red = red + op2.red;
    tmp.green = green + op2.green;
    tmp.blue = blue + op2.blue;

    return tmp;
}

bool Color::operator==(Color op2) {
    if (red == op2.red and green == op2.green and blue == op2.blue)
        return true;

    return false;
}

int main() {
    Color red(255, 0, 0), blue(0, 0, 255), c;
    c = red + blue;
    c.show();

    Color fuchsia(255, 0, 255);
    if (c == fuchsia)
        cout << "보라색 맞음";
    else
        cout << "보라색 아님";
}