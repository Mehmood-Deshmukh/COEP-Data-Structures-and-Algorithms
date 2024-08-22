// Write your own code for following library functions:
// strcasecmp strsep strcasecmp strcoll

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function prototypes for starcasecmp and strsep
int _strcasecmp(char *s1, char *s2);
char *_strsep(char **s, char *delimiters);
int _strcoll(char *s1, char *s2);

int main() {
    char str1[] = "Mehmood";
    char str2[] = "mehmood";

    int result = _strcasecmp(str1, str2);

    if (result == 0) {
        printf("'%s' and '%s' are the same (ignoring case).\n", str1, str2);
    } else if (result < 0) {
        printf("'%s' is less than '%s' (ignoring case).\n", str1, str2);
    } else {
        printf("'%s' is greater than '%s' (ignoring case).\n", str1, str2);
    }

    char str[] = "apple,orange,,banana,grape";
    char *token;
    char *stringp = str;

    while ((token = _strsep(&stringp, ",")) != NULL) {
        printf("Token: '%s'\n", token);
    }

    int result2 = strcoll(str1, str2);

    if (result2 == 0) {
        printf("'%s' and '%s' are the same.\n", str1, str2);
    } else if (result2 < 0) {
        printf("'%s' is less than '%s'.\n", str1, str2);
    } else {
        printf("'%s' is greater than '%s'.\n", str1, str2);
    }

    return 0;
}

// this function compares two strings case insensitively
int _strcasecmp(char *s1, char *s2){
    //skip same characters
    while(tolower(*s1) == tolower(*s2)){
        if(!*s1) return 0;

        s1++;
        s2++;
    }

    // return difference between the first different character
    return tolower(*s1) - tolower(*s2);
}

//similar to strtok but it also returns empty string when there are consecutive delimiters
char *_strsep(char **s, char *delimiters) {
    char *start = *s;
    char *temp;              

    if (start == NULL) {
        return NULL;
    }

    // for each delimiter check if current character matches it.
    // if it matches replace it with '\0'
    //set the string to start from the next character
    for (temp = start; *temp != '\0'; temp++) {
        for (char *d = delimiters; *d != '\0'; d++) {
            if (*temp == *d) {
                *temp = '\0';      
                *s = temp + 1;
                return start;
            }
        }
    }

    *s = NULL;
    return start;
}

int _strcoll(char *s1, char *s2){
    //skip same characters
    while(*s1 == *s2){
        if(!*s1) return 0;

        s1++;
        s2++;
    }

    // return difference between the first different character
    return *s1 - *s2;
}