typedef struct Hotel{
    char name[50];
    char address[100];
    char grade;
    int numRooms;
    int roomCharges;
} Hotel;

void printHotelsByGrade(Hotel hotels[], int numHotels, char grade);
void printHotelsByRoomCharges(Hotel hotels[], int numHotels, int roomCharges);
