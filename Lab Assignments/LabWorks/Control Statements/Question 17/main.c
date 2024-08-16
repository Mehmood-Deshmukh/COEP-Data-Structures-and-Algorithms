// 17. Write a program to read numbers until –1 is entered and display whether it is 
// an Armstrong number or not. 

#include <stdio.h>
#include <math.h>
int isArmstrong(int num);

int main() {
        int num;
    while (1) {
        printf("Enter a number (to exit enter -1): ");
        scanf("%d", &num);

        if (num == -1) break;

        if (isArmstrong(num)) {
            printf("%d is an Armstrong number.\n", num);
        } else {
            printf("%d is not an Armstrong number.\n", num);
        }
    }
    return 0;
}

int isArmstrong(int num) {
    int temp = num, length = 0;
    float sum = 0; 
    while (temp != 0) {
        temp /= 10;
        length++;
    }
    temp = num;

    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, length);
        temp /= 10;
    }

    return ((int)sum == num);
}
