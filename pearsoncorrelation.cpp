#include <iostream>
#include <math.h>

using namespace std;

long double pcc(long double covXY, long double stdevX, long double stdevY) {
	long double res = 0;
    // Pearson Correlation can be calculated by taking covariance of X and Y
    // divided by the product of standard deviation of X and Y
	res = covXY / (stdevX * stdevY);
	return res;
}