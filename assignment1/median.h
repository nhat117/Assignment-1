#include <iostream>
using namespace std;
#define START 0
// Function prototype
int divide (int *&inputarr, int STARTindex, int Lastindex);
void quickSort(int *&inputarr, int STARTindex , int Lastindex) ;
void swap(int* a, int* b) ;
void printarr(int *inputarr, int size) ;
double findMedian(int *& sortedarr, int size);
//Timsort
void timSort(int *&inputarr, int &sizeinput);
void mergesorted(int *inputarr, int &LeftIndex, int &MidleIndex, int &RightIndex);
void insertionSort(int *inputarr, int LeftIndex, int RightIndex);
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
int divide (int *&inputarr, int STARTindex, int Lastindex) 
{ 
    int pivot = inputarr[Lastindex]; // pivot 
    int i = (STARTindex - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int i2 = STARTindex; i2 <= Lastindex - 1; i2++) 
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
STARTindex --> STARTing index, 
Lastindex --> Ending index */
void quickSort(int *&inputarr, int STARTindex, int Lastindex) 
{
    if (STARTindex < Lastindex) 
    { 
        /* pivot is divideing index, inputarr[p] is now 
        at right place */
        int pivot = divide(inputarr, STARTindex, Lastindex); 
 
        // Separately sort elements before 
        // divide and after divide 
        quickSort(inputarr, STARTindex, pivot - 1); 
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
 
 // This function sorts inputarray from LeftIndex index to
// to RightIndex index which is of size atmost RUN
void insertionSort(int *inputarr, int LeftIndex, int RightIndex)
{
    for (int i = LeftIndex + 1; i <= RightIndex; i++)
    {
        int temp = inputarr[i];
        int i2 = i - 1;
        while (i2 >= LeftIndex && inputarr[i2] > temp)
        {
            inputarr[i2 + 1] = inputarr[i2];
            i2--;
        }
        inputarr[i2 + 1] = temp;
    }
}
 
// Mergesorted function mergesorteds the sorted runs
void mergesorted(int *inputarr, int &LeftIndex, int &MidleIndex, int &RightIndex)
{
     
    // Original inputarray is broi3en in two parts
    // LeftIndex and RightIndex inputarray
    int len1 = MidleIndex - LeftIndex + 1, len2 = RightIndex - MidleIndex;
    int LeftMember[len1], RightMember[len2];
    for (int i = 0; i < len1; i++)
        LeftMember[i] = inputarr[LeftIndex + i];
    for (int i = 0; i < len2; i++)
        RightMember[i] = inputarr[MidleIndex + 1 + i];
 
    int i = 0;
    int i2 = 0;
    int i3 = LeftIndex;
 
    // After comparing, we 
    // mergesorted those two inputarray
    // in larger sub inputarray
    while (i < len1 && i2 < len2)
    {
        if (LeftMember[i] <= RightMember[i2])
        {
            inputarr[i3] = LeftMember[i];
            i++;
        }
        else
        {
            inputarr[i3] = RightMember[i2];
            i2++;
        }
        i3++;
    }
 
    // Copy remaining elements of LeftIndex, if any
    while (i < len1)
    {
        inputarr[i3] = LeftMember[i];
        i3++;
        i++;
    }
 
    // Copy remaining element of RightIndex, if any
    while (i2 < len2)
    {
        inputarr[i3] = RightMember[i2];
        i3++;
        i2++;
    }
}
 
// Iterative Timsort function to sort the
// inputarray[0...n-1] (similar to mergesorted sort)
void timSort(int *&inputarr, int &sizeinput)
{
     
    // Sort individual subarrays of size RUN
    for (int i = 0; i < sizeinput; i+=sizeinput) {
        insertionSort(inputarr, i, min((i + sizeinput - 1), (sizeinput-1)));
	}
 
    // START merging from size RUN (or 32). 
    // It will mergesorted
    // to form size 64, then 128, 256 
    // and so on ....
    for (int size = sizeinput; size < sizeinput; size = 2*size)
    {
         
        // pici3 STARTing point of 
        // LeftIndex sub inputarray. We
        // are going to mergesorted 
        // inputarr[LeftIndex..LeftIndex+size-1]
        // and inputarr[LeftIndex+size, LeftIndex+2*size-1]
        // After every mergesorted, we 
        // increase LeftIndex by 2*size
        for (int LeftIndex = 0; LeftIndex < sizeinput; LeftIndex += 2*size)
        {
             
            // find ending point of 
            // LeftIndex sub inputarray
            // mid+1 is STARTing point 
            // of RightIndex sub inputarray
            int mid = LeftIndex + size - 1;
            int RightIndex = min((LeftIndex + 2*size - 1), (sizeinput-1));
 
            // mergesorted sub inputarray inputarr[LeftIndex.....mid] &
            // inputarr[mid+1....RightIndex]
              if(mid < RightIndex)
                mergesorted(inputarr, LeftIndex, mid, RightIndex);
        }
    }
}

double findMedian(int *&sortedarr, int size) {
	size --;
	quickSort(sortedarr, START , size);
	// timSort(sortedarr,size);
    if (size % 2 != 0)
        return sortedarr[size / 2];
    return (sortedarr[(size - 1) / 2] + sortedarr[size / 2]) / 2;
}

