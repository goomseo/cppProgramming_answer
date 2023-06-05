#include <iostream>
#include <string>

using namespace std;

// BasedClass - 프린터
class Printer {
private:
    string model, manufacturer;
    int printedCount, availableCount;
public:
    Printer(string model, string manufacturer, int availableCount);

    virtual bool isPrintable(int pages);
    virtual void print(int pages); // pages매의 용지를 사용하여 출력
    virtual void showInfo();

    string getModel() {return model;}
    string getManufacturer() {return manufacturer;}
    int getAvailableCount() {return availableCount;}

    void setAvailableCount(int pages) {availableCount -= pages;}
    void setPrintedCount(int pages) {printedCount += pages;}
};

Printer::Printer(string model, string manufacturer, int availableCount) {
    this -> model = model;
    this -> manufacturer = manufacturer;
    this -> availableCount = availableCount;
    printedCount = 0;
}

bool Printer::isPrintable(int pages) {
    if (pages <= availableCount)
        return true;

    return false;
}

void Printer::print(int pages) {
    if (!isPrintable(pages)) {
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        return;
    }

    setAvailableCount(pages);
    setPrintedCount(pages);

    cout << "프린트하였습니다." << endl;
}

void Printer::showInfo() {
    cout << "프린터 : " << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장" << endl;
}

// Derived 1 - 잉크젯 프린터
class InkJetPrinter : public Printer {
private:
    int availableInk;
public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk);

    bool isPrintable(int pages);
    void printInkJet(int pages);
    void showInfo();
};

InkJetPrinter::InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk)
: Printer(model, manufacturer, availableCount) {
    this -> availableInk = availableInk;
}

bool InkJetPrinter::isPrintable(int pages) {
    if (Printer::isPrintable(pages) and pages <= availableInk)
        return true;

    return false;
}

void InkJetPrinter::printInkJet(int pages) {
    if (!isPrintable(pages)) {
        if (pages > getAvailableCount())
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        else if (pages > availableInk)
            cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;

        return;
    }

    setAvailableCount(pages);
    setPrintedCount(pages);
    availableInk -= pages;

    cout << "프린트하였습니다." << endl;
}

void InkJetPrinter::showInfo() {
    cout << "프린터 : " << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailableCount() << "장, 남은 잉크: " << availableInk << endl;
}

// Derived 2 - 레이저 프린터
class LaserPrinter : public Printer {
private:
    int availableToner;
public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner);

    bool isPrintable(int pages);
    void printLaser(int pages);
    void showInfo();
};

LaserPrinter::LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
: Printer(model, manufacturer, availableCount) {
    this -> availableToner = availableToner;
}

bool LaserPrinter::isPrintable(int pages) {
    if (Printer::isPrintable(pages) and pages <= availableToner)
        return true;

    return false;
}

void LaserPrinter::printLaser(int pages) {
    if (!isPrintable(pages)) {
        if (pages > getAvailableCount())
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        else if (pages > availableToner)
            cout << "토너가 부족하여 프린트할 수 없습니다." << endl;

        return;
    }

    setAvailableCount(pages);
    setPrintedCount(pages);
    availableToner -= pages;

    cout << "프린트하였습니다." << endl;
}

void LaserPrinter::showInfo() {
    cout << "프린터 : " << getModel() << ", " << getManufacturer() << ", 남은 종이 " << getAvailableCount() << "장, 남은 토너: " << availableToner << endl;
}


int main() {
    InkJetPrinter *inkP = new InkJetPrinter("Officejet V40", "HP", 5, 10);
    LaserPrinter *laserP = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
    cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
    inkP -> showInfo(); laserP -> showInfo();

    while (true) {
        int printerType, pages;
        cout << "\n프린터(1: 잉크젯, 2: 레이저)와 매수 입력>> ";
        cin >> printerType >> pages;

        if (printerType == 1)
            inkP -> printInkJet(pages);
        else if (printerType == 2)
            laserP -> printLaser(pages);
        else {
            cout << "프린터 타입이 올바르지 않습니다. 다시 입력해 주세요." << endl;
            continue;
        }

        inkP -> showInfo(); laserP -> showInfo();

        char respond;
        cout << "계속 프린트 하시겠습니까(y/n)>> ";
        cin >> respond;

        if (respond == 'n')
            break;
    }

    delete inkP;
    delete laserP;
}
