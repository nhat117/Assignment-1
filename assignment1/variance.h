#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

//Function Prototype
double variance(int *&myarray, int size);
double mean(int *&myarray, int size);
double deviation(double variance);
//Function definition
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