#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[], int lenA){
    for(int i = 1; i<lenA; i++){
        int numIndex = i;
        while(numIndex>0 && A[numIndex-1] > A[numIndex]){
            // swap
            int temp = A[numIndex];
            A[numIndex] = A[numIndex-1];
            A[numIndex-1] = temp;
            numIndex--;
        }
    }
}







int main()
{
    int A[] = {1, 5, 8, 4, -2, 6, 25, 35, -21, 35, 6,  12};
    int lenA = sizeof(A)/sizeof(A[0]);
    insertionSort(A, lenA);
    for(int i = 0; i<lenA; i++)
        printf("%d, ", A[i]);

    return 0;
}
