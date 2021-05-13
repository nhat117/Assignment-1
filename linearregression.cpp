#include <iostream>

using namespace std;

void LinearRegression(long double mean_x, long double mean_y, long double stdev_x, long double stdev_y, long double r) {
	//Standard deviation algorithm
	long double a = (r * stdev_y) / stdev_x;
	long double b = mean_y - (a * mean_x);

	//Return result
 	cout << "y = " << a << "x + "  << b << endl;
}

