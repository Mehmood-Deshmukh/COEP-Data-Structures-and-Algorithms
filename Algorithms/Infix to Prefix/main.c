#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

char* results[] = {
    "+ 1 - * 2 3 4",
    "- * + 1 2 3 ^ - 4 5 + 6 7",
    "* 2 + 3 4"
};

char* infix_to_prefix(char* infix);

void printResult(char* prefix, char* result, int index) {
    if (strcmp(prefix, result) == 0) {
        printf(GREEN "Test %d: Correct\n" RESET, index + 1);
    } else {
        printf(RED "Test %d: Incorrect\n" RESET, index + 1);
        printf(RED "Expected: %s\nGot: %s\n" RESET, result, prefix);
    }
}

void test_infix_to_prefix(char* infix, int index) {
    char* prefix = infix_to_prefix(infix);
    if (prefix) {
        printf("Infix Expression: %s\n", infix);
        printResult(prefix, results[index], index);
        free(prefix);
    } else {
        printf(RED "Test %d Failed!.\n" RESET, index + 1);
    }
}

int main() {
    char expression1[] = "1 + 2 * 3 - 4";
    char expression2[] = "(1 + 2) * 3 - (4 - 5) ^ (6 + 7)";
    char expression3[] = "2 * (3 + 4)";
    
    printf("Testing infix to prefix conversion:\n\n");
    test_infix_to_prefix(expression1, 0);
    test_infix_to_prefix(expression2, 1);
    test_infix_to_prefix(expression3, 2);
    
    return 0;
}