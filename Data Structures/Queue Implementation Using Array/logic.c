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

void enqueue(Queue *q, int data){
    if(is_full(*q)) return;

    if(is_empty(*q)) q->head++;

    q->Q[++q->tail] = data;
    return;
}

int dequeue(Queue *q){
    if(is_empty(*q)) return INT_MIN;

    int data = q->Q[q->head++];

    if(q->head > q->tail) q->head = q->tail = -1;

    return data;
}

int is_empty(Queue q){
    if (q.head == -1) return 1;

    return 0;
}

int is_full(Queue q){
    if (q.tail == q.size - 1) return 1;
    
    return 0;
}

int peek(Queue q){
    if(is_empty(q)) return INT_MIN;

    return q.Q[q.head];
}

void display(Queue q){
    if(is_empty(q)) {
        printf("The Queue is Empty!");
        return;
    }

    printf("Printing The Queue: ");
    for (int i = q.head; i <= q.tail; i++){
        printf("%d | ", q.Q[i]);
    }
    
    printf("\b\b \n");
    return;
}