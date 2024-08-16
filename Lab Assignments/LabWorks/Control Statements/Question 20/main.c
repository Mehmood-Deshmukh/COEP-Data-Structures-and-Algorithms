// 20. 
// McDonald’s  wants you to write a program to take orders from the Internet. Your 
// program asks for the item, its price, and if overnight shipping is wanted. Regular 
// shipping for items under Rs.100 is Rs20.00; for items Rs100 or more shipping is 
// Rs30.00. For overnight delivery add Rs50.00. For example, the output might be: 
// Enter the item: Burger Enter the price: 450 Overnight delivery (0==no, 1==yes): 1 
// Invoice: Burger Rs.450 shipping Rs.80 total Rs. 530. 

#include <stdio.h>

void calculateInvoice(char item[], float price, int overnight);

int main() {
    char item[50];
    float price;
    int overnight;

    printf("Enter the item: ");
    scanf("%s", item);
    printf("Enter the price of the Item: ");
    scanf("%f", &price);
    printf("Do you want an Overnight delivery ? (0==no, 1==yes): ");
    scanf("%d", &overnight);

    calculateInvoice(item, price, overnight);
    return 0;
}

void calculateInvoice(char item[], float price, int overnight) {
    float shipping;
    if (price < 100) {
        shipping = 20.0;
    } else {
        shipping = 30.0;
    }

    if (overnight) {
        shipping += 50.0;
    }

    float total = price + shipping;
    printf("Invoice:\n%s Rs.%.2f\nShipping Rs.%.2f\nTotal Rs.%.2f\n", item, price, shipping, total);
}