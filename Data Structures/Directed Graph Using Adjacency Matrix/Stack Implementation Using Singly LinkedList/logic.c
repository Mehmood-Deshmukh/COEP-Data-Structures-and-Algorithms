#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void init_stack(Stack *s){
    *s = NULL; 
    return;  
}

void push(Stack *s, int data){
    StackNode *newStackNode = (StackNode *)malloc(sizeof(StackNode));
    if(!newStackNode) return;

    newStackNode->data = data;
    newStackNode->next = *s;

    *s = newStackNode;
    return;
}

int pop(Stack *s){
    if(is_empty_stack(*s)) return INT_MIN;

    StackNode *removedStackNode;
    int removedElement;

    removedStackNode = *s;
    removedElement = removedStackNode->data;
    *s = (*s)->next;

    free(removedStackNode);
    return removedElement;
}

int peek_stack(Stack s){
    if(is_empty_stack(s)) return INT_MIN;

    return s->data;
}

int is_empty_stack(Stack s){
    if(!s) return 1;

    return 0;
}

void display_stack(Stack s){
    if(is_empty_stack(s)){
        printf("Stack is Empty!\n");
        return;
    }

    printf("Displaying stack: ");
    StackNode *temp = s;
    while(temp){
        printf("%d | ", temp->data);
        temp = temp->next;
    }

    printf("\b\b \n");
    return;
}

void free_stack(Stack *s){
    while(!is_empty_stack(*s)){
        pop(s);
    }
}