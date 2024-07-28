#include <stdio.h>

int main() {
    int i, *pi;
    pi = &i;
    i = 10;
    *pi = 20;
    printf("i = %d\n", i);
    return 0;
}