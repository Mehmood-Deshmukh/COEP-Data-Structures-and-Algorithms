// 15. The Average of numbers from 1 to 50

#include <stdio.h>

void printOdd(int start, int end);
int main() {
    int m = 1;
    int n = 50;
    printOdd(m, n);
    return 0;
}


void printOdd(int start, int end){
    int i;
    for(i = start; i <= end; i++){
        if(i % 2 != 0) printf("%d ", i);
    }
}