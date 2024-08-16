// 10. Write a C program to input month number and print number of days in that month. 

#include <stdio.h>

int getDays(int month);
int main() {
    int month = 9;
    int days = getDays(month);
    if(days == -1){
        printf("Invalid Month\n");
    }else{
        printf("The Month %d has %d Days", month, days);
    }
    return 0;
}

int getDays(int month){
    switch (month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return 28;
    default:
        return -1;
    }
}