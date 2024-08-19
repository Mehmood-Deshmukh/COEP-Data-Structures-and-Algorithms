// Q3 Write a program to search for an element accepted from user in an array of floating
// point values of size 50. Display the index if element is found else display message 
// Not Found. 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 50
#define EPSILON 0.01

int search(float arr[], int len, float target);
void printArray(float arr[], int len);

int main() {
    float array[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++){
        array[i] = ((float)rand() / (float)RAND_MAX) * 100.0;
    }
    printArray(array, MAX_SIZE);
    float target;
    printf("Enter target to Find: \n");
    scanf("%f", &target);
    int index = search(array, MAX_SIZE, target);

    if(index == -1){
        printf("Couldn't find %.2f in the array\n", target);
    }else{
        printf("found %.2f at the index %d in the array\n", target, index);
    }

    return 0;
}
void printArray(float arr[], int len){
    printf("[");
    for(int i = 0; i < len; i++){
        if(i == len - 1){
            printf("%.2f", arr[i]);
        } else{
            printf("%.2f, ", arr[i]);
        }
    }
    printf("]\n");
}

int search(float arr[], int len, float target){
    int i = 0;
    for(i = 0; i < len; i++){
        if(fabs(arr[i] - target) < EPSILON) return i;
    }

    return -1;
}
