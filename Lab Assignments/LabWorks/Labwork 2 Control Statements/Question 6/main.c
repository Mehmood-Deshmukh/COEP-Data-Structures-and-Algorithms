// 6. Write a program to calculate simple interest and compound interest. 

#include <stdio.h>
#include <math.h>

float calculateSimpleInterest(float principal, float rate, float period) {
    return (principal * rate * period) / 100;
}

float calculateCompoundInterest(float principal, float rate, float period, int n) {
float amount = principal * pow((1 + rate / (n * 100)), n * period);
return amount - principal;
}

int main() {
    float principal, rate, period;
    int n;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the rate of interest: ");
    scanf("%f", &rate);
    printf("Enter the period in years: ");
    scanf("%f", &period);
    printf("Enter number of times interest applied per year: ");
    scanf("%d", &n);

    float simpleInterest = calculateSimpleInterest(principal, rate, period);
    float compoundInterest = calculateCompoundInterest(principal, rate, period, n);

    printf("The Simple Interest is : %.2f\n", simpleInterest);
    printf("The Compound Interest is : %.2f\n", compoundInterest);

    return 0;
}
