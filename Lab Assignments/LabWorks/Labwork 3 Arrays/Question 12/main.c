/*
Q12. C program to find the nearest lesser and greater element in an array.
*/

#include <stdio.h>
#include <limits.h>

void findNearestElements(int arr[], int size, int key, int *nearestLesser, int *nearestGreater) {
    *nearestLesser = INT_MIN;
    *nearestGreater = INT_MAX;

    for (int i = 0; i < size; ++i) {
        if (arr[i] < key && arr[i] > *nearestLesser) {
            *nearestLesser = arr[i];
        }
        if (arr[i] > key && arr[i] < *nearestGreater) {
            *nearestGreater = arr[i];
        }
    }
}

int main() {
    int arr[] = {1, 8, 2,  9, 12, 23, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the key element: ");
    scanf("%d", &key);

    int neareslesser, nearestGreater;

    findNearestElements(arr, size, key, &neareslesser, &nearestGreater);

    printf("Nearest lesser element: %d\n", (neareslesser != INT_MIN) ? neareslesser : -1);
    printf("Nearest greater element: %d\n", (nearestGreater != INT_MAX) ? nearestGreater : -1);

    return 0;
}