//Function definition
// swap two elements 
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
/*  takes last element as pivot point, places 
the pivot element at its correct position in sorted 
xArrayay, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivotpoint */
int divide (int *&xArray, int Startindex, int Lastindex) 
{ 
    int pivot = xArray[Lastindex]; // pivot 
    int i = (Startindex - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int i2 = Startindex; i2 <= Lastindex - 1; i2++) 
    { 
        // If current element is smaller than the pivot 
        if (xArray[i2] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&xArray[i], &xArray[i2]); 
        } 
    } 
    swap(&xArray[i + 1], &xArray[Lastindex]); 
    return (i + 1); 
} 
 
/* The main function that implements QuickSort 
xArray[] --> xArrayay to be sorted, 
Startindex --> Starting index, 
Lastindex --> Ending index */
void quickSort(int *&xArray, int Startindex, int Lastindex) 
{
    if (Startindex < Lastindex) 
    { 
        /* pivot is divideing index, xArray[p] is now 
        at right place */
        int pivot = divide(xArray, Startindex, Lastindex); 
 
        // Separately sort elements before 
        // divide and after divide 
        quickSort(xArray, Startindex, pivot - 1); 
        quickSort(xArray, pivot + 1, Lastindex); 
    } 
} 
 
/* Function to print an xArrayay */
double findMedian(int *&sortedarr, int &size) {
    if (size % 2 != 0)
        return sortedarr[size / 2];
    return (sortedarr[(size - 1) / 2] + sortedarr[size / 2]) / 2;
}