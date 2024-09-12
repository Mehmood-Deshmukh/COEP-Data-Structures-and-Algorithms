#include "../Infix to Postfix/logic.c"
#include "../../Data Structures/Stack Implementation Using Singly LinkedList/logic.c"
#include <stdlib.h>

int getNum(char **str){
    char result[1024];
    int i = 0;
    char ch;
    while((ch = **str) != '\0' && isdigit(ch)){
        result[i++] = ch;
        (*str)++;
    }

    result[i] = '\0';
    return atoi(result);
}


int evaluatePostfix(char *postfix){
    Stack s;
    init(&s);

    int answer;
    char ch;
    while((ch = *postfix++)!= '\0'){
        if(isspace(ch)) continue;

        if(isdigit(ch)){
            postfix--;
            push(&s, getNum(&postfix));
            continue;
        }

        if(isOperator(ch)){
            int operand2;
            switch(ch){
                case '+':
                    push(&s, pop(&s) + pop(&s));
                    break;
                case '*':
                    push(&s, pop(&s) * pop(&s));
                    break;
                case '-':
                    operand2 = pop(&s);
                    push(&s, pop(&s) - operand2);
                    break;
                case '/':
                    operand2 = pop(&s);
                    push(&s, pop(&s) / operand2);
                    break;
                case '%':
                    operand2 = pop(&s);
                    push(&s, pop(&s) % operand2);
                    break;
                case '^':
                    operand2 = pop(&s);
                    push(&s, (int) pow(pop(&s), operand2));
                    break;
                default:
                    break;
            }
        }
    }

    answer = pop(&s);

    return answer;
}