#include <iostream>

using namespace std;

long double covariance(long double* arX, long double* arY, int arSize, long double meanX, long double meanY) {
    long double res = 0;
    //Calculate covariance equals sum of data value of X minus arrayX's mean times by data value of Y minus arrayY's mean
    //and then divide it by size the number of data minus 1
    for (int i = 0; i < arSize; i++) {
        res = res + (((long double)arX[i] - meanX) * ((long double)arY[i] - meanY));
    }
    
    return res / (long double)(arSize - 1);
}