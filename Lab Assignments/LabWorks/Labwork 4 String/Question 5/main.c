//  Write a function to find lcm() of 2 numbers

#include <stdio.h>

//function prototypes
int gcd(int a, int b);
int lcm(int a, int b);

int main() {
    int num1 = 16;
    int num2 = 12;

    printf("The lowest common multiple of %d and %d is %d", num1, num2, lcm(num1, num2));
    return 0;
}

//function for calculating the GCD
int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// using the formula LCM = a * b / GCD
int lcm(int a, int b){
    return a * b / gcd(a, b);
}