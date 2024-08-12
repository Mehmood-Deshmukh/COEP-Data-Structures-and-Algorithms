#include "./header.h"
#include <stdio.h>

int isValid(Time startTime, Time endTime){
    if(startTime.hours > endTime.hours){
        return 0;
    }else if(startTime.hours == endTime.hours &&  startTime.minutes > endTime.minutes){
        return 0;
    }else if(startTime.minutes == endTime.minutes &&  startTime.seconds > endTime.seconds){
        return 0;
    }

    return 1;
}

void printGoodDay(Time startTime, Time endTime){
    if(!isValid(startTime, endTime)) return;

    while(startTime.hours < endTime.hours ||(startTime.hours == endTime.hours && startTime.minutes < endTime.minutes) || (startTime.hours == endTime.hours && startTime.minutes == endTime.minutes && startTime.seconds < endTime.seconds)){
        printf("GOOD DAY!\n");
        startTime.seconds++;

        if(startTime.seconds == 60){
            startTime.seconds = 0;
            startTime.minutes++;
        }

        if(startTime.minutes == 60){
            startTime.minutes = 0;
            startTime.hours++;
        }
    }
}