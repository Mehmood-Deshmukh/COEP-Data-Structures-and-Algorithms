// 6. Write a C program to check whether a character is alphabet or not. 

#include <stdio.h>
int checkAlpha(char ch);
int main() {
    char ch = 'M';
    printf("%c %s an Alphabet\n", ch, checkAlpha(ch) ? "is" : "is not");
    return 0;
}
int checkAlpha(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}