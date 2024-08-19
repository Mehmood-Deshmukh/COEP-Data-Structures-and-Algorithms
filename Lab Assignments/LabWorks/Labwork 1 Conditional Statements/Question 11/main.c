// 11. Write a C program to input angles of a triangle and check whether triangle is valid or not. 

#include <stdio.h>

int isValid(int angle1, int angle2, int angle3);

int main() {
    int angle1, angle2, angle3;
    printf("Enter the three angles of the triangle: ");
    scanf("%d %d %d", &angle1, &angle2, &angle3);

    if (isValid(angle1, angle2, angle3)){
        printf("Valid triangle\n");
    }else{
        printf("Invalid triangle\n");
    }
    return 0;
}

int isValid(int angle1, int angle2, int angle3){

    return angle1 + angle2 + angle3 == 180;
}