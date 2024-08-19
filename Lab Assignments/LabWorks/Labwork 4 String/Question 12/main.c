// Write a function which does the following
// void rev(char *str);
// Reverses the string "str" in place (without using another string).

#include <stdio.h>
#include <string.h>

//function prototype
void reverseString(char *str);

int main() {
    char str[] = "Mehmood";

    printf("The Reverse Representation of %s is ", str);
    reverseString(str);
    printf("%s\n", str);
    
    return 0;
}

//function to reverse string in place
void reverseString(char *str){
    int len = strlen(str);

    for(int i = 0; i < len / 2; i++){
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}