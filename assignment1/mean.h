#include <iostream>

using namespace std;

// long double mean(int* &ar, int size) {
//     long double sum = 0.0;
 
//     long double result;

//     for(int i = 0; i < size; i++){
//         sum += ar[i];
//     }

//     result = (long double)sum / (long double)size;
//     return result;


// }


long double mean(int* &arr, int size) {
	long double result = 0;
	long double size1 = size;
	for (int i = 0; i < size; i++) {
		result = result + arr[i];
	}
	return result / size1;
}