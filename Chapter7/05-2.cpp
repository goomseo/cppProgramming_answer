#include <iostream>

using namespace std;

class Color {
private:
    int red, green, blue;
public:
    Color();
    Color(int red, int green, int blue);

    friend Color operator +(Color op1, Color op2);
    friend bool operator ==(Color op1, Color op2);

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

Color operator+(Color op1, Color op2) {
    Color tmp;
    tmp.red = op1.red + op2.red;
    tmp.green = op1.green + op2.green;
    tmp.blue = op1.blue + op2.blue;

    return tmp;
}

bool operator==(Color op1, Color op2) {
    if (op1.red == op2.red and op1.green == op2.green and op1.blue == op2.blue)
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