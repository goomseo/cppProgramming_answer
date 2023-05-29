#include <iostream>

using namespace std;

class Book {
    string title;
    int price, pages;
public:
    Book(string title = "", int price = 0, int pages = 0);

    void show() {cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;}
    string getTitle() {return title;}

    bool operator ==(int price2);
    bool operator ==(string title2);
    bool operator ==(Book book2);
};

Book::Book(string title, int price, int pages) {
    this -> title = title;
    this -> price = price;
    this -> pages = pages;
}

bool Book::operator ==(int price2) {
    if (price == price2)
        return true;

    return false;
}

bool Book::operator ==(string title2) {
    if (title == title2)
        return true;

    return false;
}

bool Book::operator==(Book book2) {
    if (price == book2.price and title == book2.title)
        return true;

    return false;
}

int main() {
    Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
    if (a == 30000)
        cout << "정가 30000원" << endl;
    if (a == "명품 C++")
        cout << "명품 C++입니다." << endl;
    if (a == b)
        cout << "두 책이 같은 책입니다." << endl;
}