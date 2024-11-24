#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

char *infix_to_postfix(char *infix, int len);

char* results[] = {
    "1 23 23 * + 43 -",
    "10 20 + 30 * 40 50 - 1 2 + ^ -",
    "2 3 4 + *",
    "5 2 3 + 4 * +",
    "3 4 2 * 1 5 - 2 3 ^ ^ / +",
    "100 200 + 2 / 5 * 7 +",
    "1 2 + 3 4 + * 5 -",
    "9 5 3 + 2 4 ^ - *",
    "8 3 2 * + 5 1 2 + * -"
};

int expectedEvaluations[] = {
    487,
    1900,
    14,
    25,
    3,
    757,
    16,
    -72,
    -1
};

void printResult(char *postfix, char *result, int index) {
    if (strcmp(postfix, result) == 0) {
        printf(GREEN "Test %d: Correct: %s\n" RESET, index + 1, postfix);
    } else {
        printf(RED "Test %d: Incorrect\n" RESET, index + 1);
        printf(RED "Expected: %s\nGot: %s\n" RESET, result, postfix);
    }
}

void printEvaluationResult(int evaluation, int expectedEvaluation, int index) {
    if (evaluation == expectedEvaluation) {
        printf(GREEN "Evaluation Test %d: Correct: %d\n" RESET, index + 1, evaluation);
    } else {
        printf(RED "Evaluation Test %d: Incorrect\n" RESET, index + 1);
        printf(RED "Expected: %d\nGot: %d\n" RESET, expectedEvaluation, evaluation);
    }
}

void testInfixToPostfix(char *infix, int index) {
    int len = strlen(infix);
    char *postfix = infixToPostfix(infix, len);
    if (postfix) {
        printf("Infix Expression: %s\n", infix);
        printResult(postfix, results[index], index);
        int evaluation = evaluatePostfix(postfix);
        printEvaluationResult(evaluation, expectedEvaluations[index], index);
        free(postfix);
    } else {
        printf(RED "Test %d Failed!.\n" RESET, index + 1);
    }
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