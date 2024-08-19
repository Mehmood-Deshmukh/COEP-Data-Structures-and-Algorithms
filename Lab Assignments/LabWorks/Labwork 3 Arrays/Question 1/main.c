// Q1.  Write a program that calculates the sum of squares of the elements of an integer array 
// of size 10. 

#include <stdio.h>

#define MAX_SIZE 10

int sumOfSquares(int arr[], int len);

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};

    printf("The sum of sqaures of all the elements in the Array is %d.\n", sumOfSquares(array, MAX_SIZE));

    return 0;
}

int sumOfSquares(int arr[], int len){
    int i, sum = 0;
    for(i = 0; i < len; i++){
        sum += (arr[i] *arr[i]);
    }

    return sum;
}