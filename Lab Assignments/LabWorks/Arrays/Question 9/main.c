/*
Q9: Take 20 integer inputs from the user and print the following:
- Number of positive numbers
- Number of negative numbers
- Number of odd numbers
- Number of even numbers
- Number of zeros
*/
#include <stdio.h>

int main() {
    int array[20];
    int positive = 0, negative = 0, odd = 0, even = 0, zero = 0;


    printf("Enter 20 integers:\n");
    for (int i = 0; i < 20; ++i) {
        scanf("%d", &array[i]);
        

        if (array[i] > 0) {
            positive++;
        } else if (array[i] < 0){
            negative++;
        }else{
            zero++;
        } 
                
        if (array[i] % 2 == 0) 
            even++;
        else 
            odd++;
        }

    printf("Number of positive numbers: %d\n", positive);
    printf("Number of negative numbers: %d\n", negative);
    printf("Number of odd numbers: %d\n", odd);
    printf("Number of even numbers: %d\n", even);
    printf("Number of zeros: %d\n", zero);

    return 0;
}
