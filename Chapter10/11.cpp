#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title, author;
    int year;
public:
    Book();
    Book(string title, string author, int year);

    void set(string title, string author, int year);
    string getAuthor() {return author;}
    int getYear() {return year;}
    void show() {cout << year << "년도, " << title << ", " << author << endl;}
};

Book::Book() {
    title = "";
    author = "";
    year = 1000;
}

Book::Book(string title, string author, int year) {
    this -> title = title;
    this -> author = author;
    this -> year = year;
}

void Book::set(string title, string author, int year) {
    this -> title = title;
    this -> author = author;
    this -> year = year;
}

class BookManager {
private:
    vector<Book> v;
    void bookIn(), searchByAuthor(), searchByYear();
public:
    void run();
};

void BookManager::bookIn() {
    int year;
    string title, author;
    Book bk;

    cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
    while(true) {
        cout << "년도>> ";
        cin >> year;
        cin.ignore();

        if (year == -1)
            break;

        cout << "책이름>> ";
        getline(cin, title);

        cout << "저자>> ";
        getline(cin, author);

        bk.set(title, author, year);
        v.push_back(bk);
    }

    cout << "총 입고된 책은 " << v.size() << "권입니다." << endl;
}

void BookManager::searchByAuthor() {
    cout << "검색하고자 하는 저자 이름을 입력하세요>> ";
    string author;
    getline(cin, author);

    for(int i = 0; i < v.size(); ++i) {
        Book bk = v[i];

        if(author == bk.getAuthor())
            bk.show();
    }
}

void BookManager::searchByYear() {
    cout << "검색하고자 하는 년도를 입력하세요>> ";
    int year;
    cin >> year;

    for(int i = 0; i < v.size(); ++i) {
        Book bk = v[i];

        if(year == bk.getYear())
            bk.show();
    }
}

void BookManager::run() {
    bookIn();
    searchByAuthor();
    searchByYear();
}

int main() {
    BookManager man;
    man.run();
}

