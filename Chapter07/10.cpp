#include <iostream>

using namespace std;

class Stack {
private:
    int *arr;
    int size;
public:
    Stack();

    bool operator!();
    Stack &operator<<(int component);
    void operator~();
    void operator>>(int &avg);
};

Stack::Stack() {
    arr = new int[100];
    size = 0;
}

bool Stack::operator!() {
    if (size)
        return false;

    return true;
}

Stack &Stack::operator<<(int component) {
    arr[size++] = component;

    return *this;
}

void Stack::operator~() {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

void Stack::operator>>(int &avg) {
    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];

    avg = sum / size;
}

int main() {
    Stack stat;
    if (!stat)
        cout << "현재 통계 데이타가 없습니다." << endl;

    int x[5];
    cout << "5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; ++i)
        cin >> x[i];

    for (int i = 0; i < 5; ++i)
        stat << x[i];
    stat << 100 << 200;
    ~stat;

    int avg;
    stat >> avg;
    cout << "avg = " << avg << endl;
}