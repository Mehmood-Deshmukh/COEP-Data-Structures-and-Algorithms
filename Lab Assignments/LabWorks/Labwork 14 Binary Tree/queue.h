#include<stdio.h>
#include<stdlib.h>
#include "header.h"

typedef struct qNode{
    Node data;
    struct qNode *next;
} qNode;

typedef struct Queue{
    qNode *front;
    qNode *rear;
} Queue;

/* function prototypes */

void initQueue(Queue *q);
void enqueue(Queue *q, Node data);
Node dequeue(Queue *q);
int isEmpty(Queue q);
int getSize(Queue q);