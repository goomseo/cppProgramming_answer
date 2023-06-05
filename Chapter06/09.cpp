#include<iostream>
#include<string>

using namespace std;

class Board{
public:
    static int cnt;
    static string *comment;
    static void add(string str);
    static void print();
};

int Board::cnt = 0;
string *Board::comment = new string [100];

void Board::add(string str){
    comment[cnt] = str;
    cnt++;
}

void Board::print(){
    cout << "************* 게시판입니다. *************\n";
    for(int i=0; i<cnt; i++)
        cout << i << ": " << comment[i] << endl;
    cout << endl;
}

int main() {
    Board::add("중간고사는 감독 없는 자율 시험입니다.");
    Board::add("코딩 라운지 많이 이용해 주세요.");
    Board::print();
    Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
    Board::print();
}