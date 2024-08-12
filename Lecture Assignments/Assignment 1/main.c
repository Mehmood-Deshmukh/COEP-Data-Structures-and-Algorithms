#include <stdio.h>
#include "logic.c"


int main() {
    int choice;
    Array array;
    while(1){
        printMenu();
        scanf("%d", &choice);
        handleChoice(choice, &array);
    }

    return 0;
}