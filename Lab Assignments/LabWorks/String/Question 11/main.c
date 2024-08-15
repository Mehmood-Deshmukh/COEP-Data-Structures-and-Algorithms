#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define MAX_SIZE 1024

int deriveInteger(const char *s) {
    int result = 0;

    while (*s != '\0') {
        if (isdigit(*s)) {
            result = result * 10 + (*s - '0');
        } else {
            return INT_MIN;
        }

        s++;
    }

    return result;
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string represeting digits: ");
    scanf("%s", input);

    int result = deriveInteger(input);
    
    if (result != INT_MIN) {
        printf("Derived integer: %d\n", result);
    } else {
        printf("The string does not represent a valid integer!\n");
    }

    return 0;
}