// 9. Write a program to read an integer. Display the value of that integer in decimal, 
// octal, and hexadecimal notation. 

#include <stdio.h>

void displayNotations(int number) {
    printf("Decimal: %d\n", number);
    printf("Octal: %o\n", number);
    printf("Hexadecimal: %X\n", number);
}

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    displayNotations(number);

    return 0;
}
