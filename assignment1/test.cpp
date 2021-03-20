#include <iostream>
#include "mean.h"
using namespace std;

int main() {
    int* ar = new int[5];
    ar[0] = 1;
    ar[1] = 2;
    ar[2] = 3;
    ar[3] = 4;
    ar[4] = 5;
    cout << mean(ar, 5);
}