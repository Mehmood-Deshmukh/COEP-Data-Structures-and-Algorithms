#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* cutonchar(char* str, char ch) {
    char* result = (char*)malloc(strlen(str) + 1);
    
    if (result == NULL) {
        return NULL;
    }

    strcpy(result, str);
    char* pos = strchr(result, ch);

    if (pos != NULL) {
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