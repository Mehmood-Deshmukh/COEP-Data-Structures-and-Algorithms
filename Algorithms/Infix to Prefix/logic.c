#include "./Character Stack Implementation Using Singly LinkedList/header.h"
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

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

void reverse_string(char* str, int len) {
    int i;
    for(i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}


char *infix_to_prefix(char *str){
    int len = strlen(str);
    reverse_string(str, len);

    for(int i = 0; i < len; i++){
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }

    char *postfix = infix_to_postfix(str, len);

    reverse_string(postfix, strlen(postfix));

    return postfix;    
}