#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "median.h"
#include "mode.h"
#include "variance.h"
using namespace std;

#define groupCSV 27
#define MAX 1000000

// // Function prototype
// int divide (int *&xArray, int Startindex, int Lastindex);
// void quickSort(int *&xArray, int Startindex, int Lastindex) ;
// void swap(int* a, int* b) ;
// void printarr(int *xArray, int size) ;
// double findMedian(int *& sortedarr, int &size);
//Main function
int main(int argc, char* argv[]) {
    int* xArray = new int[MAX];
    int* yArray = new int[MAX];
    int cur = 0;
    int arraySize = 0;
    
    string line;
    string x;
    string y;
    ifstream inp(argv[1]);

    if (!inp.is_open()) {
        cerr << "Cannot open the file!\n";
        return 1;
    }

    while (inp.good()) {
        getline(inp, x, ',');
        getline(inp, y, '\n');
        if (x == "x") continue;
        if (y == "y") continue;
        xArray[cur] = stoi(x);
        yArray[cur] = stoi(y);
        cur++;
        arraySize++;
    }
	// Ex 1 Sort and fine mean
	//Sort X and y
	quickSort(xArray, 0, arraySize); 
	quickSort(yArray, 0, arraySize); 
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
    cout << "var_x= " << variance(xArray,arraySize) << " - " << "var_y= " << variance(yArray,arraySize) << "\n";
    cout << "stdev_x= " << deviation(variance(xArray,arraySize)) << " - " << "stdev_y= " << deviation(variance(yArray,arraySize)) << "\n";
	//delete array and close file
    delete []xArray;
    delete []yArray;
    inp.close();
   
    return 0;   
}

 