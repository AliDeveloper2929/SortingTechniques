#include <stdio.h>
#include <stdlib.h>

void countSort(int A[], int lenA){
    if(lenA <= 1)
        return;
    int min = A[0];
    int max = A[0];
    for(int i = 1; i<lenA; i++){
        if(A[i] < min)
            min = A[i];
        if(A[i] > max)
            max = A[i];
    }
    if(min <0){
        printf("Count sort is only for positive numbers\n");
        return;
    }
    int arrLen = max-min+1;
    int* tempArr = (int*)malloc(sizeof(int) * arrLen);
    for(int i = 0; i< arrLen; i++)
        tempArr[i] = 0;
    for(int i = 0; i<lenA; i++)
        tempArr[ A[i]-min ] ++;

    int j = 0;
    for(int i = 0; i<arrLen; i++){
        if(tempArr[i] != 0){
            while(tempArr[i] != 0){
                A[j++] = i+min;
                tempArr[i]--;
            }
        }
    }

}



int main()
{
    int A[] = {1, 5, 8, 4, 2, 6, 25, 12, 0, 1, 45, 21, 9, 25, 21};
    int lenA = sizeof(A)/sizeof(A[0]);
    countSort(A, lenA);
    for(int i = 0; i<lenA; i++)
        printf("%d, ", A[i]);

    return 0;
}
