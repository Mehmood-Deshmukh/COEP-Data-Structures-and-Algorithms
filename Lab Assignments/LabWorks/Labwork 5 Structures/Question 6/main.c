#include <stdio.h>
#include "./logic.c"
int main() {
    Date date;

    printf("Enter the date in (dd/mm/yyyy) format : \n");
    scanf("%d %d %d", &date.day, &date.month, &date.year);

    if(isvalid(date)){
        printf("Valid date entered!\n");
        printDate(date);
    }else{
        printf("Invalid date entered!\n");
    }

    return 0; 
}