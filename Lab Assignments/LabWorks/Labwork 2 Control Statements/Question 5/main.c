//     5. Write a program to read a floating point number. Display the rightmost digit of the 
// integral part of the number. 

#include <stdio.h>


int main() {
    float num;
    printf("Enter a floating point number: ");
    scanf("%f", &num);

    int integerPart = (int)num;

    printf("Rightmost digit of the integral part: %d\n", integerPart % 10);

    return 0;
}
