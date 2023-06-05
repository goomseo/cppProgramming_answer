#include <iostream>

using namespace std;

class Converter {
protected:
    double ratio;
    virtual double convert(double src) = 0;
    virtual string getSourceString() = 0;
    virtual string getDestString() = 0;
public:
    Converter(double ratio) {this -> ratio = ratio;}

    void run();
};

void Converter::run() {
    double src;
    cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다. ";
    cout << getSourceString() << "을 입력하세요>> ";
    cin >> src;
    cout << "반환 결과: " << convert(src) << getDestString() << endl;
}

class WonToDollar : public Converter {
private:
    string source, dest;
public:
    WonToDollar(double ratio);
    double convert(double src) override {return src / ratio;}
    string getSourceString() override {return source;}
    string getDestString() override {return dest;}
};

WonToDollar::WonToDollar(double ratio) : Converter(ratio) {
    source = "원";
    dest = "달러";
}

int main() {
    WonToDollar wd(1010);
    wd.run();
}
