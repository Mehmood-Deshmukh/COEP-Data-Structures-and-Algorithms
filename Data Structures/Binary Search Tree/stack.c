#include "./stack.h"

void sInit(Stack *s){
    *s = NULL; 
    return;  
}

void push(Stack *s, Node *data){
    Snode *newNode = (Snode *)malloc(sizeof(Snode));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = *s;

    *s = newNode;
    return;
}

Node *pop(Stack *s){
    if(isEmpty(*s)) return NULL;

    Snode *removedNode;
    Node *removedElement;

    removedNode = *s;
    removedElement = removedNode->data;
    *s = (*s)->next;

    free(removedNode);
    return removedElement;
}

Node *peek(Stack s){
    if(isEmpty(s)) return NULL;

    return s->data;
}

int isEmpty(Stack s){
    if(!s) return 1;

    return 0;
}

int getSize(Stack s){
    int count = 0;
    while(s){
        count++;
        s = s->next;
    }

    return count;
}