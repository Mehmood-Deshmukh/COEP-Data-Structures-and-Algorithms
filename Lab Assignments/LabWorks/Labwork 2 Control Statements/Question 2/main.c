// 2. Write a program to print the count of even numbers between 1–200. Also print their 
// sum

#include <stdio.h>

void countAndSumEvenNumbers(int *count, int *sum) {
    *count = 0;
    *sum = 0;
    for (int i = 1; i <= 200; i++) {
        if (i % 2 == 0) {
            (*count)++;
            *sum += i;
        }
    }
}

int main() {
    int count, sum;
    countAndSumEvenNumbers(&count, &sum);
    printf("The Count of even numbers from 1 to 200 is: %d\n", count);
    printf("and thier sum is: %d\n", sum);
    return 0;
}
