#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define INITIAL_SIZE 2 


int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void get_input(int **arr, int *index) {
    if (!*arr) {
        perror("Failed to allocate memory");
        return;
    }

    int value;
    int capacity = INITIAL_SIZE;
    
    while (scanf("%d", &value) != EOF) {
        printf("value: %d\n", value);
        if (*index >= capacity) {
            capacity *= 2;
            int *new_arr = (int *)realloc(*arr, capacity * sizeof(int));
            if (!new_arr) {
                perror("Failed to allocate memory");
                free(*arr);
                return;
            }
            *arr = new_arr;
        }
        (*arr)[(*index)++] = value;
    }
}

int main() {
    int *arr = (int *) malloc(INITIAL_SIZE * sizeof(int));
    int index = 0;

    get_input(&arr, &index);

    int arr_size = index;
    if (arr_size == 0) {
        printf("No elements in the array\n");
        free(arr);
        return 0;
    }

    printf("Array: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    srand(time(NULL)); 
    int key = arr[rand() % arr_size]; 



    int result = binarySearch(arr, arr_size, key);

    if (result != -1) {
        printf("Binary Search: Element %d found at index %d\n", key, result);
    } else {
        printf("Binary Search: Element %d not found\n", key);
    }

    free(arr);
    return 0; 
}
