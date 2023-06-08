#include <iostream>
#include <string>

using namespace std;

class LoopAdder {
    string name;
    int x, y, sum;
    void read();
    void write();
protected:
    LoopAdder(string name = "");

    int getX() {return x;}
    int getY() {return y;}
    virtual int calculate() = 0; // 루프를 돌며 합을 구하는 함수
public:
    void run();
};

LoopAdder::LoopAdder(string name) {
    this -> name = name;
}

void LoopAdder::read() {
    cout << name << ": " << endl;
    cout << "처음 수에서 두 번째 수까지 더합니다. 두 수를 입력하세요>> ";
    cin >> x >> y;
}

void LoopAdder::write() {
    cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

void LoopAdder::run() {
    read();
    sum = calculate();
    write();
}

class WhileLoopAdder : public LoopAdder {
public:
    WhileLoopAdder(string name = "");
    int calculate();
};

WhileLoopAdder::WhileLoopAdder(string name) : LoopAdder(name) {}

int WhileLoopAdder::calculate() {
    int i = getX(), sum = 0;
    while (i <= getY())
        sum += i++;

    return sum;
}

class DoWhileLoopAdder : public LoopAdder {
public:
    DoWhileLoopAdder(string name = "");
    int calculate();
};

DoWhileLoopAdder::DoWhileLoopAdder(string name) : LoopAdder(name) {}

int DoWhileLoopAdder::calculate() {
    int i = getX(), sum = 0;
    do {
        sum += i++;
    } while (i <= getY());

    return sum;
}

int main() {
    WhileLoopAdder whileLoop("While Loop");
    DoWhileLoopAdder doWhileLoop("Do while Loop");

    whileLoop.run();
    doWhileLoop.run();
}