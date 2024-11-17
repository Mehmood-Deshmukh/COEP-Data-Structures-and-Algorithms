#include "./stack.h"

void init_stack(Stack *s){
    *s = NULL; 
    return;  
}

void push(Stack *s, Node *data){
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    if(!new_node) return;

    new_node->data = data;
    new_node->next = *s;

    *s = new_node;
    return;
}

Node *pop(Stack *s){
    if(is_empty_stack(*s)) return NULL;

    StackNode *removed_node;
    Node *removed_element;

    removed_node = *s;
    removed_element = removed_node->data;
    *s = (*s)->next;

    free(removed_node);
    return removed_element;
}

Node *peek(Stack s){
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