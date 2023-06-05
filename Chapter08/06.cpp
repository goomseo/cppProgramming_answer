#include <iostream>
#include <string>

using namespace std;

class BaseArray {
private:
    int capacity;
    int *mem;
protected:
    BaseArray(int capacity = 100);

    ~BaseArray();

    void put(int index, int val) {mem[index] = val;}
    int get(int index) {return mem[index];}
    int getCapacity() {return capacity;}
};

BaseArray::BaseArray(int capacity) {
    this -> capacity = capacity;
    mem = new int[capacity];
}

BaseArray::~BaseArray() {
    delete [] mem;
}

class MyStack : public BaseArray {
private:
    int index;
public:
    MyStack(int capacity);

    void push(int n);
    int capacity() {return getCapacity();}
    int length() {return index;}
    int pop();
};

MyStack::MyStack(int capacity) : BaseArray(capacity) {
    index = 0;
}

void MyStack::push(int n) {
    if (index == capacity()) {
        cout << "Stack is full" << endl;
        return;
    }

    put(index++, n);
}

int MyStack::pop() {
    if (index == 0) {
        cout << "Stack is empty" << endl;
        return -1;
    }

    return get(--index);
}

int main() {
    MyStack mStack(100);
    int n;
    cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; ++i) {
        cin >> n;
        mStack.push(n);
    }

    cout << "스택의 용량: " << mStack.capacity() << ", 스택 크기: " << mStack.length() << endl;
    cout << "스택의 원소를 팝하여 출력한다>> ";
    while (mStack.length() != 0)
        cout << mStack.pop() << ' ';
    cout << endl << "스택의 현재 크기: " << mStack.length() << endl;
}
