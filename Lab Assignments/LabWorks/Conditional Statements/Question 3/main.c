// 3. Write a C program to check whether a number is divisible by 5 and 11 or not. 

#include <stdio.h>
int checkDivisibility(int num);
int main() {
    int num = 55;
    int divisibility = checkDivisibility(num);
    printf("%d %s divisible by 5 and 11\n", num, divisibility == 1? "is" : "is not");
    return 0;
}
int checkDivisibility(int num){
    return (num % 5 == 0) && (num % 11 == 0);
}