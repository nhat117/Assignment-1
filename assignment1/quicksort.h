#include <iostream>

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
void quicksort(int *&inputarr, int Startindex, int Lastindex) 
{
    if (Startindex < Lastindex) 
    { 
        /* pivot is divideing index, inputarr[p] is now 
        at right place */
        int pivot = divide(inputarr, Startindex, Lastindex); 
 
        // Separately sort elements before 
        // divide and after divide 
        quicksort(inputarr, Startindex, pivot - 1); 
        quicksort(inputarr, pivot + 1, Lastindex); 
    } 
} 