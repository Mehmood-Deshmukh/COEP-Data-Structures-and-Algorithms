/*
Q15. Write code to find the second-largest element in a 1D array.
*/

#include <stdio.h>
#include <limits.h>

int findSecondLargest(int arr[], int size);

int main() {
    int arr[] = {12, 12, 24};

    int size = sizeof(arr) / sizeof(arr[0]);

    int secondLargest = findSecondLargest(arr, size);
    if(secondLargest == INT_MIN){
        printf("There is no second Largest element in the Array!\n");
    }else{
        printf("The second-largest element in the array is: %d\n", secondLargest);
    }

    return 0;
}

int findSecondLargest(int arr[], int size) {
    if (size < 2) {
        printf("Array size is less than 2!\n");
        return INT_MIN;
    }

    int first, second;

    if (arr[0] > arr[1]) {
        first = arr[0];
        second = arr[1];
    } else {
        first = arr[1];
        second = arr[0];
    }

    for (int i = 2; i < size; ++i) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    return second != first ? second : INT_MIN;
}