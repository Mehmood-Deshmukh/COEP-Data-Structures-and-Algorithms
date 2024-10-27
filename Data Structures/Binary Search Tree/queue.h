#ifndef QUEUE_H
#define QUEUE_H

#include "header.h"

typedef struct Qnode {
    Node *data;
    struct Qnode *next;
} Qnode;

typedef struct{
    Qnode *front;
    Qnode *rear;
} Queue;

void qInit(Queue *q);
void enqueue(Queue *q, Node *data);
Node *dequeue(Queue *q);
Node *qPeek(Queue q);
int isEmptyQueue(Queue q);
int getQueueSize(Queue q);

#endif // QUEUE_H