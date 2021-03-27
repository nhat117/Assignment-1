#include <iostream>

using namespace std;

long double covariance(int* &arX, int* &arY, int arSize, long double meanX, long double meanY) {
    long double res = 0;
    for (int i = 0; i < arSize; i++) {
        res = res + (((long double)arX[i] - meanX) * ((long double)arY[i] - meanY));
    }
    return res / (long double)(arSize - 1);
}