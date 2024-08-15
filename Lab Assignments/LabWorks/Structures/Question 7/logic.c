#include "./header.h"

Time add(Time t1, Time t2){
    Time result;
    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    int totalSeconds = totalSeconds1 + totalSeconds2;
    result.hours = totalSeconds / 3600;
    result.minutes = (totalSeconds % 3600) / 60;
    result.seconds = totalSeconds % 60;
    return result;
}
Time substract(Time t1, Time t2){
    Time result;
    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int totalSeconds = totalSeconds1 - totalSeconds2;
    result.hours = totalSeconds / 3600;
    result.minutes = (totalSeconds % 3600) / 60;
    result.seconds = totalSeconds % 60;
    return result;
}