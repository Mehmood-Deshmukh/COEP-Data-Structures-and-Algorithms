#include<stdio.h>

int main(){
    printf("Hello, World!\c");

    // Warning:
    // ./Exercise_1-2.c: In function 'main':
    // ./Exercise_1-2.c:4:12: warning: unknown escape sequence: '\c'
    // printf("Hello, World!\c");
    //         ^~~~~~~~~~~~~~~~~

    // Output:
    // Hello, World!c
    return 0;
}