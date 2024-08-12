#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define INITIAL_SIZE 1024  

void merge(long arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    long *L = (long *)malloc(n1 * sizeof(long)); 
    long *R = (long *)malloc(n2 * sizeof(long)); 

    if (L == NULL || R == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }

    free(L);
    free(R);
} 

void mergeSort(long arr[], int l, int r) { 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r); 
    } 
} 

void printArray(long A[], int size) { 
    for (int i = 0; i < size; i++) 
        printf("%ld ", A[i]); 
    printf("\n"); 
} 

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

    mergeSort(arr, 0, arr_size - 1); 

    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 

    free(arr);
    return 0; 
}
