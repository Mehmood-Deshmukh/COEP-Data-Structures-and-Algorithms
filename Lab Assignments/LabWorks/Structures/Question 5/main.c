#include <stdio.h>
#include "./logic.c"

int main(){
    Fraction num1 = (Fraction){10, 5};
    Fraction num2 = (Fraction){18, 6};

    printf("%d\n", compare(num1, num2));
    return 0;
}