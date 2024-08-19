#include "./header.h"

int isLeapYear(Date date){
    int year = date.year;

    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int isvalid(Date date){
    int day = date.day;
    int month = date.month;
    int isLeap = isLeapYear(date);

    if (month < 1 || month > 12) {
        return 0;
    }

    if (day < 1){
        return 0;
    }

    switch (month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return (day <= 31);
    case 4:
    case 6:
    case 9:
    case 11:
        return (day <= 30);
    case 2:
        return (isLeap ? day <= 29 : day <= 28);
    default:
        return 0;
    }
    
}

void printDate(Date date){
    printf("Date: %02d/%02d/%04d\n", date.day, date.month, date.year);
}