// Q6. Write C program to shift all elements of an array by n locations to right or left in 
// circular fashion. Take all inputs from user. 

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

void circularShiftRight(int arr[], int size, int n);
void circularShiftLeft(int arr[], int size, int n);
void printArray(int arr[], int len);

int main() {
	int arr[MAX_SIZE];
	for(int i = 0; i < MAX_SIZE; i++) arr[i] = rand() % 100;

	printArray(arr, MAX_SIZE);

	int rightShift = 4;
	circularShiftRight(arr, MAX_SIZE, rightShift);
	printf("Array after %d shifts to the right: ", rightShift);
	printArray(arr, MAX_SIZE);
	
	int leftShift = 4;
	circularShiftLeft(arr, MAX_SIZE, leftShift);
	printf("Array after %d shifts to the left: ", leftShift);
	printArray(arr, MAX_SIZE);
    
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

void circularShiftRight(int arr[], int size, int n) {
	n %= size;
	for (int i = 0; i < n; ++i) {
		int temp = arr[size - 1];
		for (int j = size - 1; j > 0; --j) {
			arr[j] = arr[j - 1];
		}
		arr[0] = temp;
	}	
}	

void circularShiftLeft(int arr[], int size, int n) {
	n %= size;
	for (int i = 0; i < n; ++i) {
		int temp = arr[0];
		for (int j = 0; j < size - 1; ++j) {
			arr[j] = arr[j + 1];
		}
		arr[size - 1] = temp;
	}	
}