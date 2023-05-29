#include <iostream>
using namespace std;

class Book {
    string title;
    int price, pages;
public:
    Book(string title = "", int price = 0, int pages = 0);

    void show() {cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;}
    string getTitle() {return title;}

    Book &operator +=(int num);
    Book &operator -=(int num);
};

Book::Book(string title, int price, int pages) {
    this -> title = title;
    this -> price = price;
    this -> pages = pages;
}

Book &Book::operator +=(int num) {
    price += num;

    return *this;
}

Book &Book::operator -=(int num) {
    price -= num;

    return *this;
}

int main() {
    Book a("청춘", 2000, 300), b("미래", 30000, 500);
    a += 500;
    b -= 500;

    a.show();
    b.show();
}