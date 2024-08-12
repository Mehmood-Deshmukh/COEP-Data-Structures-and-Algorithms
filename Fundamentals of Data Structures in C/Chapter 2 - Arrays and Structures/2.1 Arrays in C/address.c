#include <stdio.h>

void print(int *ptr, int rows);
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    print(arr, 5);
    return 0;
}

void print(int *ptr, int rows){
    int i;
    printf("Address Contents\n");
    for(i = 0; i < rows; i++){
        printf("%8p%5d\n", ptr+i, *(ptr + i));
    }

    printf("\n");
}