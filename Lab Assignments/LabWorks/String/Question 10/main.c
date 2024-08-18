// Write a program to reverse the digits of an integer and store the result as another 
// integer.

#include <stdio.h>
#include<stdlib.h>

//function prototype
int reverse(int num);

int main() {
    int num = 12345;

    printf("The Reverse Representation of %d is %d\n", num, reverse(num));
    
    return 0;
}

//function to reverse digits of an integer
int reverse(int num){
    int result = 0;

    while(num){
        int digit = num % 10;
        result = result * 10 + digit;
        num /= 10;
    }

    return result;
}