// 13. Write a C program to find all roots of a quadratic equation. 

#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, D, root1, root2;
    printf("Enter the coefficients (a, b, c in ax^2 + bx + c): \n");
    scanf("%d%d%d", &a, &b, &c);

    D = b*b - 4*a*c;

    if(D >= 0){
        root1 = (-b + sqrt(D)) / (2*a); 
        root2 = (-b - sqrt(D)) / (2*a);
        printf("1st Root1: %d, 2nd Root: %d\n", root1, root2);
    }else {
        printf("Roots are not real.\n");
    }

    return 0;
}