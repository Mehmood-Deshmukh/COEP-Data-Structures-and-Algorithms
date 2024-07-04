#include <stdio.h>

int binsearch(int x, int v[], int n);
int main() {
    int v[5] = {1, 2, 6, 8, 9};
    printf("%d", binsearch(8, v, 5));
    return 0;
}

int binsearch(int x, int v[], int n){
    int low = 0, high = n - 1;

    while (low <= high){
        int mid = low + (high - low)/2;
        if (v[mid] == x){
            return mid;
        }else if (x < v[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}