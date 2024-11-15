#include <stdio.h>
#include <stdlib.h>
#include "./Heap/header.h"

#define INITIAL_SIZE 2
void get_input(int **arr, int *index);


int main(int argc, char *argv[]){
    int *arr = (int *)malloc(INITIAL_SIZE * sizeof(int));
    int index = 0;
    get_input(&arr, &index);

    heap_sort_max_heap(arr, index);

    for(int i = 0; i < index; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
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