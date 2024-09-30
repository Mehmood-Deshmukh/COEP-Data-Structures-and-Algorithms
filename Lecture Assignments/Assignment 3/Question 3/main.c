/* 3. Reverse a string using stack
Given a string, reverse it using stack. For example “Data Structures” should be
converted to “serutcurtS ataD”. */

#include "../Stack Implementation Using Singly LinkedList/logic.c"
#include <string.h>
char *reverseString(char *str);

int main(){
    char str[] = "Data Structures";
    printf("The Original String is : %s\n", str);
    
    printf("The Reversed String is: %s\n", reverseString(str));
    return 0;
}

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