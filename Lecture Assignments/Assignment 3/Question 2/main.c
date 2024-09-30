/*
2. Check for balanced parentheses in an expression
Given an expression string exp , write a program to examine whether the pairs and
the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp. For example, the program
should print true for exp = “[()]{}{[()()]()}” and false for exp = “[(])”
*/

#include "../Stack Implementation Using Singly LinkedList/logic.c"
#include <string.h>

int isValid(char *exp);

int main(){
    char exp[] = "[()]{}{[()()]()}";
    printf("The expression %s is %s\n", exp, isValid(exp) ? "Balanced" : "Not Balanced");

    char exp2[] = "[(])";
    printf("The expression %s is %s\n", exp2, isValid(exp2) ? "Balanced" : "Not Balanced");

    return 0;
}

int isOpening(char ch){
    return ch == '(' || ch == '{' || ch == '[';
}

int arePairs(char opening, char closing){
    if(opening == '(' && closing == ')') return 1;
    if(opening == '{' && closing == '}') return 1;
    if(opening == '[' && closing == ']') return 1;

    return 0;
}

int isValid(char *exp){
    Stack s;
    init(&s);
    int i;
    for(i = 0; exp[i] != '\0'; i++){
        if(isOpening(exp[i])){
            push(&s, exp[i]);
        } else {
            if(isEmpty(s) || !arePairs(peek(s), exp[i])){
                return 0;
            }
            pop(&s);
        }
    }

    return isEmpty(s);
}