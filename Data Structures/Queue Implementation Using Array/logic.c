#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void init(Queue *q, int size){
    q->head = q->tail = -1;
    q->size = size;
    q->Q = (int *) malloc(sizeof(int) * size);
    return;
}

void enQueue(Queue *q, int data){
    if(isFull(*q)) return;

    if(isEmpty(*q)) q->head++;

    q->Q[++q->tail] = data;
}

int deQueue(Queue *q){
    if(isEmpty(*q)) return INT_MIN;

    return q->Q[q->head++];
}

int isEmpty(Queue q){
    if (q.head == -1) return 1;

    return 0;
}

int isFull(Queue q){
    if (q.tail == q.size - 1) return 1;
    
    return 0;
}

int peek(Queue q){
    if(isEmpty(q)) return INT_MIN;

    return q.Q[q.head];
}

void display(Queue q){
    if(isEmpty(q)) {
        printf("The Queue is Empty!");
        return;
    }

    printf("Printing The Queue: ");
    for (int i = q.head; i <= q.tail; i++){
        printf("%d | ", q.Q[i]);
    }
    
    printf("\b\b \n");
}