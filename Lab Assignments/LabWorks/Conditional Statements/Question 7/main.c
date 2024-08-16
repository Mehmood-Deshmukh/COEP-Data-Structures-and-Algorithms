// 7. Write a C program to input any alphabet and check whether it is vowel or consonant.

#include <stdio.h>
int checkVovel(char ch);
int main() {
    char ch = 'I';
    printf("%c is a %s.\n", ch, checkVovel(ch) ? "Vowel" : "Consonant");
    return 0;
}
int checkVovel(char ch){
    return  (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}