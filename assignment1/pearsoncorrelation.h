#include <iostream>
#include "math.h"

long double pcc(long double covXY, long double stdevX, long double stdevY) {
	long double res = 0;
	res = covXY / (stdevX * stdevY);
	return res;
}