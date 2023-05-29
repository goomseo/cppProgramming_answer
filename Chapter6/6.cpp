#include<iostream>
using namespace std;

class ArrayUtility2{
public:
    static int* concat(int s1[], int s2[], int size);
    static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size){
    int* tot = new int [size];
    for(int i=0; i<size/2; i++)
        tot[i] = s1[i];

    for(int i=size/2, j=0; i<size; i++,j++)
        tot[i] = s2[j];

    return tot;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize){
    int* rmtot = new int [size/2];
    int cnt;

    for(int i=0; i<size/2; i++){
        cnt = 0;
        for(int j=0; j<size/2; j++)
            if(s1[i] == s2[j])
                cnt++;

        if(cnt == 0) {
            rmtot[i] = s1[i];
            retSize++;
        }
    }
    if(retSize == 0)
        return nullptr;

    return rmtot;
}

int main() {
    int x[5], y[5];
    int size,retSize = 0;
    int *p;

    cout << "정수 5 개 입력하라. 배열 x에 삽입한다>>";
    for(int i=0; i<5; i++)
        cin >> x[i];

    cout << "정수 5 개 입력하라. 배열 y에 삽입한다>>";
    for(int i=0; i<5; i++)
        cin >> y[i];

    size = (sizeof(x) + sizeof(y)) / sizeof(int);
    cout << "합친 정수 배열을 출력한다\n";
    p = ArrayUtility2::concat(x,y,size);
    for(int i=0; i<size; i++)
        cout << p[i] << ' ';

    cout << endl << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 ";
    p = ArrayUtility2::remove(x,y,size,retSize);
    cout << retSize << endl;
    for(int i=0; i<retSize; i++)
        cout << p[i] << ' ';
}