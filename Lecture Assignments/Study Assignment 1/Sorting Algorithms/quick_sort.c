#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 2
void quick_sort(int arr[], int n);
void swap(int *a, int *b);
void get_input(int **arr, int *index);


int main(int argc, char *argv[]){
    int *arr = (int *)malloc(INITIAL_SIZE * sizeof(int));
    int index = 0;
    get_input(&arr, &index);

    quick_sort(arr, index);

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

void partition(int arr[], int n, int *pivot){
    int i = 0, j = n - 1;
    int p = arr[0];
    while(i < j){
        while(arr[i] <= p) i++;
        while(arr[j] > p) j--;
        if(i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[0], &arr[j]);
    *pivot = j;
}

void quick_sort(int arr[], int n){
    if(n <= 1) return;
    int pivot;
    partition(arr, n, &pivot);
    quick_sort(arr, pivot);
    quick_sort(arr + pivot + 1, n - pivot - 1);
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