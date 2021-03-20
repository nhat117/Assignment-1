#include <iostream>

using namespace std;
#define MAX 1000000
void mode(int* &arr, int size) {
	int highest = 0;
	int* count = new int[size];

	// count the number of repetion of each element
	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
		if (highest < count[arr[i]]) highest = count[arr[i]];
	}

	// print the most frequently occurring elements
    cout << "{";
	for (int i = 0; i < size; i++) {
		if (highest == count[i]) cout << " " << i << " ";
	}
    cout << "}";

	delete[] count;
	return;
} 