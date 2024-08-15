/*
Q13. You have 2 arrays of size 5 each having elements in sorted order. Create a new array 
of 10 having elements of the both the arrays in sorted order. 
*/

#include <stdio.h>

void printArray(int arr[], int len);
void merge(int A[], int B[], int C[]);

int main() {
    int A[] = {45, 50, 70, 85, 90};
    int B[] = {30, 40, 60, 75, 80};
    int C[10];

    merge(A, B, C);

    printf("Merged array C:\n");
    printArray(C, 10);

    return 0;
}

void printArray(int arr[], int len){
    printf("[");
    for(int i = 0; i < len; i++){
        if(i == len - 1){
            printf("%d", arr[i]);
        } else{
            printf("%d, ", arr[i]);
        }
    }
    printf("]\n");
}


void merge(int A[], int B[], int C[]){
    int len = 5;
    int i = 0, j = 0;
    int newlen = 0;

    while(i < len && j < len){
        if(A[i] < B[j]){
            C[newlen++] = A[i++];
        }else {
            C[newlen++] = B[j++];
        }
    }

    while(i < len){
        C[newlen++] = A[i++];
    }

    while(i < len){
        C[newlen++] = B[j++];
    }
}