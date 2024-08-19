// Q.3 Write a program to define a structure for a hotel that has members— name, address, 
// grade, number of rooms, and room charges. Write a function to print the names of hotels in 
// a particular grade. Also write a function to print names of hotels that have room charges less 
// than the specified value.

#include <stdio.h>
#include "./logic.c"
int main() {
    Hotel hotels[] = {
        {"Hotel 1", "Address 1", 'A', 20, 2000},
        {"Hotel 2", "Address 2", 'B', 45, 1200},
        {"Hotel 3", "Address 3", 'A', 25, 3000},
        {"Hotel 4", "Address 4", 'A', 60, 4500}
    };

    int numHotels = sizeof(hotels) / sizeof(hotels[0]);

    printHotelsByGrade(hotels, numHotels, 'A');
    printHotelsByRoomCharges(hotels, numHotels, 4000);
    return 0;
}