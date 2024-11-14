#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void init(Stack *s){
    *s = NULL; 
    return;  
}

void push(Stack *s, int data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(!new_node) return;

    new_node->data = data;
    new_node->next = *s;

    *s = new_node;
    return;
}

int pop(Stack *s){
    if(is_empty(*s)) return INT_MIN;

    Node *removed_node;
    int removed_element;

    removed_node = *s;
    removed_element = removed_node->data;
    *s = (*s)->next;

    free(removed_node);
    return removed_element;
}

int peek(Stack s){
    if(is_empty(s)) return INT_MIN;

    return s->data;
}

int is_empty(Stack s){
    if(!s) return 1;

    return 0;
}

void display(Stack s){
    if(is_empty(s)){
        printf("Stack is Empty!\n");
        return;
    }

    printf("Displaying stack: ");
    Node *temp = s;
    while(temp){
        printf("%d | ", temp->data);
        temp = temp->next;
    }

    printf("\b\b \n");
    return;
}

void sort(Stack *s){
    Stack temp;
    init(&temp);

    while(!is_empty(*s)){
        int data = pop(s);

        while(!is_empty(temp) && peek(temp) > data){
            push(s, pop(&temp));
        }

        push(&temp, data);
    }

    *s = temp;
    return;
}