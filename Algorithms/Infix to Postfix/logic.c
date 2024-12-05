#include "./Character Stack Implementation Using Singly LinkedList/header.h"
#include<ctype.h>
#include<stdlib.h>

int get_operator_precedence(char ch){
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

int is_operator(char ch){
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

char *infix_to_postfix(char *str, int len){
    Stack s;
    init(&s);
    
    char ch;
    char *postfix = (char *)malloc(sizeof(char) * (len + 1));
    if(!postfix) return '\0';

    int i, j;
    i = j = 0;
    while((ch = str[i++]) != '\0'){
        if(isspace(ch)) continue;

        if(ch == '('){
            push(&s, ch);
            continue;
        }

        if(ch == ')'){
            while(!is_empty(s) && peek(s) != '('){
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }

            pop(&s);
            continue;
        }

        if(is_operator(ch)){
            while(!is_empty(s) && get_operator_precedence(peek(s)) >= get_operator_precedence(ch)){
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }

            push(&s, ch);
            continue;
        }

        postfix[j++] = ch;
        if (!isdigit(str[i])) postfix[j++] = ' ';
    }

    while (!is_empty(s)){
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }

    postfix[--j] = '\0';


    return postfix;
}
