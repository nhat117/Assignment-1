#include "allheaders.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Main function
int main(int argc, char* argv[]) {

    // Toggle off synchronization for standard stream to achieve cout speed as same as printf()
    ios::sync_with_stdio(0);
    cout.tie(0);

    // Check number of arguments
	if (argc > 2 || argc == 1) {
        cerr << "Invalid arguments!\n";
        return -1;
    }

	// Initialize Variable
    int arraySize = 0, cur = 0;
    string line, x, y;

	// Initialize stream to read data from file
    ifstream inp(argv[1]);

    // Check if file can be opened
    if (!inp.is_open()) {
        cerr << "Cannot open the file!\n";
        return -1;
    }

    // Find rows, arraySize
    while (!inp.eof()) {
        getline(inp, line);
        arraySize++;
    }
	line.clear();

    // Reset pointer to the beginning of the file
    inp.clear();
    inp.seekg(0);

    // Initialize x, y arrays
    long double* xArray = new long double[arraySize];
    long double* yArray = new long double[arraySize];

    // Input data from file to array
    while (!inp.eof()) {
		// Get one line
        getline(inp, line);

        // Check if line have data or not
        if (line.size() == 0) {
            arraySize--;
            continue;
        }

        // Split line into two strings
		splitStr(line, x, y);

        // Check if data is a number or not
        if (!numberChk(x) || !numberChk(y)) {
			x.clear();
			y.clear();
            arraySize--;
            continue;
        }

		// Convert input string stream and store in a dynamically allocated array
        xArray[cur] = stold(x);
        yArray[cur] = stold(y);

		// Move cursor to next position
		x.clear();
		y.clear();
        cur++;
    }
    
	line.clear();

	// Close stream to file
    inp.close();

	// Variable init and call function to compute
    long double meanX = mean(xArray, arraySize);
    long double meanY = mean(yArray, arraySize);
    long double covXY = covariance(xArray, yArray, arraySize, meanX, meanY);
    long double varX = variance(xArray, arraySize, meanX);
    long double varY = variance(yArray, arraySize, meanY);
    long double stdevX = stdev(varX);
    long double stdevY = stdev(varY);
    long double kurtX = kurt(xArray, arraySize, meanX, stdevX);
    long double kurtY = kurt(yArray, arraySize, meanY, stdevY);
    long double madX = mad(xArray, arraySize, meanX);
    long double madY = mad(yArray, arraySize, meanY);
	long double skewX = skew(xArray, arraySize, varX, meanX);
    long double skewY = skew(yArray, arraySize, varY, meanY);
    long double rXY = pcc(covXY, stdevX, stdevY);
	// Sorting 2 arrays
    mergeSort(xArray, 0, arraySize - 1);
    mergeSort(yArray, 0, arraySize - 1);
    long double medianX = findMedian(xArray, arraySize);
    long double medianY = findMedian(yArray, arraySize);
    long double fqX = firstQuartile(xArray, arraySize);
	long double fqY = firstQuartile(yArray, arraySize);
	
	// Set cout format flag
	cout.precision(4);
	cout.setf(ios::fixed);

	// Output the result of section B
	cout << "median_x : " << medianX << " - median_y : " << medianY << "\n";
	cout << "mode_x : ";
    mode(xArray, arraySize);
    cout << " - ";
    cout << "mode_y : ";
    mode(yArray, arraySize);
    cout << "\n";
	cout << "var_x = " << varX << " - var_y = " << varY << "\n";
	cout << "stdev_x = " << stdevX << " - stdev_y = " << stdevY << "\n";
	cout << "mad_x = " << madX << " - mad_y = " << madY << "\n";
	cout << "q1_x : " << fqX << " - q1_y : " << fqY << "\n";
	cout << "skew_x = " << skewX << " - skew_y = " << skewY << "\n";
	cout << "kurt_x : " << kurtX << " - kurt_y : " << kurtY << "\n";

	// Output the result of section C
	cout << "cov(x_y) = " << covXY << "\n";
	cout << "r(x_y) = " << rXY << "\n";
	LinearRegression(meanX, meanY,stdevX, stdevY, rXY);

    // Print group information
    cout << "ASSIGNMENT 1 GROUP 27\n";
    cout << "s3878231, s3878231@rmit.edu.vn, Anh, Truong Nhat\n";
    cout << "s3879364, s3879364@rmit.edu.vn, Thinh, Ngo Ngoc\n";
    cout << "s3878174, s3878174@rmit.edu.vn, Nhat, Bui Minh\n";
    cout << "s3878466, s3878466@rmit.edu.vn, Khang, Trieu Hoang\n";
    cout << "\n";

    delete[] xArray;
    delete[] yArray;
    return 0;
}