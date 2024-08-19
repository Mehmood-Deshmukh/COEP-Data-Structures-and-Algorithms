//4. Write a C program to check whether a number is even or odd. 

#include <stdio.h>
int checkEven(int num);
int main() {
    int num = 54;
    int isEven = checkEven(num);
    printf("%d is an %s Number\n", num, isEven == 1? "Even" : "Odd");
    return 0;
}
int checkEven(int num){
    return (num % 2 == 0);
}