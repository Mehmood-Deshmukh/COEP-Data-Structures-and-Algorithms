// 7. Write a program to calculate salary of an employee given his basic pay (to be 
// entered by the user), HRA = 10% of the basic pay, TA = 5% of basic pay. Define 
// HRA and TA as constants and use them to calculate the salary of the employee.


#include <stdio.h>

#define HRA 0.10
#define TA 0.05

float calculateSalary(float salary) {
    float hra = salary * HRA;
    float ta = salary * TA;
    return salary + hra + ta;
}

int main() {
    float salary;
    printf("Enter Salary: ");
    scanf("%f", &salary);

    float totalSalary = calculateSalary(salary);

    printf("The base salary is: %.2f\n", salary);
    printf("HRA: %.2f\n", salary * HRA);
    printf("TA: %.2f\n", salary * TA);
    printf("The Total Salary is: %.2f\n", totalSalary);

    return 0;
}
