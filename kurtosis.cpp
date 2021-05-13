#include <iostream>
#include <math.h>

using namespace std;

long double kurt(long double* inputarray, int size, long double mean, long double deviation) {
    //Intialize kurtosis variable
	long double kurtosis = 0;
	
    //Loop through the array calculate sum
    for (int i = 0; i < size; i++){
		kurtosis += pow((inputarray[i] - mean) / deviation, 4);
	}
    
    kurtosis /= size;
    kurtosis -= 3;
    
    return kurtosis;
}