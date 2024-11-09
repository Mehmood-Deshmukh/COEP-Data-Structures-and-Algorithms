#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define INITIAL_SIZE 1024  


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


int main() {
    int *arr = (int *)malloc(INITIAL_SIZE * sizeof(int));
    if (arr == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    int value;
    int capacity = INITIAL_SIZE;
    int index = 0;
    
    while (scanf("%d", &value) != EOF) {
        if (index >= capacity) {
            capacity *= 2;
            int *new_arr = (int *)realloc(arr, capacity * sizeof(int));
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

    srand(time(NULL)); // Seed the random number generator
    int key = arr[rand() % arr_size]; // Random element from the array



    int result = binarySearch(arr, arr_size, key);

    if (result != -1) {
        printf("Binary Search: Element %d found at index %d\n", key, result);
    } else {
        printf("Binary Search: Element %d not found\n", key);
    }

    free(arr);
    return 0; 
}
