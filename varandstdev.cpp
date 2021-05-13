#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//Function definition
long double variance(long double* myarray, int size, long double meanNum){
    long double res = 0;
    //Calculate the square difference between the element and the mean and sum it up
    for(int i = 0; i < size;i++){
        res += pow(myarray[i]- meanNum, 2);
    }

    //Divide the sum of square difference by the population minus 1
    res /= (size-1);
    return res;
}

long double stdev(long double variance) {
    // Standard deviation can be calculated by taking the square root of variance
	return sqrt(variance);
}