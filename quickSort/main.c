#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getRandomisedPartition(int A[], int low, int high){
    srand(time(0));
    int randIndex = (low + rand()%(high-low+1));
    int temp = A[randIndex];
    A[randIndex] = A[high];
    A[high] = temp;
    int pivotIndex = low;
    for(int i = low; i<high; i++){
        if(A[i] < A[high]){
            int temp = A[pivotIndex];
            A[pivotIndex] = A[i];
            A[i] = temp;
            pivotIndex++;
        }
    }
    int temp2 = A[pivotIndex];
    A[pivotIndex] = A[high];
    A[high] = temp2;
    return pivotIndex;
}


void quickSort(int A[], int low, int high){
    if(low >= high)
        return;
    int pivotIndex = getRandomisedPartition(A, low, high);
    quickSort(A, low, pivotIndex-1);
    quickSort(A, pivotIndex+1, high);
}







int main()
{
    int A[] = {1, 5, 8, 4, -2, 6, 25, 12, 45, -21, -9, 25, -21};
    int lenA = sizeof(A)/sizeof(A[0]);
    quickSort(A, 0, lenA-1);
    for(int i = 0; i<lenA; i++)
        printf("%d, ", A[i] );

    return 0;
}
