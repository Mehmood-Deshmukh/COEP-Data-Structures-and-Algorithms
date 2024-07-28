#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

void swap(int *x, int *y);
void sort(int arr[], int len);

int main() {
    int len;
    int arr[MAX_SIZE];
    printf("Enter The length of Array to generate: \n");
    scanf("%d", &len);
    
    printf("Generated Array: ");
    for(int i = 0 ; i < len; i++){
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort(arr, len);

    printf("Sorted Array: ");
    for(int i = 0 ; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int arr[], int len){
    int i, j, min;
    for(i = 0; i < len - 1; i++){
        min = i;
        for(j = i + 1; j < len; j++){
            if(arr[j] < arr[min]) min = j;
        }
        swap(&arr[i], &arr[min]);
    }
}