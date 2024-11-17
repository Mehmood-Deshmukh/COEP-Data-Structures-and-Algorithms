#ifndef STACK_H
#define STACK_H

#include "header.h"

typedef struct StackNode {
    Node *data;
    struct StackNode *next;
} StackNode;

typedef StackNode *Stack;

void init_stack(Stack *s);
void push(Stack *s, Node *data);
Node *pop(Stack *s);
Node *peek(Stack s);
int is_empty_stack(Stack s);
int get_stack_size(Stack s);

#endif // STACK_H