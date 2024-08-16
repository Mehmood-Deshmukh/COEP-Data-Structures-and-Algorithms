// 1. Write a program to read 10 integers. Display these numbers by printing three 
// numbers in a line separated by commas. 

#include <stdio.h>

#define MAX_SIZE 10

void displayIntegers(int arr[], int size);

int main() {
    int array[MAX_SIZE];
    printf("Enter %d Integers:\n", MAX_SIZE);
    for(int i = 0; i < MAX_SIZE; i++) scanf("%d", &array[i]);

    displayIntegers(array, MAX_SIZE);

    return 0;
}

void displayIntegers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if ((i + 1) % 3 == 0 || i == size - 1) {
            printf("\n");
        } else {
            printf(", ");
        }
    }
}