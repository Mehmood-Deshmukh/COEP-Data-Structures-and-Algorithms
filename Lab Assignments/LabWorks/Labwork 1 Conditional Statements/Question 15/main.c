// 15. Write a C program to input basic salary of an employee and calculate its Gross salary 
// according to following: 
// Basic Salary <= 10000 : HRA = 20%, DA = 80% 
// Basic Salary <= 20000 : HRA = 25%, DA = 90% 
// Basic Salary > 20000 : HRA = 30%, DA = 95%

#include <stdio.h>


float getGrossSalary(float salary);

int main() {
    float salary, grossSalary;
    printf("Enter the basic salary of an employee: ");
    scanf("%f", &salary);

    grossSalary = getGrossSalary(salary);
    printf("The Gross Salary of the employee is: %.2f\n", grossSalary);

    return 0;
}

float getGrossSalary(float salary){
    float HRA, DA;

    if (salary <= 10000) {
        HRA = salary * 0.20;
        DA = salary * 0.80;
    } else if (salary <= 20000) {
        HRA = salary * 0.25;
        DA = salary * 0.90;
    } else {
        HRA = salary * 0.30;
        DA = salary * 0.95;
    }

    return salary + HRA + DA;
}