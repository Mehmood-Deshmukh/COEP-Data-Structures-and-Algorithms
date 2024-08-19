// 12. 
// Write a program to add three floating point numbers. The result should contain 
// only two digits after the decimal. 

#include <stdio.h>

int main() {
    float num1, num2, num3;
    printf("Enter three floating point numbers: \n");
    scanf("%f %f %f", &num1, &num2, &num3);

    float sum = num1 + num2 + num3;
    printf("The sum of the three numbers is %.2f", sum);
    return 0;
}