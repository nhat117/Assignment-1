#include <iostream>
#include <math.h>
using namespace std;

float mad(int* &ar, int arSize, int mean) {
    float res = 0;
    for (int i = 0; i < arSize; i++) {
        res += abs(ar[i] - mean);
    }
    return res / arSize;
}

int main() {

    return 0;
}