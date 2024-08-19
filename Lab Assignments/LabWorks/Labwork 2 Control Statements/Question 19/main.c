// 19. 
// Write a program that asks the user to enter an integer and determines whether 
// it is divisible by 5 and 6, whether it is divisible by 5 or 6, and whether it is divisible 
// by 5 or 6 but not both. For example, if your input is 10, the output should be:  
// Is 10 divisible by 5 and 6? false  
// Is 10 divisible by 5 or 6? true  
// Is 10 divisible by 5 or 6, but not both? True

#include <stdio.h>

void checkDivisibility(int num);

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    checkDivisibility(num);
    return 0;
}

void checkDivisibility(int num) {
    int isdivisibleBy5 = (num % 5 == 0);
    int isdivisibleBy6 = (num % 6 == 0);

    printf("Is %d divisible by 5 and 6? %s\n", num, (isdivisibleBy5 && isdivisibleBy6) ? "true" : "false");
    printf("Is %d divisible by 5 or 6? %s\n", num, (isdivisibleBy5 || isdivisibleBy6) ? "true" : "false");
    printf("Is %d divisible by 5 or 6, but not both? %s\n", num, (isdivisibleBy5 != isdivisibleBy6) ? "true" : "false");
}