// 3. Write a program to count the number of vowels in a text. (eg: Enter text: hello world, 
// Output: No.of vowels- 3 ). 


#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

int countVowels(char *text) {
    int count = 0;
    while (*text) {
        char c = tolower(*text);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        text++;
    }
    return count;
}

int main() {
    char text[100];
    int i = 0;
    char ch;
    printf("Enter the text: ");
        while (scanf("%c", &ch) == 1 && ch != '\n') {
        if (i < MAX_LEN - 1) {
            text[i++] = ch;
        }
    }
    text[i] = '\0';

    int vowels = countVowels(text);
    printf("The No. of vowels in the text is: %d\n", vowels);

    return 0;
}
