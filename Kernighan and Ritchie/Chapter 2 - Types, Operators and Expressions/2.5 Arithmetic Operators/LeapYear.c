#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year);

int main() {
    printf("%d", isLeapYear(2016));
    return 0;
}
bool isLeapYear(int year){
    if ((year % 400 == 0) || ((year % 100 != 0 ) &&  (year % 4 == 0))){
        return true;
    }
    return false;
}
