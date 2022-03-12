#include "signal.h"

using namespace std;

int main() {
	Signal s1(2,2);
    cout << "Nhap cac thanh phan cua ma tran: \n";
    cin >> s1;
    cout << "Xuat: \n";
    cout << s1 << endl;

    Signal s2(2,2);
    cout << "Nhap cac thanh phan cua ma tran: \n";
    cin >> s2;
    cout << "Xuat: \n";
    cout << s2 << endl;

    cout << "Tong: \n";
    cout << s1 + s2 << endl;

    cout << "Tich: \n";
    cout << s1 * s2 << endl;
}