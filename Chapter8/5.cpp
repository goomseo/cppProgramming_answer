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

class MyQueue : public BaseArray {
private:
    int index, size;
public:
    MyQueue(int capacity);

    void enqueue(int n);
    int capacity() {return getCapacity();}
    int length() {return size;}
    int dequeue();
};

MyQueue::MyQueue(int capacity) : BaseArray(capacity) {
    index = 0;
    size = 0;
}

void MyQueue::enqueue(int n) {
    if (capacity() == size) {
        cout << "Queue is full" << endl;
        return;
    }

    put(index++, n);
    size++;
}

int MyQueue::dequeue() {
    if (size == 0) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    size--;
    return get(index - size - 1);
}

int main() {
    MyQueue mQ(100);
    int n;
    cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; ++i) {
        cin >> n;
        mQ.enqueue(n);
    }

    cout << "큐의 용량: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;
    cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
    while (mQ.length() != 0)
        cout << mQ.dequeue() << ' ';
    cout << endl << "큐의 현재 크기: " << mQ.length() << endl;
}
