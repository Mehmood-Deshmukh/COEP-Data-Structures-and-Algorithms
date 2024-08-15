#include <stdio.h>
#include <string.h>


// my function will accept multiple delimiters as a string and will work in all the cases: eg ",!;"
char* _strtok(char *s, const char *delimiter) {
    static char *start = NULL;
    char *token_start;

    // if s is NULL means we have to tokenize the same string we did previously.same as the strtok function
    if (s != NULL) {
        start = s;
    }
    if (start == NULL) {
        return NULL;
    }

    //take care of leading delimiters
    while (*start) {
        const char *d = delimiter;
        while (*d) {
            if (*start == *d) {
                ++start;
                break;
            }
            ++d;
        }
        if (*d == '\0') {
            break;
        }
    }

    // if we reached the end of the string we will return NULL;
    if (*start == '\0') {
        return NULL;
    }


    //else we will tokenize
    token_start = start;

    while (*start) {
        const char *d = delimiter;
        while (*d) {
            if (*start == *d) {
                *start = '\0';
                ++start;
                return token_start;
            }
            ++d;
        }
        ++start;
    }

    return token_start;
}

int main() {
    char s[] = "Mehmood!Deshmukh,!Was,Here";
    const char *delimiter = ",!";
    char *token;

    token = _strtok(s, delimiter);
    int index = 1;
    while (token != NULL) {
        printf("Token %d: %s\n", index++, token);
        token = _strtok(NULL, delimiter);
    }

    return 0;
}
