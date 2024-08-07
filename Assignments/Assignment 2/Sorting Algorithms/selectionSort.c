#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define INITIAL_SIZE 1024  

void swap(long *x, long *y);
void selectionSort(long arr[], int len);
void printArray(long A[], int size);

int main() {
    long *arr = (long *)malloc(INITIAL_SIZE * sizeof(long));
    if (arr == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    long value;
    int capacity = INITIAL_SIZE;
    int index = 0;

    while (scanf("%ld", &value) != EOF) {
        if (index >= capacity) {
            capacity *= 2;
            long *new_arr = (long *)realloc(arr, capacity * sizeof(long));
            if (new_arr == NULL) {
                perror("Failed to allocate memory");
                free(arr);
                return EXIT_FAILURE;
            }
            arr = new_arr;
        }
        arr[index++] = value;
    }

    int arr_size = index;

    if (arr_size == 0) {
        printf("No numbers provided.\n");
        free(arr);
        return 0;
    }

    printf("Given array is \n"); 
    printArray(arr, arr_size); 

    selectionSort(arr, arr_size); 

    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 

    free(arr);
    return 0; 
}

void swap(long *x, long *y){
    long temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(long arr[], int len){
    int i, j, min;
    for(i = 0; i < len - 1; i++){
        min = i;
        for(j = i + 1; j < len; j++){
            if(arr[j] < arr[min]) min = j;
        }
        swap(&arr[i], &arr[min]);
    }
}

void printArray(long A[], int size) { 
    for (int i = 0; i < size; i++) 
        printf("%ld ", A[i]); 
    printf("\n"); 
} 