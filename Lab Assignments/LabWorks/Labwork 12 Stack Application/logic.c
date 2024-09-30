#include "../../../Data Structures/Character Stack Implementation Using Singly LinkedList/logic.c"
#include "../../../Data Structures/Stack Implementation Using Singly LinkedList/logic.c"
#include<ctype.h>
#include <string.h>
#include<math.h>

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


int isValidInfix(const char *infix) {
    int len = strlen(infix);

    cStack parenthesesStack;
    cinit(&parenthesesStack);

    int lastWasOperator = 1; 
    int lastWasOperand = 0;
    int inNumber = 0;

    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (isspace(ch)) {
            continue;
        }

        if (isdigit(ch) || ch == '.') {
            if (lastWasOperand && !inNumber) {
                return 0; 
            }
            lastWasOperand = 1;
            lastWasOperator = 0;
            inNumber = 1;
        } else {
            inNumber = 0;
            if (isOperator(ch)) {
                if (lastWasOperator) {
                    return 0;  
                }
                lastWasOperator = 1;
                lastWasOperand = 0;
            } else if (ch == '(') {
                cpush(&parenthesesStack, ch);
                if (!lastWasOperator && !lastWasOperand) {
                    return 0;  
                }
                lastWasOperator = 1;
                lastWasOperand = 0;
            } else if (ch == ')') {
                if (cisEmpty(parenthesesStack) || cpop(&parenthesesStack) != '(') {
                    return 0;  
                }
                if (lastWasOperator) {
                    return 0;
                }
                lastWasOperator = 0;
                lastWasOperand = 1;
            } else {
                return 0;
            }
        }
    }

    if (!cisEmpty(parenthesesStack) || lastWasOperator) {
        return 0; 
    }

    return 1;
}



char *infixToPostfix(char *str, int len){
    if(!isValidInfix(str)) return '\0';
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