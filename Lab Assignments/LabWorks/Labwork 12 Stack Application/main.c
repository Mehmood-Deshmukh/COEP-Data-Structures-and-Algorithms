#include<stdio.h>
#include "./logic.c"

void testInfixToPostfix(char *infix, int index) {
    int len = strlen(infix);
    char *postfix = infixToPostfix(infix, len);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Result: %d\n\n", evaluatePostfix(postfix));
    free(postfix);
}

int main() {
    char expression1[] = "1 + 23 * 23 - 43";
    char expression2[] = "(10 + 20) * 30 - (40 - 50) ^ (1 + 2)";
    char expression3[] = "2 * (3 + 4)";
    char expression4[] = "5 + (2 + 3) * 4";
    char expression5[] = "3 + 4 * 2 / (1 - 5) ^ (2 ^ 3)";
    char expression6[] = "(100 + 200) / 2 * 5 + 7";
    char expression7[] = "(1 + 2) * (3 + 4) - 5";
    char expression8[] = "9 * (5 + 3 - 2 ^ 4)";
    char expression9[] = "8 + 3 * 2 - 5 * (1 + 2)";

    printf("Testing infix to postfix conversion:\n\n");
    testInfixToPostfix(expression1, 0);
    testInfixToPostfix(expression2, 1);
    testInfixToPostfix(expression3, 2);
    testInfixToPostfix(expression4, 3);
    testInfixToPostfix(expression5, 4);
    testInfixToPostfix(expression6, 5);
    testInfixToPostfix(expression7, 6);
    testInfixToPostfix(expression8, 7);
    testInfixToPostfix(expression9, 8);

    return 0;
}