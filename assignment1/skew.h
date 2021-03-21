#include <iostream>
#include <math.h>

long double skew(int*& arr, int size, long double var, long double meanNum) {
	long double res = 0;
	for (int i = 0; i < size; i++) {
		res += pow((arr[i] - meanNum) / sqrt(var), 3);
	}
	return res / size;
}