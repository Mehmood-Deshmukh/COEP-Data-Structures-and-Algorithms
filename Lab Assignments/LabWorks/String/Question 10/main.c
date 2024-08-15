#include <stdio.h>
#include<stdlib.h>

int reverse(int num);

int main() {
    int num = 12345;

    printf("The Reverse Representation of %d is %d\n", num, reverse(num));
    
    return 0;
}

int reverse(int num){
    int result = 0;

    while(num){
        int digit = num % 10;
        result = result * 10 + digit;
        num /= 10;
    }

    return result;
}
