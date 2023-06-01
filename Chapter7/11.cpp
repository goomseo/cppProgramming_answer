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
    void operator>>(int &component);
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

void Stack::operator>>(int &component) {
    component = arr[--size];
}

int main() {
    Stack stack;
    stack << 3 << 5 << 10;

    while (true) {
        if (!stack)
            break;

        int x;
        stack >> x;

        cout << x << ' ';
    }
    cout << endl;
}