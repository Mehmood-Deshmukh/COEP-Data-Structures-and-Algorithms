#include "./Stack Implementation Using Singly LinkedList/header.h"

typedef struct Queue{
    Stack s1;
    Stack s2;
} Queue;

void init(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int peek(Queue q);
int is_empty(Queue q);