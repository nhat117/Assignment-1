#include <iostream>

using namespace std;

float covariance(int* &arX, int* &arY, int arSize) {
    float res = 0;
    float meanX = mean(arX, arSize);
    float meanY = mean(arY, arSize);
    for (int i = 0; i < arSize; i++) {
        res = res + (arX[i] - meanX) * (arY[i] - meanY);
    }
    return res / (arSize - 1);
}