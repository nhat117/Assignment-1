#include <iostream>
using namespace std;
// Function prototype
int divide (int *&inputarr, int Startindex, int Lastindex);
void quickSort(int *&inputarr, int Startindex, int Lastindex) ;
void swap(int* a, int* b) ;
void printarr(int *inputarr, int size) ;
double findMedian(int *& sortedarr, int &size);
//Function definition
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
/*  takes last element as pivot point, places 
the pivot element at its correct position in sorted 
inputarray, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivotpoint */
int divide (int *&inputarr, int Startindex, int Lastindex) 
{ 
    int pivot = inputarr[Lastindex]; // pivot 
    int i = (Startindex - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int i2 = Startindex; i2 <= Lastindex - 1; i2++) 
    { 
        // If current element is smaller than the pivot 
        if (inputarr[i2] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&inputarr[i], &inputarr[i2]); 
        } 
    } 
    swap(&inputarr[i + 1], &inputarr[Lastindex]); 
    return (i + 1); 
} 
 
/* The main function that implements QuickSort 
inputarr[] --> inputarray to be sorted, 
Startindex --> Starting index, 
Lastindex --> Ending index */
void quickSort(int *&inputarr, int Startindex, int Lastindex) 
{
    if (Startindex < Lastindex) 
    { 
        /* pivot is divideing index, inputarr[p] is now 
        at right place */
        int pivot = divide(inputarr, Startindex, Lastindex); 
 
        // Separately sort elements before 
        // divide and after divide 
        quickSort(inputarr, Startindex, pivot - 1); 
        quickSort(inputarr, pivot + 1, Lastindex); 
    } 
} 
 
/* Function to print an inputarray */
void printarr(int *inputarr, int size) { 
    int i; 
    for (i = 0; i < size; i++) 
        cout << inputarr[i] << " "; 
    cout << '\n'; 
} 
 
double findMedian(int *&sortedarr, int &size) {
    if (size % 2 != 0)
        return sortedarr[size / 2];
    return (sortedarr[(size - 1) / 2] + sortedarr[size / 2]) / 2;
}
 
