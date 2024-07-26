#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
void stackEmpty();

int main() {
    stackEmpty();
    return 0;
}

void stackEmpty(){
    fprintf(stderr, "Stack is Empty, cannot remove element");
    exit(EXIT_FAILURE);
}