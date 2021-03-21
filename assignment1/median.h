#include <iostream>
using namespace std;

long double findMedian(int *&sortedArr, int size) {
	size --;
    if (size % 2 != 0)
        return (long double)sortedArr[size / 2];
    return (long double)(((long double)sortedArr[(size - 1) / 2] + (long double)sortedArr[size / 2]) / 2);
}

