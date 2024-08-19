// 13. 
// Write a program to take input from the user and then check whether it is a 
// number or a character. If it is a character, determine whether it is in upper case or 
// lower case. Also print its ASCII value. 

#include <stdio.h>
#include <ctype.h>

void checkInput(char ch) {
    if (isdigit(ch)) {
        printf("The input is a number.\n");
    } else if (isalpha(ch)) {
        if (isupper(ch)) {
            printf("The input is an uppercase letter.\n");
        } else {
            printf("The input is a lowercase letter.\n");
        }
        printf("ASCII value: %d\n", ch);
    } else {
        printf("The input is neither a number nor a letter.\n");
    }
}

int main() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    checkInput(ch);
    return 0;
}
