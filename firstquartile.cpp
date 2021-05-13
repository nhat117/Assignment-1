#include <iostream>

using namespace std;

long double firstQuartile(long double* sortedArr, int size) {
    //Find first quartile of the array by divide sorted array by 4
    //If the array size is even return the data value which index is the array size divided by 4
    //If the array size is odd return the average between two data value that have the index closest to the value of array size divided by 4
    if (size / 2 % 2 != 0)
        return sortedArr[size / 4];
        
    return (sortedArr[(size - 1) / 4] + sortedArr[size / 4]) / 2;
}