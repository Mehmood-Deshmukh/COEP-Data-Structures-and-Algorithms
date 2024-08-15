/*
Question: Generate ten random numbers in the range [1, 100] using the rand() function.
Initialize an array of integers with values ranging from 50 to 100 (both inclusive) and display the contents.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
int main() {
    int array[MAX_SIZE];
    
    srand(time(NULL));

    printf("An array with random values ranging from 50 to 100:\n");

    for (int i = 0; i < MAX_SIZE; ++i) {
        array[i] = rand() % 51 + 50; 
        printf("%d ", array[i]);
    }

    return 0;
}