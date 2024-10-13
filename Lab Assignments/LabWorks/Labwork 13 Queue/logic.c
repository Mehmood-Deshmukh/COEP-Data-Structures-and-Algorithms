#include "header.h"

/*
This function initializes the queue.
It sets the head and tail pointers to NULL.
*/

void init(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

/*
This function adds a new node to the queue.
It takes the queue and the data to be added as arguments.

It creates a new node and sets its data to the given data.
If the queue is empty, it sets the head and tail pointers to the new node.
Otherwise, it adds the new node to the end of the queue and updates the tail pointer.
*/

void enqueue(Queue *q, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = NULL;

    if(q->head == NULL){
        q->head = newNode;
        q->tail = newNode;
    }else{
        q->tail->next = newNode;
        q->tail = newNode;
    }
}
/*
This function removes a node from the queue.
It takes the queue as an argument and returns the data of the removed node.

If the queue is empty, it returns INT_MIN.
Otherwise, it removes the first node from the queue and returns its data.
It also updates the head pointer to point to the next node in the queue.

if the node removed is the only node in the queue, it also updates the tail pointer.
*/

int dequeue(Queue *q){
    if(isEmpty(q)) return INT_MIN;

    Node *removedNode = q->head;
    int removedData = removedNode->data;

    q->head = q->head->next;
    free(removedNode);

    return removedData;
}

/*
This function returns the data of the first node in the queue.
It takes the queue as an argument.

If the queue is empty, it returns INT_MIN.
*/

int peek(Queue *q){
    if(isEmpty(q)) return INT_MIN;

    return q->head->data;
}

/*
This function checks if the queue is empty.
*/
int isEmpty(Queue *q){
    return q->head == NULL;
}

/*
This function displays the elements of the queue.
*/

void display(Queue *q){
    if(isEmpty(q)) return;

    Node *temp = q->head;
    while(temp){
        printf("%d | ", temp->data);
        temp = temp->next;
    }
    printf("\b\b  \n");
}

/*
This function clears the queue.
*/

void clear(Queue *q){
    while(!isEmpty(q)){
        dequeue(q);
    }
}



