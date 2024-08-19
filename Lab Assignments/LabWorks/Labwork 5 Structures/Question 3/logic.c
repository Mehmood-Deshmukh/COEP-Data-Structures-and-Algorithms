#include "./header.h"

void printHotelsByGrade(Hotel hotels[], int numHotels, char grade){
    printf("\n**Hotels with Grade %c**\n", grade);
    for(int i = 0 ; i < numHotels; i++){
        if(hotels[i].grade == grade){
            printf("Hotel: %s\n", hotels[i].name);
        }
    }
}

void printHotelsByRoomCharges(Hotel hotels[], int numHotels, int roomCharges){
    printf("\n**Hotels with charges less than %d**\n", roomCharges);
    for(int i = 0 ; i < numHotels; i++){
        if(hotels[i].roomCharges <= roomCharges){
            printf("Hotel: %s\n", hotels[i].name);
        }
    }
}
