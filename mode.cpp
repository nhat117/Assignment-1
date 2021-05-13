#include <iostream>

using namespace std;

void mode(long double* sortedarr, int size) {
    // Create new struct to hold the value and frequency
    struct data { 
        long double val;
        int freq = 1;
    };

    int resSize = 0; // Size of result array
    int maxFreq = 1; // If that number exists -> it appears 1 times
    int count = 1; // Find the number of different elements
    int cur = 0; // Control the index in an array

    data* ar = new data[size];

    data temp; 
    temp.val = sortedarr[0];

    long double* result = new long double[size];

    // Loop through the sorted array
    // Make comparision between element i and i + 1 in each loop
    for (int i = 0; i < size; i++) {

        if (i == size - 1) {
            temp.val = sortedarr[i];
            ar[cur] = temp;
            break;
        }
        if (sortedarr[i] == sortedarr[i + 1]) {
            temp.freq++; // Increment the frequency of current value
            if (temp.freq > maxFreq) maxFreq = temp.freq; // Update the mode
        }
        else {
            // If the next element is different
            // Stop updating frequency

            ar[cur] = temp; // Push to the array
            temp.val = sortedarr[i + 1]; // Change temp.val to the next value
            temp.freq = 1; //reset frequency
            cur++; // Move to the next position
            count++; // Find the number of different elements
        }
    } 

    // Reset cur
    cur = 0;
    
    // Find the elements that has the same maxFreq
    for (int i = 0; i < count; i++) {
        if (ar[i].freq == maxFreq) {
            result[cur] = ar[i].val;
            cur++;
            resSize++;
        }
    }


    // Print result in the given format
    if (resSize == 1) {
        cout << "{ " << result[0] << " }";
    }
    else {
        cout << "{";
        for (int i = 0; i < resSize; i++) {
            if (i == resSize - 1) {
                cout << " " << result[i] << " ";
            }
            else {
                cout << " " << result[i] << " ,";
            }
        }
        cout << "}";
    }

    //delete dynamic arrays
    delete [] ar;
    delete [] result;
}