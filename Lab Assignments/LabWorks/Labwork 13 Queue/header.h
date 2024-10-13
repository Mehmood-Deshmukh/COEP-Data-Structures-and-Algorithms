/* Implement a queue of integers using an ADT list. Invoke all queue operations using a menu-driven program. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
This is the structure of a node in the queue.
It contains:
    - data: the integer value of the node
    - next: a pointer to the next node in the queue
*/

typedef struct Node{
    int data;
    struct Node *next;
} Node;

/*
This is the structure of the queue.
It contains:
    - head: a pointer to the first node in the queue
    - tail: a pointer to the last node in the queue
*/

typedef struct Queue{
    Node *head;
    Node *tail;
} Queue;

/*These are the function prototypes for the queue operations*/
void init(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
int peek(Queue *q);
int isEmpty(Queue *q);
void display(Queue *q);
void clear(Queue *q);
