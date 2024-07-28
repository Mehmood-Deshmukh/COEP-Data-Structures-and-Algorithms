#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101

int compare(int x, int y);
int binarySearch(int arr[], int target, int len);
void sort(int arr[], int len);
void swap(int *x, int *y);

int main() {
    int len, target, index;
    int arr[MAX_SIZE];
    printf("Enter The length of Array to generate: \n");
    scanf("%d", &len);

    for(int i = 0 ; i < len; i++){
        arr[i] = rand() % 100;
    }
    sort(arr, len);
    
    printf("Generated Array: ");
    for(int i = 0 ; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter The Target to search: \n");
    scanf("%d", &target);
    index = binarySearch(arr, target, len);

    if(index == -1){
        printf("Target Not found in the Array!");
    }else{
        printf("Target found at the Index %d!", index);

    }
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

int compare(int x, int y){
    if(x == y){
        return 0;
    }else if(x > y){
        return 1;
    }else{
        return -1;
    }
}

int binarySearch(int arr[], int target, int len){
    int left, right, mid;
    left = 0, right = len - 1;


    while (left <= right){
        mid = left - (left - right)/2;
        switch (compare(target, arr[mid])){
        case 0:
            return mid;
            break;
        case 1:
            left = mid + 1;
            break;
        case -1:
            right = mid - 1;
        default:
            break;
        }
    }
    
    return -1;
}