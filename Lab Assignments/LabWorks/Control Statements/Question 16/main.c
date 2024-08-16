// 16. Write a program to print all prime numbers from m to n.

#include <stdio.h>

void printPrime(int start, int end);
int isPrime(int num);

int main() {
    int m = 1;
    int n = 50;
    printPrime(m, n);
    return 0;
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void printPrime(int start, int end){
    int i;
    for(i = start; i <= end; i++){
        if(isPrime(i)) printf("%d ", i);
    }
}