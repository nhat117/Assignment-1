#include <iostream>

using namespace std;
#define MAX 1000000
void mode(int* &arr, int size) {
	int highest = 0;
	int* count = new int[MAX];

	// count the number of repetion of each element
	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
		if (highest < count[arr[i]]) highest = count[arr[i]];
	}

	// print the most frequently occurring elements
    cout << "{";
	for (int i = 0; i < MAX; i++) {
		if (highest == count[i]) cout << " " << i << " ";
	}
    cout << "}";
	// cout << "(" << highest << " times)" << "\n";

	delete[] count;
	return;
}

int main(int argc, char* argv[]) {
    int* arr = new int[15];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 6;
	arr[4] = 6;
	arr[5] = 6;
	arr[6] = 6;
	arr[7] = 6;
	arr[8] = 6;
	arr[9] = 7;
	arr[10] = 7;
	arr[11] = 7;
	arr[12] = 7;
	arr[13] = 7;
	arr[14] = 7;
	mode(arr, 15);
    return 0;
}