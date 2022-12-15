#include <stdio.h>

#include <stdlib.h>

void selectionSort(int A[], int lenA){
    for(int i = 0; i<lenA-1; i++){
        for(int j = i+1; j<lenA; j++){
            if(A[j] < A[i]){
                // swap(A[i], A[j]);
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
    }
}




int main()
{
    int A[] = {1, 5, 8, 4, -2, 6, 25, 12};
    int lenA = sizeof(A)/sizeof(A[0]);
    selectionSort(A, lenA);
    for(int i = 0; i<lenA; i++)
        printf("%d, ", A[i]);
    return 0;
}
