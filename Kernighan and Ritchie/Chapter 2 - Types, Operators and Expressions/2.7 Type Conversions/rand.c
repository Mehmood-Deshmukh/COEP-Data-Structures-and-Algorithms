#include <stdio.h>

unsigned long int next = 1;

int rand();
void srand(unsigned int seed);

int main() {
    srand(90);
    printf("%d", rand());
    return 0;
}

int rand(void){
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed){
    next = seed;
}