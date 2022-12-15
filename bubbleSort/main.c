#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int A[], int lenA){
    for(int i = 0; i<lenA-1; i++){
        int flag = 0;
        for(int j = 0; j < lenA-i-1; j++){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            return;
    }
}


int main()
{

    int A[] = {1, 5, 8, 4, -2, 6, 25, 35, -21, 35, 6,  12};
    int lenA = sizeof(A)/sizeof(A[0]);
    bubbleSort(A, lenA);
    for(int i = 0; i<lenA; i++)
        printf("%d, ", A[i]);

    return 0;
}
