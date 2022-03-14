#include "signal.h"

using namespace std;

int main() {
    DS ds1;
    ds1.input();
    ds1.output();

    // DS ds2;
    // ds2.input();

    // ds1.tong(ds2);
    // ds2.output();

    DS ds3 = ds1.downsampling();
    ds3.output();

    DS ds4 = ds1.upsampling();
    ds4.output();

    // ds1.shifting();
    // ds1.output();

    // ds1.reversal();
    // ds1.output();
   
    system("pause");
    return 0;
}