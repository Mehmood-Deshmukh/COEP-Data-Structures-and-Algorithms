// Q7.Delete all duplicate elements from an array retaining the first occurrence. Note: 
// Array elements cannot be deleted. shift and replace can be done. 


#include <stdio.h>
#define MAX_SIZE 10

void removeDuplicates(int arr[], int  *len);
void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);
void printArray(int arr[], int len);

int main() {
	int arr[] = {4, 2, 9, 4, 3, 9, 7, 1, 4, 2};
    int length = sizeof(arr) / sizeof(arr[0]);
    printf("Your Array is: ");
	printArray(arr, length);

    removeDuplicates(arr, &length);

    printf("After removing duplicates: ");
	printArray(arr, length);
    
    return 0;
}

void printArray(int arr[], int len){
    printf("[");
    for(int i = 0; i < len; i++){
        if(i == len - 1){
            printf("%d", arr[i]);
        } else{
            printf("%d, ", arr[i]);
        }
    }
    printf("]\n");
}

void mergeSort(int arr[], int start, int end){
    if(start >= end){
        return;
    }

    int mid = start + (end - start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}

void merge(int arr[], int start, int mid, int end){
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int temp1[len1];
    int temp2[len2];

    for(int i = 0; i < len1; i++){
        temp1[i] = arr[start + i];
    }

    for(int i = 0; i < len2; i++){
        temp2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int newlen = start;

    while(i < len1 && j < len2){
        if(temp1[i] < temp2[j]){
            arr[newlen++] = temp1[i++];
        }else {
            arr[newlen++] = temp2[j++];
        }
    }

    while(i < len1){
        arr[newlen++] = temp1[i++];
    }

    while(i < len1){
        arr[newlen++] = temp2[j++];
    }
}

void removeDuplicates(int arr[], int  *len){
    int length = *len;
    mergeSort(arr, 0 , length-1);
    int newlen = 1;
    for(int i = 1; i < length; i++){
        if(arr[i] != arr[newlen - 1]){
            arr[newlen++] = arr[i];
        }
    }
    *len = newlen;
}