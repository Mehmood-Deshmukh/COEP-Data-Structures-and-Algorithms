// 8. Write a program to prepare a grocery bill. Enter the name of the items purchased, 
// quantity in which it is purchased, and its price per unit. Then display the bill in the 
// following format: 
// Quantity   
// ************ ********************************B I L L ***************************************** 
// Item   
// Price   
// Amount 
// __________________________________________________________________ 
// Total Amount to be paid =  
// __________________________________________________________________ 


#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 12

typedef struct {
    char name[50];
    int quantity;
    float pricePerUnit;
} Item;

void printBill(Item items[], int numItems) {
    float grandTotal = 0;
    printf("\n************ **************************************** B I L L *****************************************\n");
    printf("%-20s %10s %10s %10s\n", "Item", "Quantity", "Price", "Amount");
    printf("____________________________________________________________________________________\n");

    for (int i = 0; i < numItems; i++) {
        float totalAmount = items[i].quantity * items[i].pricePerUnit;
        printf("%-20s %10d %10.2f %10.2f\n", items[i].name, items[i].quantity, items[i].pricePerUnit, totalAmount);
        grandTotal += totalAmount;
    }

    printf("____________________________________________________________________________________\n");
    printf("Total Amount to be paid = %.2f\n", grandTotal);
}

int main() {
    Item items[MAX_ITEMS];
    int numItems;

    printf("Enter the number of items: \n");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        printf("Enter the item name: ");
        scanf("%s", items[i].name);

        int len = strlen(items[i].name);
        if (len > 0 && items[i].name[len - 1] == '\n') {
            items[i].name[len - 1] = '\0';
        }

        printf("Enter the quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Enter the price per unit: ");
        scanf("%f", &items[i].pricePerUnit);
    }

    printBill(items, numItems);

    return 0;
}
