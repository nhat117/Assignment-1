#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "median.h"
#include "mode.h"
#include "variance.h"
#include "covariance.h"
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

	// Ex 1 Sort and fine mean
		//Sort X and y
		// Index of last mem of Dynamic array = arrsize - 1  
	// Calculate Median
	
	cout << "median_x : " << findMedian(xArray, arraySize) << " - ";
	cout << "median_y : " << findMedian(yArray, arraySize) << "\n";
	
	//Ex 2 Calculate mode
	cout << "mode_x : ";
    mode(xArray, arraySize);
    cout << " - ";
    cout << "mode_y : ";
    mode(yArray, arraySize);
    cout << "\n";
	
    // EX 3 variance
    cout << "var_x= " << variance(xArray, arraySize) << " - " << "var_y= " << variance(yArray, arraySize) << "\n";
    cout << "stdev_x= " << deviation(variance(xArray, arraySize)) << " - " << "stdev_y= " << deviation(variance(yArray, arraySize)) << "\n";
    //
    //Section C
    //
    // EX C1 Covariane
    cout << "cov(x_y) = " << covariance(xArray, yArray, arraySize) << "\n";
    // EX C2 Correlation Coefficient
    // cout << "r(x_y) = " << correlationCoefficient(xArray, yArray, arraySize) << "\n";

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

 