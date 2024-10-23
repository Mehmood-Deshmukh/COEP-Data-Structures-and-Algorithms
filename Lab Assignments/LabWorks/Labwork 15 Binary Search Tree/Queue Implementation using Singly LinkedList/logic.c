#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void qinit(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

void enQueue(Queue *q, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty(*q)){
        q->head = newNode;
        q->tail = newNode;
        return;
    }

    q->tail->next = newNode;
    q->tail = newNode;

}

int deQueue(Queue *q){
    if(isEmpty(*q)) return INT_MIN;
    Node *removedNode;
    int removedElement;

    removedNode = q->head;
    removedElement = removedNode->data;

    q->head = q->head->next;
    if(!q->head) q->tail = NULL;

    free(removedNode);
    return removedElement;
}

int isEmpty(Queue q){
    if(!q.head) return 1;

    return 0;
}

int peek(Queue q){
    if(isEmpty(q)) return INT_MIN;

    return q.head->data;
}

void display(Queue q){
    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }

    printf("Displaying Queue: ");
    Node *temp = q.head;
    while(temp){
        printf("%d | ", temp->data);
        temp = temp->next;
    }

    printf("\b\b \n");
    return;
}

int getSize(Queue q){
    if(isEmpty(q)) return 0;

    int count = 0;
    Node *temp = q.head;
    while(temp){
        count++;
        temp = temp->next;

    }

    return count;
}