// Q2. Display array elements in reverse. ie from last to first.

#include <stdio.h>

#define MAX_SIZE 10

void displayReverse(int arr[], int len);

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};

    displayReverse(array, MAX_SIZE);

    return 0;
}

void displayReverse(int arr[], int len){
    int i;
    printf("Displaying array in reverse order: ");
    for(i = len - 1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    return;
}