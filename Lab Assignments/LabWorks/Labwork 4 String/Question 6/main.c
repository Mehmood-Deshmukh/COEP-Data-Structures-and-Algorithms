// Write a function to convert a decimal number to a binary number and return the binary 
// representation in a string.

#include <stdio.h>
#include<stdlib.h>

// function prototype
char *toBinary(int num);

int main() {
    int num = 5;

    printf("The Binary Representation of %d is %s\n", num, toBinary(num));
    
    return 0;
}

// this function return the binary representation of an integer as a string
char *toBinary(int num){
    if(num == 0) return "0";
    int length = 0;
    int temp = num;
    //get the length of the binary representation
    while(temp){
        length++;
        temp /= 2;
    }

    //allocate memory for the string
    char *binary = (char *)malloc(sizeof(char) * length);

    //start from the last index
    int index = length - 1;
    while(index >= 0){
        binary[index] = (num % 2) + '0'; 
        num /= 2;
        index--;
    }

    binary[length] = '\0'; //end with a NULL character

    return binary;
}
