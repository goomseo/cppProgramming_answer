// 제공되는 답안을 다듬었음.
#include <iostream>
using namespace std;

class BaseMemory {
    char *mem;
    int size;
protected:
    BaseMemory(int size);

    void burn(char *mem, int address, int size);
public:
    char read(int address) {return mem[address];}
};

BaseMemory::BaseMemory(int size)  {
    mem = new char [size];
    this -> size = size;
}

void BaseMemory::burn(char *mem, int address, int size)  {
    if (address + size > this -> size)
        return;
    for (int i = 0; i < size; ++i)
        this -> mem[address + i] = mem[i];
}

class ROM : public BaseMemory {
public:
    ROM(int size, char* initData, int initSize);
};

ROM::ROM(int size, char* initData, int initSize) : BaseMemory(size) {
    burn(initData, 0, initSize);
}

class RAM : public BaseMemory {
public:
    RAM(int size);
    void write(int address, char data);
};

RAM::RAM(int size) : BaseMemory(size) { }

void RAM::write(int address, char data) {
    burn(&data, address, 1);
}

int main() {
    char x[5]={'h', 'e', 'l', 'l', 'o'};
    ROM biosROM(1024 * 10, x, 5);
    RAM mainMemory(1024 * 1024);

    for(int i = 0; i < 5; ++i)
        mainMemory.write(i, biosROM.read(i));

    for(int i = 0; i < 5; ++i)
        cout << mainMemory.read(i);
}
