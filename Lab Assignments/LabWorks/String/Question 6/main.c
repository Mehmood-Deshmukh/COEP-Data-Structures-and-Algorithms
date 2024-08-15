#include <stdio.h>
#include<stdlib.h>

char *toBinary(int num);

int main() {
    int num = 5;

    printf("The Binary Representation of %d is %s\n", num, toBinary(num));
    
    return 0;
}

char *toBinary(int num){
    if(num == 0) return "0";
    int length = 0;
    int temp = num;
    while(temp){
        length++;
        temp /= 2;
    }

    char *binary = (char *)malloc(sizeof(char) * length);
    int index = length - 1;
    while(index >= 0){
        binary[index] = (num % 2) + '0';
        num /= 2;
        index--;
    }

    binary[length] = '\0';

    return binary;
}
