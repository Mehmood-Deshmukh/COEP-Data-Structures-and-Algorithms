//  Write a function to find gcd() of 2 numbers. (See Dromey for this, after you have tried 
// your bit)

#include <stdio.h>

//function prototype
int gcd(int a, int b);

int main() {
    int num1 = 16;
    int num2 = 12;

    printf("The greatest common divisor of %d and %d is %d", num1, num2, gcd(num1, num2));
    return 0;
}

//my solution
// int gcd(int a, int b){
//     if(b == 0) return a;

//     return gcd(b, a % b);
// }

// dromey's solution
int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}