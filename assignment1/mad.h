#include <iostream>
#include <math.h>

using namespace std;

long double mad(int* &ar, int size, long double meanNum){
    long double sum = 0;
    for (int i = 0; i < size; i++)
        sum = sum + abs(ar[i] - meanNum);
    return sum / (long double)size;
}