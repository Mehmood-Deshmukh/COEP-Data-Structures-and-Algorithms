#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void init(Queue *q, int size){
    q->head = q->tail = -1;
    q->length = 0;
    q->size = size;
    q->array = (int *) malloc(sizeof(int) * size);
    return;
}

void enqueue(Queue *q, int data){
    if(is_full(*q)) return;

    if(is_empty(*q)) q->head = 0;

    q->tail = (q->tail + 1) % q->size;
    q->array[q->tail] = data;
    q->length++;
    return;
}

int dequeue(Queue *q){
    if(is_empty(*q)) return INT_MIN;
    int data = q->array[q->head];
    q->length--;
    q->head = (q->head + 1) % q->size;
    return data;
}

int is_empty(Queue q){
    if (q.length == 0) return 1;

    return 0;
}

int is_full(Queue q){
    if (q.length == q.size) return 1;
    
    return 0;
}

int peek(Queue q){
    if(is_empty(q)) return INT_MIN;

    return q.array[q.head];
}

void display(Queue q){
    if(is_empty(q)) {
        printf("The Queue is Empty!");
        return;
    }

    printf("Printing The Queue: ");
    for (int i = q.head; i < q.head + q.length; i++){
        printf("%d | ", q.array[i % q.size]);
    }
    
    printf("\b\b \n");
}