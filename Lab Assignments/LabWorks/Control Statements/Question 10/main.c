// 10. 
// Write a program that prints a floating point value in exponential format with the 
// following specifications: 
// a. correct to two decimal places; 
// b. correct to four decimal places; and 
// c. correct to eight decimal places. 
// [Expected Output: value entered: 123456.453125 Value in exponent 
// form: 1.234565e+05 ]


#include <stdio.h>

void printExponential(float num) {
    printf("2 decimal places: %.2e\n", num);
    printf("4 decimal places: %.4e\n", num);
    printf("8 decimal places: %.8e\n", num);
}

int main() {
    float num;
    printf("Enter a floating point number: ");
    scanf("%f", &num);

    printExponential(num);

    return 0;
}
