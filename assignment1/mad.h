#include <iostream>
#include <math.h>
#include "mean.h"

using namespace std;

double mad(int* &ar, int size, int meanNum){
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum = sum + abs(ar[i] - meanNum);
    return sum / size;
}