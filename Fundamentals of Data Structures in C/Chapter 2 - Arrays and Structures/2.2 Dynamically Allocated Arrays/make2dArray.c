#include <stdio.h>
#include <stdlib.h>

int **make2dArray(int rows, int cols);
int main() {
    int **myArray;
    myArray = make2dArray(5, 10);
    myArray[0][0] = 12;
    printf("%d", myArray[0][0]);
    free(myArray);
    return 0;
}

int **make2dArray(int rows, int cols){
    int **x, i;
    
    x = (int **)malloc(sizeof(*x) * rows);

    for(i = 0; i < rows; i++){
        x[i] = (int *)malloc(sizeof(**x));
    }

    return x;
}