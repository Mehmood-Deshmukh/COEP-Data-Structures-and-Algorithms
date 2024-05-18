#include<stdio.h>

int main(){
    int c;
    printf("%d", (c = getchar()) != EOF);
    return 0;
}