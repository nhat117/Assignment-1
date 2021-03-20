#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>

using namespace std;

#define MAX 1000000000

double variance(int *&myarray, int size);
double mean(int *&myarray, int size);
double deviation(double variance);

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
   
    cout << arraySize << " " << variance(xArray,arraySize) << endl;
    cout << "Standard deviation " << deviation(variance(xArray,arraySize)) << endl;

    //delete array and close file
    delete []xArray;
    delete []yArray;
    inp.close(); 
    return 0;
}

double variance(int *&myarray, int size){
    double meanRes = mean(*&myarray,size);
    double res = 0;
    //Calculate the square difference between the element and the mean and sum it up
    for(int i = 0; i < size;i++){
        res += pow(myarray[i]-meanRes,2);
    }

    //Divide the sum of square difference by the population minus 1
    res /= (size-1);
    return res;
}

double mean(int *&myarray, int size) {
    double res = 0;
    //Sum of all array element
    for(int i = 0; i < size; i++){
        res += myarray[i];
    }
    //Divide sum by the size of the array, we get the mean
    res /= size;
    return res;
}

double deviation(double variance){
    //Standard deviation equals square root of variance
    return sqrt(variance);
}