#include <stdio.h>
#include <stdlib.h>


void countSortInRadix(int A[], int lenA, int place){
    int* outputArr = (int*)malloc(sizeof(int) * lenA);
    for(int i= 0; i<lenA; i++)
        outputArr[i] = 0;
    int countArray[10] = {0};
    for(int i = 0; i<lenA; i++)
        countArray[ (A[i]/place)%10 ] ++;

    for(int i = 1; i<10; i++)
        countArray[i] += countArray[i-1];


    int j = 0;
    for(int i = lenA-1; i>=0; i--){
        outputArr[ countArray[ (A[i]/place)%10 ] - 1] = A[i];
        countArray[ (A[i] / place)%10 ]--;
    }

    for(int i = 0; i<lenA; i++)
        A[i] = outputArr[i];
    free(outputArr);
}

void radixSort(int A[], int lenA){
    int max = A[0];
    for(int i = 1; i<lenA; i++){
        if(A[i] > max)
            max= A[i];
        if(A[i] < 0){
            printf("\nRadix Sort is only for positive numbers.\n");
            return;
        }
    }
    for(int place = 1; max/place>0; place*=10){
        countSortInRadix(A, lenA, place);
    }
}


int main()
{
    int A[] = {1, 5, 8, 45, 4285, 8, 856852, 12548, 0, 198, 7522123, 4, 2, 6, 25, 35, 21, 35, 6,  12};
    int lenA = sizeof(A)/sizeof(A[0]);
    radixSort(A, lenA);
    for(int i = 0; i<lenA; i++)
        printf("%d, ", A[i]);

    return 0;
}
