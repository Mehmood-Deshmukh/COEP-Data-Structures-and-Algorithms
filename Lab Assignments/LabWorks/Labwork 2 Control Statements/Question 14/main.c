// 14. 
// Write a program to display sum and average of numbers from 1 to n. Use for 
// loop. 

#include <stdio.h>
void displaySumAndAverage(int n);

int main() {
    int n = 50;
    displaySumAndAverage(n);
    return 0;
}


void displaySumAndAverage(int n){
    int sum = 0, average, i;
    for(i = 1; i <= n; i++){
        sum+= i;
    }

    average = sum / n;

    printf("The sum of numbers from 1 to %d is %d\n", n, sum);
    printf("The Average of numbers from 1 to %d is %d\n", n, average);
}