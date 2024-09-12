#include "../../Data Structures/Character Stack Implementation Using Singly LinkedList/logic.c"
#include<ctype.h>

int getOperatorPrecedence(char ch){
    switch(ch){
        case '+': 
        case '-':
            return 1;
        case '/':
        case '*':
        case '%':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0;
        default:
            return -1;
    }
}

int isOperator(char ch){
    switch(ch){
        case '+':
        case '-':
        case '/':
        case '%':
        case '*':
        case '^':
            return 1;
        default:
            return 0;
    }
}

char *infixToPostfix(char *str, int len){
    cStack s;
    cinit(&s);
    
    char ch;
    char *postfix = (char *)malloc(sizeof(char) * (len + 1));
    if(!postfix) return NULL;

    int i, j;
    i = j = 0;
    while((ch = str[i++]) != '\0'){
        if(isspace(ch)) continue;

        if(ch == '('){
            cpush(&s, ch);
            continue;
        }

        if(ch == ')'){
            while(!cisEmpty(s) && cpeek(s) != '('){
                postfix[j++] = cpop(&s);
                postfix[j++] = ' ';
            }

            cpop(&s);
            continue;
        }

        if(isOperator(ch)){
            while(!cisEmpty(s) && getOperatorPrecedence(cpeek(s)) >= getOperatorPrecedence(ch)){
                postfix[j++] = cpop(&s);
                postfix[j++] = ' ';
            }

            cpush(&s, ch);
            continue;
        }

        postfix[j++] = ch;
        if (!isdigit(str[i])) postfix[j++] = ' ';
    }

    while (!cisEmpty(s)){
        postfix[j++] = cpop(&s);
        postfix[j++] = ' ';
    }

    postfix[--j] = '\0';


    return postfix;
}