#include "./header.h"

int compare(Fraction x, Fraction y){
    double num1 = (double) x.numerator / x.denominator;
    double num2 = (double) y.numerator / y.denominator;

    if(num1 == num2){
        return 0;
    } else if(num1 < num2){
        return -1;
    } else{
        return 1;
    }
}