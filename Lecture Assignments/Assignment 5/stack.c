#include "./stack.h"

void init_stack(Stack *s){
    *s = NULL; 
    return;  
}

void push_stack(Stack *s, Node *data){
    stack_node *newNode = (stack_node *)malloc(sizeof(stack_node));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = *s;

    *s = newNode;
    return;
}

Node *pop_stack(Stack *s){
    if(is_empty_stack(*s)) return NULL;

    stack_node *removedNode;
    Node *removedElement;

    removedNode = *s;
    removedElement = removedNode->data;
    *s = (*s)->next;

    free(removedNode);
    return removedElement;
}

Node *peek_stack(Stack s){
    if(is_empty_stack(s)) return NULL;

    return s->data;
}

int is_empty_stack(Stack s){
    if(!s) return 1;

    return 0;
}

int get_stack_size(Stack s){
    int count = 0;
    while(s){
        count++;
        s = s->next;
    }

    return count;
}