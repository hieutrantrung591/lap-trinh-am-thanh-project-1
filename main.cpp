#include "signal.h"

using namespace std;

int main() {
    DS ds1;
    ds1.input();
    ds1.output();

    DS ds2;
    ds2.input();

    DS tong = ds1.tong(ds2);
    tong.output();

    DS tich = ds1.tich(ds2);
    tich.output();

    // ds1.tong(ds2);
    // ds2.output();


    // int key;
    // vector<DS> list;
    // DS ds1, ds2;
    
    // while(true) {                
    //     menu();

    //     cin >> key;
    //     switch(key) {
    //         case 1:
    //             cout << "\n1. Nhap 2 tin hieu";
    //             ds1.input();
    //             ds2.input();
    //             break;
    //         case 2:
    //             cout << "\n2. Tong 2 tin hieu";
    //             DS tong = ds1.tong(ds2);
    //             tong.output();
    //             break;
    //         case 3:
    //             cout << "\n3. Tich 2 tin hieu";
    //             ds1.tich(ds2);
    //             break;
    //         case 4:
    //             cout << "\n4. Nhan tin hieu voi hang so";
    //             break;
    //         case 5:
    //             cout << "\n5. Dich thoi gian";
    //             ds1.shifting();
    //             ds1.output();
    //             break;
    //         case 6:
    //             cout << "\n6. Dao thoi gian";
    //             ds1.reversal();
    //             ds1.output();
    //             break;
    //         case 7:
    //             cout << "\n7. Tang tan so lay mau (upsampling)";
    //             DS ds4 = ds1.upsampling();
    //             ds4.output();
    //             break;
    //         case 8:
    //             cout << "\n8. Giam tan so lay mau (downsampling)";
    //             DS ds3 = ds1.downsampling();
    //             ds3.output();
    //             break;
    //         case 0:
    //             cout << "Thoat!\n";
    //             exit(1);
    //             break;
    //         default:
    //             cout << "Khong ton tai lua chon!\n";
    //             break;
    //     }
    // }

    system("pause");
    return 0;
}