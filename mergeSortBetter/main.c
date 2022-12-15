#include <stdio.h>
#include <stdlib.h>


void mergeSortedArrs(int A[], int low, int mid, int high){
    int i = low, j = mid+1, k = 0;
    int tempArr[100];
    while(i <= mid && j <= high){
        if(A[i] <= A[j] )
            tempArr[k++] = A[i++];
        else
            tempArr[k++] = A[j++];
    }
    while(i <= mid)
        tempArr[k++] = A[i++];
    while(j <= high)
        tempArr[k++] = A[j++];
    for(i = low; i<= high; i++)
        A[i] = tempArr[i-low];
}



void mergeSort(int A[], int low, int high){
    if(low >= high)
        return;
    int mid = (low+high)/2;
    mergeSort(A, low, mid);
    mergeSort(A, mid+1, high);
    mergeSortedArrs(A, low, mid, high);
}








int main()
{
    int A[] = {1, 5, 8, 4, -2, 6, 25, 12, 45, -21, -9, 25, -21};
    int lenA = sizeof(A)/sizeof(A[0]);
    mergeSort(A, 0, lenA-1);
    for(int i = 0; i<lenA; i++)
        printf("%d, ", A[i]);

    return 0;
}
