#include <math.h>

using namespace std;

long double mad(long double* ar, int size, long double meanNum){
    long double sum = 0;
    // Calculate mad by summing the absolute result of the subtraction of array's data value and array's mean
    for (int i = 0; i < size; i++)
        sum = sum + fabs(ar[i] - meanNum);
    // and divide it by array's size
    return sum / (long double)size;
}