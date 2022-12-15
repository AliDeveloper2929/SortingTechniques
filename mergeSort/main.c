#include <stdio.h>
#include <stdlib.h>

void mergeSortedArrs(int A1[], int len1, int A2[], int len2, int A[], int lenA){
    int i, j, k;
    i = j = k = 0;

    while( i < len1 && j < len2 ){
        if(A1[i] <= A2[j])
            A[k++] = A1[i++];
        else
            A[k++] = A2[j++];
    }

    while(i< len1)
        A[k++] = A1[i++];
    while(j<len2)
        A[k++] = A2[j++];
    return;
}



void mergeSort(int A[], int lenA){
    if(lenA<2)
        return;

    int len1 = lenA/2;
    int len2 = lenA-len1;
    int A1[len1];
    int A2[len2];

    for(int i = 0; i<len1; i++)
        A1[i] = A[i];
    for(int i = 0; i<len2; i++)
        A2[i] = A[i+len1];

    mergeSort(A1, len1);
    mergeSort(A2, len2);

    mergeSortedArrs(A1, len1, A2, len2, A, lenA);
}




int main()
{
    int A[] = {1, 5, 8, 4, -2, 6, 25, 12, 45, -21, -9, 25, -21};
    int lenA = sizeof(A)/sizeof(A[0]);
    mergeSort(A, lenA);
    for(int i = 0; i<lenA; i++)
        printf("%d, ", A[i]);
    return 0;
}
