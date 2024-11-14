#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void init(Queue *q){
    init_stack(&q->s1);
    init_stack(&q->s2);
    return;
}

void enqueue(Queue *q, int data){
    push(&q->s1, data);
    return;   
}

void transfer(Stack *s1, Stack *s2){
    while(!is_empty_stack(*s1)){
        push(s2, pop(s1));
    }
    return;
}

int dequeue(Queue *q){
    if(is_empty_stack(q->s2)){
        if(is_empty_stack(q->s1)){
            printf("Queue is Empty\n");
            return INT_MIN;
        }
        transfer(&q->s1, &q->s2);
    }
    return pop(&q->s2);
}

int peek(Queue q){
    if(is_empty_stack(q.s2)){
        if(is_empty_stack(q.s1)){
            printf("Queue is Empty\n");
            return INT_MIN;
        }
        transfer(&q.s1, &q.s2);
    }
    return peek_stack(q.s2);
}

int is_empty(Queue q){
    return is_empty_stack(q.s1) && is_empty_stack(q.s2);
}