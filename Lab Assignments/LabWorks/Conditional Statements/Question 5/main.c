// 5. Write a C program to check whether a year is leap year or not. 

#include <stdio.h>
int isLeap(int year);
int main() {
    int year = 2023;
    printf("%d %s a Leap Year \n", year, isLeap(year) == 1? "is a" : "is not");
    return 0;
}
int isLeap(int year){
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}