/*
Q5.You know the size of an integer array. Can you find the number of elements in it? How?
*/

#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int numberOfElements = sizeof(array) / sizeof(array[0]);
    printf("Number of elements in the array: %d\n", numberOfElements);

    return 0;
}