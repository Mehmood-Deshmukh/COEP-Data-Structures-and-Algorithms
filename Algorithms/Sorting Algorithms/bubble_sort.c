#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 2
void bubble_sort(int arr[], int n);
void swap(int *a, int *b);
void get_input(int **arr, int *index);


int main(int argc, char *argv[]){
    int *arr = (int *)malloc(INITIAL_SIZE * sizeof(int));
    int index = 0;
    get_input(&arr, &index);

    bubble_sort(arr, index);

    for(int i = 0; i < index; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        int swapped = 0;
        for(j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
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