#include "./queue.h"

void init_queue(Queue *q){
    q->front = q->rear = NULL;
    return;  
}

void enqueue(Queue *q, Node *data){
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if(!new_node) return;

    new_node->data = data;
    new_node->next = NULL;

    if(!q->front){
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;

    return;
}

Node *dequeue(Queue *q){
    if(is_empty_queue(*q)) return NULL;

    QueueNode *removed_node;
    Node *removed_element;

    removed_node = q->front;
    removed_element = removed_node->data;

    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }else{
        q->front = q->front->next;
    }

    free(removed_node);
    return removed_element;
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

    QueueNode *temp = q.front;
    while(temp){
        count++;
        temp = temp->next;
    }

    return count;
}