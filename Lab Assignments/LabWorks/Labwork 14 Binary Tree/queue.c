#include "queue.h"

void initQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue *q, Node data){
    qNode *newNode = (qNode *)malloc(sizeof(qNode));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = NULL;

    if(q->rear){
        q->rear->next = newNode;
    }
    q->rear = newNode;
    if(q->front == NULL){
        q->front = q->rear;
    }
}

Node dequeue(Queue *q){
    if(isEmpty(*q)) return;

    qNode *removedNode;
    Node removedData;
    removedNode = q->front;
    removedData = temp->data;

    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(removedNode);
    return removedData;
}

int isEmpty(Queue q){
    return q.front == NULL;
}

int getSize(Queue q){
    int size = 0;
    qNode *temp = q.front;
    while(temp){
        size++;
        temp = temp->next;
    }
    return size;
}