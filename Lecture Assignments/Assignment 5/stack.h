#ifndef STACK_H
#define STACK_H

#include "header.h"

typedef struct stack_node {
    Node *data;
    struct stack_node *next;
} stack_node;

typedef stack_node *Stack;

void init_stack(Stack *s);
void push_stack(Stack *s, Node *data);
Node *pop_stack(Stack *s);
Node *peek_stack(Stack s);
int is_empty_stack(Stack s);
int get_stack_size(Stack s);

#endif