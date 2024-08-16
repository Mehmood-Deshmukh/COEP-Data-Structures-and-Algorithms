#include <stdio.h>


int gcd(int a, int b);

int main() {
    int num1 = 16;
    int num2 = 12;

    printf("The greatest common divisor of %d and %d is %d", num1, num2, gcd(num1, num2));
    return 0;
}

int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}