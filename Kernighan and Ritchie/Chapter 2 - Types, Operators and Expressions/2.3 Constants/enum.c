#include <stdio.h>

enum boolean {NO, YES};

enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main() {
    printf("%d\n", NO);
    printf("%d\n", YES);
    printf("****************MONTHS**************************");
    printf("%d\n", JAN);
    printf("%d\n", FEB);
    printf("%d\n", MAR);
    printf("%d\n", APR);
    printf("%d\n", MAY);
    printf("%d\n", JUN); 
    printf("%d\n", JUL);
    printf("%d\n", AUG);
    printf("%d\n", SEP);
    printf("%d\n", OCT);
    printf("%d\n", NOV);
    printf("%d\n", DEC);


    return 0;
}