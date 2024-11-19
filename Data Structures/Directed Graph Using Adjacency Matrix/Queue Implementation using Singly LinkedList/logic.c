#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void init_queue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue *q, int data){
    QueueNode *newQueueNode = (QueueNode *)malloc(sizeof(QueueNode));
    if(!newQueueNode) return;

    newQueueNode->data = data;
    newQueueNode->next = NULL;

    if(is_empty_queue(*q)){
        q->head = newQueueNode;
        q->tail = newQueueNode;
        return;
    }

    q->tail->next = newQueueNode;
    q->tail = newQueueNode;

}

int dequeue(Queue *q){
    if(is_empty_queue(*q)) return INT_MIN;
    QueueNode *removedQueueNode;
    int removedElement;

    removedQueueNode = q->head;
    removedElement = removedQueueNode->data;

    q->head = q->head->next;
    if(!q->head) q->tail = NULL;

    free(removedQueueNode);
    return removedElement;
}

int is_empty_queue(Queue q){
    if(!q.head) return 1;

    return 0;
}

int peek_queue(Queue q){
    if(is_empty_queue(q)) return INT_MIN;

    return q.head->data;
}

void display_queue(Queue q){
        if(is_empty_queue(q)){
        printf("Queue is Empty!\n");
        return;
    }

    printf("Displaying Queue: ");
    QueueNode *temp = q.head;
    while(temp){
        printf("%d | ", temp->data);
        temp = temp->next;
    }

    printf("\b\b \n");
    return;
}

void free_queue(Queue *q){
    while(!is_empty_queue(*q)) dequeue(q);
}