#include <stdio.h>

void shellsort(int v[], int n);
int main() {
    int arr[5] = {5, 4, 3, 1, 0};
    shellsort(arr, 5);
    return 0;
}

void shellsort(int v[], int n){
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2){
        for (i = gap; i < n; i++){
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
        
    }

    for (int k = 0; k < n; k++){
        printf("%d ", v[k]);
    }
    
}