#include "./queue.h"

void qInit(Queue *q){
    q->front = q->rear = NULL;
    return;  
}

void enqueue(Queue *q, Node *data){
    Qnode *newNode = (Qnode *)malloc(sizeof(Qnode));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = NULL;

    if(!q->front){
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;

    return;
}

Node *dequeue(Queue *q){
    if(isEmptyQueue(*q)) return NULL;

    Qnode *removedNode;
    Node *removedElement;

    removedNode = q->front;
    removedElement = removedNode->data;

    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }else{
        q->front = q->front->next;
    }

    free(removedNode);
    return removedElement;
}

Node *qPeek(Queue q){
    if(isEmptyQueue(q)) return NULL;

    return q.front->data;
}

int isEmptyQueue(Queue q){
    if(!q.front) return 1;

    return 0;
}

int getQueueSize(Queue q){
    int count = 0;

    Qnode *temp = q.front;
    while(temp){
        count++;
        temp = temp->next;
    }

    return count;
}