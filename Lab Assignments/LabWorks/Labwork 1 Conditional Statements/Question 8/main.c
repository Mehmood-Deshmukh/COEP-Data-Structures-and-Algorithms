// 8. Write a C program to input any character and check whether it is alphabet, digit or special 
// character. 

#include <stdio.h>
int getType(char ch);
int main() {
    char ch = '?';
    char *options[] = {"Digit", "Alphabet", "Special Character"};
    printf("The numbers is %s\n",  options[getType(ch)]);
    return 0;
}
int getType(char ch){
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return 1;
    else if (ch >= '0' && ch <= '9')
        return 0;

    return 2;
}