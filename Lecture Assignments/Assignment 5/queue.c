#include "./queue.h"

void init_queue(Queue *q){
    q->front = q->rear = NULL;
    return;  
}

void enqueue(Queue *q, Node *data){
    queue_node *newNode = (queue_node *)malloc(sizeof(queue_node));
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
    if(is_empty_queue(*q)) return NULL;

    queue_node *removedNode;
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

Node *peek_queue(Queue q){
    if(is_empty_queue(q)) return NULL;

    return q.front->data;
}

int is_empty_queue(Queue q){
    if(!q.front) return 1;

    return 0;
}

int get_queue_size(Queue q){
    int count = 0;

    queue_node *temp = q.front;
    while(temp){
        count++;
        temp = temp->next;
    }

    return count;
}