#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int size);

int main(int argv, char *argc[]){
    if(argv < 2){
        printf("Usage: %s <file with numbers to sort>\n", argc[0]);
        exit(1);
    }

    FILE *file = fopen(argc[1], "r");
    if(file == NULL){
        perror("Error opening file: ");  
        exit(1);
    }

    int size;
    fscanf(file, "%d", &size);

    int *array = (int *) malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        fscanf(file, "%d", &array[i]);
    }

    fclose(file);

    int *array_copy = (int *) malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        array_copy[i] = array[i];
    }

    printf("Sorting using max heap\n");

    printf("Before sorting: ");
    print_array(array, size);

    heap_sort_max_heap(array, size);

    printf("After sorting: ");
    print_array(array, size);

    printf("\n");

    printf("Sorting using min heap\n");

    printf("Before sorting: ");
    print_array(array_copy, size);

    heap_sort_min_heap(array_copy, size);

    printf("After sorting: ");
    print_array(array_copy, size);

    free(array);
    free(array_copy);

    return 0;
}

void print_array(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
}