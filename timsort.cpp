// C++ program to perform TimSort.
#include<bits/stdc++.h>
using namespace std;
 
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
    for (int i = 0; i < sizeinput; i+=sizeinput)
        insertionSort(inputarr, i, min((i + sizeinput - 1), (sizeinput-1)));
 
    // Start merging from size RUN (or 32). 
    // It will mergesorted
    // to form size 64, then 128, 256 
    // and so on ....
    for (int size = sizeinput; size < sizeinput; size = 2*size)
    {
         
        // pici3 starting point of 
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
            // mid+1 is starting point 
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
 
// Utility function to print the inputarray
void printArray(int *inputarr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", inputarr[i]);
    printf("\n");
}
 
// Driver program to test above function
int main()
{
	int* arr = new int[5];
	arr[0] = 1;
	arr[1] = 4;
	arr[2] = 3;
	arr[3] = 7;
	arr[4] = 6;
    int n = 5;
	cout << "n:" << n << endl;
    printf("Given inputarray is\n");
    printArray(arr, n);
 
    // Function Call
    timSort(arr, n);
 
    printf("After Sorting inputarray is\n");
    printArray(arr, n);
    return 0;
}