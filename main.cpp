#include "signal.h"

using namespace std;

int main() {
    DS ds1;
    ds1.input();
    ds1.output();

    ds1.shifting();
    ds1.output();

    ds1.reversal();
    ds1.output();

    system("pause");
    return 0;
}