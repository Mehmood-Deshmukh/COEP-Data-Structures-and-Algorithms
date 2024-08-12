#include "./header.h"

void mergeSort(double arr[], int start, int end){
    if(start >= end){
        return;
    }

    int mid = start + (end - start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}

void merge(double arr[], int start, int mid, int end){
    int len1 = mid - start + 1;
    int len2 = end - mid;
    double temp1[len1];
    double temp2[len2];

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

void removeDuplicates(double arr[], int  *len){
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

void printArray(double arr[], int len){
    printf("[");
    for(int i = 0; i < len; i++){
        if(i == len - 1){
            printf("%.2lf", arr[i]);
        } else{
            printf("%.2lf, ", arr[i]);
        }
    }
    printf("]\n");
}