//Write a function which cuts a string given by "str" on the character given in "ch" 
// and returns the first such word.
// char *cutonchar(char *str, char ch);
// For example: if 'str' is "something bad" and 'ch' is ' ' then it returns "something".
// if 'str' is "something bad" and 'ch' is 'e' then it returns 'som'

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function to cut string on character
char* cutonchar(char* str, char ch) {
    char* result = (char*)malloc(strlen(str) + 1);
    
    if (result == NULL) {
        return NULL;
    }

    strcpy(result, str);
    char* pos = strchr(result, ch); //get position of ch

    if (pos != NULL) { //if ch exixts replace it with '\0'
        *pos = '\0';
    }

    return result;
}

int main() {
    char input[] = "I am Mehmood Rehan Deshmukh";
    char ch = 'o';
    printf("%s cut on %c is %s", input, ch, cutonchar(input, ch));
    return 0;
}