#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define INITIAL_SIZE 1024  


int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
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

    srand(time(NULL)); 
    int key = arr[rand() % arr_size]; 

    int result = linearSearch(arr, arr_size, key);

    if (result != -1) {
        printf("Linear Search: Element %d found at index %d\n", key, result);
    } else {
        printf("Linear Search: Element %d not found\n", key);
    }

    free(arr);
    return 0; 
}
