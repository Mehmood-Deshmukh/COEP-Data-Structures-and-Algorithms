#ifndef QUEUE_H
#define QUEUE_H

#include "header.h"

typedef struct queue_node {
    Node *data;
    struct queue_node *next;
} queue_node;

typedef struct{
    queue_node *front;
    queue_node *rear;
} Queue;

void init_queue(Queue *q);
void enqueue(Queue *q, Node *data);
Node *dequeue(Queue *q);
Node *peek_queue(Queue q);
int is_empty_queue(Queue q);
int get_queue_size(Queue q);

#endif