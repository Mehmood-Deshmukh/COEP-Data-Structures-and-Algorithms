// Q4.Display elements of array in triangle pattern. Use formatting to get a uniform display. 
// Eg: 
// A = {60,700,80,900,10} 
// Output: 
// 60 
// 60  700 
// 60  700  80 
// 60  700  80  900 
// 60  700  80  900   10 


#include <stdio.h>

#define MAX_SIZE 10

void displayTriangle(int arr[], int len);

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};

    displayTriangle(array, MAX_SIZE);

    return 0;
}

void displayTriangle(int arr[], int len){
    int i, j;

    for(i = 0; i < len; i++){
        for(j = 0; j <= i; j++){
            printf("%-3d", arr[j]);
        }

        printf("\n");
    }
}