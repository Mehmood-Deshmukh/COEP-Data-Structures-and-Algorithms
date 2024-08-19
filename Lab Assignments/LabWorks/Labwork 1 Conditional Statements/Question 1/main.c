// 1. Write a C program to find maximum between two numbers.

#include <stdio.h>
int findMax(int num1, int num2);
int main() {
    int num1 = 12;
    int num2 = 24;

    printf("The maximum between the two numbers is %d\n",  findMax(num1, num2));
    return 0;
}

int findMax(int num1, int num2){

    return num1 > num2 ? num1 : num2;
}