#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void init(Queue *q){
    *q = NULL;
    return;
}

void enQueue(Queue *q, char data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(*q)){
        *q = newNode;
        return;
    }

    Node *temp = *q;
    while(temp && temp->next){
        temp = temp->next;
    }

    temp->next = newNode;
    return;
}

char deQueue(Queue *q){
    if(isEmpty(*q)) return '\0';

    Node *removedNode;
    char removedElement;

    removedNode = *q;
    removedElement = removedNode->data;

    *q = (*q)->next;

    free(removedNode);
    return removedElement;
}

int isEmpty(Queue q){
    if(!q) return 1;

    return 0;
}

char peek(Queue q){
    if(isEmpty(q)) return '\0';

    return q->data;
}

void display(Queue q){
        if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }

    printf("Displaying Queue: ");
    Node *temp = q;
    while(temp){
        printf("%c | ", temp->data);
        temp = temp->next;
    }

    printf("\b\b \n");
    return;
}