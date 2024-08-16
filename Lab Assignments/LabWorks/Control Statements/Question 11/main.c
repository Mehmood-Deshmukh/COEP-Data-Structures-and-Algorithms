// 11. 
// Write a program to read a character and print it. Also print its ASCII value. If the 
// character is in lower case, print it in upper case and vice versa. Repeat the process 
// until a ‘*’ is entered. 

#include <stdio.h>
#include <ctype.h>

void processCharacter(char ch) {
    printf("The Character is: %c\n", ch);
    printf("It's ASCII value is: %d\n", (int)ch);

    if (islower(ch)) {
        printf("Uppercase: %c\n", toupper(ch));
    } else if (isupper(ch)) {
        printf("Lowercase: %c\n", tolower(ch));
    } else {
        printf("Character is neither uppercase nor lowercase.\n");
    }
}

int main() {
    char ch;

    while (1) {
        printf("Enter a character (to exit enter *): ");
        scanf(" %c", &ch);

        if (ch == '*') {
            break;
        }

        processCharacter(ch);
    }

    return 0;
}
