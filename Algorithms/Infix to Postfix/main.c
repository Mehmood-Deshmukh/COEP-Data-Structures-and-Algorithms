#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

char *infix_to_postfix(char *infix, int len);

char* results[] = {
    "1 23 23 * + 43 -",      
    "10 20 + 30 * 40 50 - 60 70 + ^ -",  
    "2 3 4 + *"              
};

void printResult(char *postfix, char *result, int index) {
    if (strcmp(postfix, result) == 0) {
        printf(GREEN "Test %d: Correct\n" RESET, index + 1);
    } else {
        printf(RED "Test %d: Incorrect\n" RESET, index + 1);
        printf(RED "Expected: %s\nGot: %s\n" RESET, result, postfix);
    }
}

void testInfixToPostfix(char *infix, int index) {
    int len = strlen(infix);
    char *postfix = infix_to_postfix(infix, len);

    if (postfix) {
        printf("Infix Expression: %s\n", infix);
        printResult(postfix, results[index], index);
        free(postfix);
    } else {
        printf(RED "Test %d Failed!.\n" RESET, index + 1);
    }
}

int main() {
    char expression1[] = "1 + 23 * 23 - 43";
    char expression2[] = "(10 + 20) * 30 - (40 - 50) ^ (60 + 70)";
    char expression3[] = "2 * (3 + 4)";

    printf("Testing infix to postfix conversion:\n\n");

    testInfixToPostfix(expression1, 0);
    testInfixToPostfix(expression2, 1);
    testInfixToPostfix(expression3, 2);

    return 0;
}
