#include <iostream>

using namespace std;

// Calcultate median
long double findMedian(long double* sortedArr, int size) {
	long double result = 0;
	// If size is even
	if (size % 2 != 0) return (long double)sortedArr[size / 2];
	// if the size is odds
	return (long double)(((long double)sortedArr[(size / 2) - 1] + (long double)sortedArr[size / 2]) / 2);
}