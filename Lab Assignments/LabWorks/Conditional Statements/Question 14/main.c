// 14. Write a C program to input marks of five subjects Physics, Chemistry, Biology, 
// Mathematics and Computer. Calculate percentage and grade according to following: 
// Percentage >= 90% : Grade A 
// Percentage >= 80% : Grade B 
// Percentage >= 70% : Grade C 
// Percentage >= 60% : Grade D 
// Percentage >= 40% : Grade E 
// Percentage < 40% : Grade F 

#include <stdio.h>

int main() {
    float physics, chemistry, biology, mathematics, computer;
    printf("Enter marks int the following five subjects (out of 100): physics, chemistry, biology, mathematics, computer : ");
    scanf("%f %f %f %f %f", &physics, &chemistry, &biology, &mathematics, &computer);

    float total = physics + chemistry + biology + mathematics + computer;
    float percentage = total / 5;

    printf("The Percentage is : %.2f\n", percentage);

    if (percentage >= 90){
        printf("Grade: A\n");
    } else if (percentage >= 80){
        printf("Grade: B\n");
    } else if (percentage >= 70){
        printf("Grade: C\n");
    }else if (percentage >= 60){
        printf("Grade: D\n");
    }else if (percentage >= 40){
        printf("Grade: E\n");
    }else{
        printf("Grade: F\n");
    }
    return 0;
}
