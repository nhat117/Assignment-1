#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "quicksort.h"
#include "mean.h"
#include "median.h"
#include "mode.h"
#include "varandstdev.h"
#include "covariance.h"
#include "correlation.h"
#include "firstquartile.h"
#include "skew.h"
#include "mad.h"
#include "kurtosis.h"
#include "linearregression.h"
#include "pearsoncorrelation.h"
#include <sstream>

//Add a chrono watch
#include <chrono> 
using namespace std::chrono; 

using namespace std;

#define group 27
#define MAX 1000000

//Main function
int main(int argc, char* argv[]) {
	//Start stopwatch
	auto start = high_resolution_clock::now(); 
	
    int* xArray = new int[MAX];
    int* yArray = new int[MAX];
    int cur = 0;
    int arraySize = 0;
    int maxX = -9999999;
    int maxY = -9999999;
    int iX;
    int iY;
    string line;
    string x;
    string y;
    ifstream inp(argv[1]);

    //check if file can be openned
    if (!inp.is_open()) {
        cerr << "Cannot open the file!\n";
        return 1;
    }
    
    while (!inp.eof()) {
        getline(inp, x, ',');
        getline(inp, y, '\n');
        if (x == "x") continue;
        if (y == "y") continue;
        iX = stoi(x);
        iY = stoi(y); 
        xArray[cur] = iX;
        yArray[cur] = iY;
        if (iX > maxX) maxX = iX;
        if (iY > maxY) maxY = iY;
        cur++;
        arraySize++;
    }
    inp.close();

	// sort array x and y
	cout << "size: " << arraySize << endl;
	quicksort(xArray, 0, arraySize - 1);
	quicksort(yArray, 0, arraySize - 1);

	// Calculate meanX and meanY
	long double meanX = mean(xArray, arraySize);
	long double meanY = mean(yArray, arraySize);

	// Ex 1 Sort and fine median
    
	// Calculate median
	long double medianX = findMedian(xArray, arraySize);
    long double medianY = findMedian(yArray, arraySize);
	cout.precision(10);
	cout << "median_x : " << medianX << " - median_y : " << medianY << "\n";
	
	//Ex 2 Calculate mode
	cout << "mode_x : ";
    mode(xArray, arraySize);
    cout << " - ";
    cout << "mode_y : ";
    mode(yArray, arraySize);
    cout << "\n";
	
    // EX 3 Variance and standart deviation
	long double varX = variance(xArray, arraySize, meanX);
	long double varY = variance(yArray, arraySize, meanY);
    cout << "var_x = " << varX << " - var_y = " << varY << "\n";
	long double stdevX = stdev(varX);
	long double stdevY = stdev(varY);
    cout << "stdev_x = " << stdevX << " - stdev_y = " << stdevY << "\n";

	// EX 4 Mean absolute deviations
	long double madX = mad(xArray, arraySize, meanX);
	long double madY = mad(yArray, arraySize, meanY);
	cout.precision(15);
	cout << "mad_x = " << madX << " - mad_y = " << madY << "\n";

    // EX 5 Firstquartile
	long double fqX = firstQuartile(xArray, arraySize);
	long double fqY = firstQuartile(yArray, arraySize);
    cout << "q1_x : " << fqX << " - q1_y : " << fqY << "\n";
	
	// EX 6 Skewness
	long double skewX = skew(xArray, arraySize, varX, meanX);
	long double skewY = skew(yArray, arraySize, varY, meanY);
	cout << "skew_x = " << skewX << " - skew_y = " << skewY << "\n";

    // Ex 7 Kurtosis
	long double kurtX = kurt(xArray, arraySize, meanX, stdevX);
	long double kurtY = kurt(yArray, arraySize, meanY, stdevY);
	cout << "kurt_x : " << kurtX << " - kurt_y : " << kurtY << "\n";

    //Section C
    //
    // EX C1 Covariane
	long double covXY = covariance(xArray, yArray, arraySize, meanX, meanY);
    cout << "cov(x_y) = " << covXY << "\n";

    // EX C2 Pearson Correlation
    // cout << "r(x_y) = " << correlationCoefficient(covXY, stdevX, stdevY) << "\n";
	long double rXY = pcc(covXY, stdevX, stdevY);
	cout << "Thinh r(x_y) = " << rXY << "\n";

	// EX C3 Linear Regression
	LinearRegression(meanX, meanY,stdevX, stdevY, rXY);

    //delete array and close file
    delete []xArray;
    delete []yArray;

	//Stop stopwatch and output the time
	auto stop = high_resolution_clock::now(); 
	// use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl; 
   
    return 0;   
}

 