/*
Q14. Populate an array of size 100 with values generated randomly between 1 to 1000.
Copy all the numbers divisible by 8 or 15 to a new array. Display both arrays.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void populateArray(int arr[], int size);

void getDivisibleNumbers(int source[], int sourceSize, int destination[], int *destSize);

void printArray(int arr[], int len);

int main() {
    int array[MAX_SIZE];
    int divisibleArray[MAX_SIZE];  
    int length = 0;

    srand(time(NULL));
    populateArray(array, MAX_SIZE);

    getDivisibleNumbers(array, MAX_SIZE, divisibleArray, &length);

    printf("The Original array:\n");
    printArray(array, MAX_SIZE);

    printf("The Divisible array:\n");
    printArray(array, length);

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

void populateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000 + 1;
    }
}

void getDivisibleNumbers(int src[], int srclen, int dest[], int *destlen) {
    for (int i = 0; i < srclen; ++i) {
        if (src[i] % 8 == 0 || src[i] % 15 == 0) {
            dest[(*destlen)++] = src[i];
        }
    }
}