/* 3. Reverse a string using stack
Given a string, reverse it using stack. For example “Data Structures” should be
converted to “serutcurtS ataD”. */

/* To solve this problem we will be using a character stack*/
#include "../Stack Implementation Using Singly LinkedList/logic.c"
#include <string.h>

/*Our approach for solving this problem is as follows:
As Stack is a LIFO data structure, we can reverse a string using a stack.

1. We will traverse the entire string.
2. We will push each character onto the stack.
3. After traversing the entire string we will pop each character from the stack and store it in a new string.
4. The new string will be the reversed string.
*/
char *reverseString(char *str);

int main(){
    char str[] = "Data Structures";
    printf("The Original String is : %s\n", str);
    
    printf("The Reversed String is: %s\n", reverseString(str));
    return 0;
}

/*
We will solve this problem using the approach mentioned above.
*/
char *reverseString(char *str){
    int len = strlen(str);
    char *reversedStr = (char *)malloc(sizeof(char) * len);
    Stack s;
    init(&s);
    int i;
    for(i = 0; str[i] != '\0'; i++){
        push(&s, str[i]);
    }
    i = 0;
    while(!isEmpty(s)){
        reversedStr[i++] = pop(&s);
    }

    return reversedStr;
}