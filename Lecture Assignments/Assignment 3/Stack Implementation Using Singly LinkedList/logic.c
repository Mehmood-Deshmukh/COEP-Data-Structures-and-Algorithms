#include "./header.h"

void init(Stack *s){
    *s = NULL; 
    return;  
}

void push(Stack *s, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = *s;

    *s = newNode;
    return;
}

int pop(Stack *s){
    if(isEmpty(*s)) return INT_MIN;

    Node *removedNode;
    int removedElement;

    removedNode = *s;
    removedElement = removedNode->data;
    *s = (*s)->next;

    free(removedNode);
    return removedElement;
}

int peek(Stack s){
    if(isEmpty(s)) return INT_MIN;

    return s->data;
}

int isEmpty(Stack s){
    if(!s) return 1;

    return 0;
}

void display(Stack s){
    if(isEmpty(s)){
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