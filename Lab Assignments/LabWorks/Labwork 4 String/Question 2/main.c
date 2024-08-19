// Write the strtok() function.

#include <stdio.h>
#include <string.h>

//function prototype
char* _strtok(char *s, char *delimiter);

int main() {
    char s[] = "Mehmood!Deshmukh,!Was,Here"; //this is the input string
    char *delimiter = ",!"; // this is the sequence of delimeters
    char *token;

    token = _strtok(s, delimiter);
    int index = 1;
    while (token != NULL) {
        printf("Token %d: %s\n", index++, token);
        token = _strtok(NULL, delimiter);
    }

    return 0;
}

// my function will accept multiple delimiters as a string and will work in all the cases: eg ",!;"
char* _strtok(char *s, char *delimiter) {
    static char *start = NULL; //static because we need to return the next token everytime
    char *token_start;

    // if s is NULL means we have to tokenize the same string we did previously. same as the strtok function
    if (s != NULL) {
        start = s;
    }

    // if start is NULL which means there are no more tokens left so we will return NULL
    if (start == NULL) {
        return NULL;
    }

    //take care of leading delimiters
    while (*start) {
        char *d = delimiter; //compare each character with all the delimiters if any of them match increment the start
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
        char *d = delimiter; // for each delimiter check if the current character matches any of them
        while (*d) {
            if (*start == *d) { //if the current character matches any of the delimiter , replace it with null character and return the token
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
