// 4. Write a program to read two floating point numbers. Add these numbers and assign 
// the result to an integer. Finally, display the value of all the three variables. 

#include <stdio.h>

int main() {
    float num1, num2;
    int result;

    printf("Enter first Number : \n");
    scanf("%f", &num1);

    printf("Enter second Number : \n");
    scanf("%f", &num2);

    result = num1 + num2;

    printf("First number: %.2f\n", num1);
    printf("Second number: %.2f\n", num2);
    printf("Sum as integer: %d\n", result);
    return 0;
}
