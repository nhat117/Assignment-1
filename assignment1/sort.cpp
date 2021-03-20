#include <iostream>
using namespace std;
// Function Prototype
void swap(int* a, int* b) ;
int partition (int *InputArray, int *FirstElement, int *LastElement);
//Swap number
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
// Partition part of the quick sort function
int partition (int *InputArray, int *FirstElement, int *LastElement) 
{ 
    int pivot = InputArray [*LastElement]; // pivot point
    int i = (*FirstElement - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int i2 = *FirstElement; i2 <= *LastElement - 1; i2++) 
    { 
        // If current element is smaller than the pivot 
        if (InputArray [i2] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap( InputArray[i], InputArray[i2]); 
        } 
    } 
    swap( InputArray[i + 1],  InputArray[*LastElement]); 
    return (i + 1); 
}
// Implement quicksort


