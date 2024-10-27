#ifndef STACK_H
#define STACK_H

#include "header.h"

typedef struct Snode {
    Node *data;
    struct Snode *next;
} Snode;

typedef Snode *Stack;

void sInit(Stack *s);
void push(Stack *s, Node *data);
Node *pop(Stack *s);
Node *peek(Stack s);
int isEmpty(Stack s);
int getSize(Stack s);

#endif // STACK_H