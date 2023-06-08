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

class ForLoopAdder : public LoopAdder {
public:
    ForLoopAdder(string name = "");
    int calculate();
};

ForLoopAdder::ForLoopAdder(string name) : LoopAdder(name) {}

int ForLoopAdder::calculate() {
    int sum = 0;
    for (int i = getX(); i < getY() + 1; ++i)
        sum += i;

    return sum;
}

int main() {
    ForLoopAdder forLoop("For Loop");
    forLoop.run();
}