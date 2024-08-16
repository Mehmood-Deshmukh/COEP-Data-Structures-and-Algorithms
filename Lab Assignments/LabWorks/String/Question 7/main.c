#include <stdio.h>
#include <string.h>
#include <ctype.h>

int _strcasecmp(char *s1, char *s2);
char *_strsep(char **s, char *delimiters);

int main() {
    char str1[] = "Mehmood";
    char str2[] = "mehmood";

    int result = strcasecmp(str1, str2);

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

    return 0;
}

int _strcasecmp(char *s1, char *s2){
    while(tolower(*s1) == tolower(*s2)){
        if(!*s1) return 0;

        s1++;
        s2++;
    }

    return tolower(*s1) - tolower(*s2);
}


char *_strsep(char **stringp, char *delim) {
    char *start = *stringp;
    char *temp;              

    if (start == NULL) {
        return NULL;
    }

    for (temp = start; *temp != '\0'; temp++) {
        for (char *d = delim; *d != '\0'; d++) {
            if (*temp == *d) {
                *temp = '\0';      
                *stringp = temp + 1;
                return start;
            }
        }
    }

    *stringp = NULL;
    return start;
}