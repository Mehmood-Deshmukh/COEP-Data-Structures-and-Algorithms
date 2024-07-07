#include <stdio.h>

void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);
int main() {
    int arr[6] = {6, 3, 9, 8, 2, 5};
    printf("[ ");
    for (int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    printf("]");
    printf("\n");
    
    qsort(arr, 0 , 5);

    printf("[ ");
    for (int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    printf("]");
    printf("\n");
    
    return 0;
}


void qsort(int v[], int left, int right){
    if (left >= right){
        return;
    }

    int i, last;
    swap(v, left, right);
    last = left;

    for(i = left+1; i <= right; i++){
        if (v[i] < v[left]){
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);


    qsort(v, left, last-1);
    qsort(v, last + 1, right);
    
}


void swap(int v[], int i, int j){
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}