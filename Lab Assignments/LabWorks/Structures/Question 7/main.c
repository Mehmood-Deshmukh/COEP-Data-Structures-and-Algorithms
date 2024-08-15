#include "./logic.c"
#include <stdio.h>

int main(){
    Time t1 = (Time){10, 20, 50};
    Time t2 = (Time){5, 30, 40};

    Time added = add(t1, t2);
    Time substracted = substract(t1, t2);
    printf("Sum: %d hrs %d mins %d s\n", added.hours, added.minutes, added.seconds);
    printf("Difference: %d hrs %d mins %d s\n", substracted.hours, substracted.minutes, substracted.seconds);
    return 0;
}