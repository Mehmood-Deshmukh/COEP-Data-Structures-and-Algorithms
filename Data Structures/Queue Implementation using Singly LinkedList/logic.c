#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void init(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue *q, int data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(!new_node) return;

    new_node->data = data;
    new_node->next = NULL;

    if(is_empty(*q)){
        q->head = new_node;
        q->tail = new_node;
        return;
    }

    q->tail->next = new_node;
    q->tail = new_node;

}

int dequeue(Queue *q){
    if(is_empty(*q)) return INT_MIN;
    Node *removed_node;
    int removed_element;

    removed_node = q->head;
    removed_element = removed_node->data;

    q->head = q->head->next;
    if(!q->head) q->tail = NULL;

    free(removed_node);
    return removed_element;
}

int is_empty(Queue q){
    if(!q.head) return 1;

    return 0;
}

int peek(Queue q){
    if(is_empty(q)) return INT_MIN;

    return q.head->data;
}

void display(Queue q){
    if(is_empty(q)){
        printf("Queue is Empty!\n");
        return;
    }

    printf("Displaying Queue: ");
    Node *temp = q.head;
    while(temp){
        printf("%d | ", temp->data);
        temp = temp->next;
    }

    printf("\b\b \n");
    return;
}