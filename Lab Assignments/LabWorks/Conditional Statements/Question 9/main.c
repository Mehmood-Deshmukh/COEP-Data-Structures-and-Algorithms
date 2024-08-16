// 9. Write a C program to check whether a character is uppercase or lowercase alphabet.

#include <stdio.h>
int isLowerCase(char ch);
int main() {
    char ch = 'm';
    printf("%c is %s\n", ch, isLowerCase(ch) ? "Lowercase" : "UpperCase");
    return 0;
}
int isLowerCase(char ch){
    return (ch >= 'a' && ch <= 'z');
}