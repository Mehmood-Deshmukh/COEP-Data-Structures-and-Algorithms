#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void init(Queue *q, int size){
    q->head = q->tail = -1;
    q->count = 0;
    q->size = size;
    q->Q = (int *) malloc(sizeof(int) * size);
    return;
}

void enQueue(Queue *q, int data){
    if(isFull(*q)) return;

    if(isEmpty(*q)) q->head = 0;

    q->tail = (q->tail + 1) % q->size;
    q->Q[q->tail] = data;
    q->count++;
    return;
}

int deQueue(Queue *q){
    if(isEmpty(*q)) return INT_MIN;
    int data = q->Q[q->head];
    q->count--;
    q->head = (q->head + 1) % q->size;
    return data;
}

int isEmpty(Queue q){
    if (q.count == 0) return 1;

    return 0;
}

int isFull(Queue q){
    if (q.count == q.size) return 1;
    
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
    for (int i = q.head; i < q.head + q.count; i++){
        printf("%d | ", q.Q[i % q.size]);
    }
    
    printf("\b\b \n");
}