/*
2. Check for balanced parentheses in an expression
Given an expression string exp , write a program to examine whether the pairs and
the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp. For example, the program
should print true for exp = “[()]{}{[()()]()}” and false for exp = “[(])”
*/


/* To solve this problem we will be using a character stack*/
#include "../Character Stack Implementation Using Singly LinkedList/logic.c"
#include <string.h>

/*Our approach for solving this problem is as follows:
1. We will traverse the entire expression string.
2. If we encounter an opening bracket we will push it onto the stack.
3. If we encounter a closing bracket we will check if the top of the stack the closing bracket are pairs or not.
4. if they are not pairs or if the stack is empty then the expression is not balanced.
5. If the stack is empty after traversing the entire expression then the expression is balanced.
*/

int isValid(char *exp); /*Function to check if the expression is balanced or not*/

/* These are the helper functions */
int isOpening(char ch);  /* check if the character is an opening bracket */
int arePairs(char opening, char closing); /* check if the opening and closing brackets are pairs */

int main(){
    char exp[] = "[()]{}{[()()]()}";
    printf("The expression %s is %s\n", exp, isValid(exp) ? "Balanced" : "Not Balanced");

    char exp2[] = "[(])";
    printf("The expression %s is %s\n", exp2, isValid(exp2) ? "Balanced" : "Not Balanced");

    return 0;
}

/*
returns 1 if the character is an opening bracket i.e. '(' or '{' or '['
*/

int isOpening(char ch){
    return ch == '(' || ch == '{' || ch == '[';
}

/*
returns 1 if the opening and closing brackets are pairs i.e. '(' and ')' or '{' and '}' or '[' and ']' else returns 0
*/
int arePairs(char opening, char closing){
    if(opening == '(' && closing == ')') return 1;
    if(opening == '{' && closing == '}') return 1;
    if(opening == '[' && closing == ']') return 1;

    return 0;
}

/*
returns 1 if the expression is balanced else returns 0
we will use the approach mentioned above to solve this problem 
*/
int isValid(char *exp){
    cStack s;
    cinit(&s);
    int i;
    for(i = 0; exp[i] != '\0'; i++){
        if(isOpening(exp[i])){
            cpush(&s, exp[i]);
        } else {
            if(cisEmpty(s) || !arePairs(cpeek(s), exp[i])){
                return 0;
            }
            cpop(&s);
        }
    }

    return cisEmpty(s);
}