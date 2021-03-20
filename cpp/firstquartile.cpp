#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "median.h"
#include "mode.h"
//#include "variance.h"
//#include "covariance.h"
using namespace std;

#define group 27
#define MAX 1000000

double firstQuartile(int *&sortedarr, int &size) {
    if (size/2 % 2 != 0)
        return sortedarr[size / 4];
    return (sortedarr[(size - 1) / 4] + sortedarr[size / 4]) / 2;
}

//Main function
int main(int argc, char* argv[]) {
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

    if (!inp.is_open()) {
        cerr << "Cannot open the file!\n";
        return 1;
    }

    while (inp.good()) {
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
	// Ex 1 Sort and fine mean
	//Sort X and y
	quickSort(xArray, 0, arraySize); 
	quickSort(yArray, 0, arraySize); 
    cout << "q1_x : " << firstQuartile(xArray, arraySize) << " - ";
	cout << "q1_y : " << firstQuartile(yArray, arraySize) << "\n";

    delete []xArray;
    delete []yArray;
    inp.close();
    return 0;
}