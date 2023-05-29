#include <iostream>
#include <string>

using namespace std;

class Trace {
private:
    static string logArr[100][2];
    static int id;
public:
    static void put(string tag, string debuggingInfo);
    static void print(string tag = "");
};

string Trace::logArr[100][2] = {{"", ""}};

int Trace::id = 0;

void Trace::put(string tag, string debuggingInfo) {
    logArr[id][0] = tag;
    logArr[id][1] = debuggingInfo;
    id++;
}

void Trace::print(string tag) {
    if (tag == "") {
        cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl;

        for (int i = 0; i < id; ++i)
            cout << logArr[i][0] << ": " << logArr[i][1] << endl;
    }
    else {
        cout << "----- " << tag << "태그의 Trace 정보를 출력합니다. -----" << endl;

        for (int i = 0; i < id; ++i)
            if (tag == logArr[i][0])
                cout << tag << ": " << logArr[i][1] << endl;
    }
}

void f() {
    int a, b, c;
    cout << "두 개의 정수를 입력하세요>> ";
    cin >> a >> b;
    Trace::put("f()", "정수를 입력 받았음");
    c = a + b;
    Trace::put("f()", "합 계산");
    cout << "합은 " << c << endl;
}

int main() {
    Trace::put("main()", "프로그램 시작합니다");
    f();
    Trace::put("main()", "종료");

    Trace::print("f()");
    Trace::print();
}