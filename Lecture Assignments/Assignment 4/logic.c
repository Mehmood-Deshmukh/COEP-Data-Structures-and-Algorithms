#include "header.h"

/*  
This function initializes the queue
It takes a pointer to the queue as an argument
It sets the head and tail of the queue to NULL
*/
void qinit(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}
/*
This function checks if the queue is empty
It takes a pointer to the queue as an argument
It returns 1 if the queue is empty and 0 otherwise
The queue is empty if the head is NULL
*/

int qempty(Queue *q) {
    return q->head == NULL;
}

/*
This function adds an element to the queue
It takes a pointer to the queue and the data to be added as arguments
It creates a new node with the data and adds it to the end of the queue

If the queue is empty, the new node is both the head and the tail of the queue
Otherwise, the new node is added after the tail and becomes the new tail
The new tail points to the head of the queue to maintain the circular structure
*/

void enq(Queue *q, Data data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;
    newNode->data = data;
    newNode->next = NULL;

    if(qempty(q)) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
        q->tail->next = q->head;
    }
}

/*
This function removes an element from the queue
It takes a pointer to the queue as an argument
It returns the data of the removed element

If the queue is empty, it returns an empty data structure
Otherwise, it removes the head of the queue and returns its data
If the queue becomes empty after removing the element, it sets the head and tail to NULL
Otherwise, it updates the head of the queue to the next element
The tail of the queue points to the new head to maintain the circular structure
*/

Data deq(Queue *q){
    if(qempty(q)) {
        Data data = {"", -1};
        return data;
    }

    Node *removedNode = q->head;
    Data removedData = removedNode->data;

    if(q->head == q->tail) {
        q->head = q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->tail->next = q->head;
    }

    free(removedNode);
    return removedData;
}
