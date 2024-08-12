// Q.4 Declare a structure time that has three fields—hr, min, sec. Create two variables start_time 
// and end_time. Input their values from the user. Then while start_time does not reach the 
// end_time, display GOOD DAY on the screen.

#include "./logic.c"
#include <stdio.h>

int main() {
    Time startTime, endTime;
    printf("Enter start time in hours minutes and seconds :\n");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Enter end time in hours minutes and seconds :\n");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    printGoodDay(startTime, endTime);

    return 0;
}