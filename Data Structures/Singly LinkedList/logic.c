#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void init(List *l){
    *l = NULL;
    return;
}

void display(List l){
    if(!l){
        printf("LinkedList is Empty\n");
        return;
    }

    printf("Linked List: ");
    while (l) {
        printf(" %d ->", l->data);
        l = l->next;
    }
    printf("\b\b   \n");
    return;
}

void append(List *l, int data){
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) {
        return;
    }
    
    newNode->data = data;
    newNode->next = NULL;

    if(!*l){
        *l = newNode;
        return;
    }

    Node *temp = *l;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}
void insertAtBeginning(List *l, int data){
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) return;
    
    newNode->data = data;
    newNode->next = *l;

    *l = newNode;
    return;
}
int removeEnd(List *l){
    Node *temp, *removedNode;
    int removedElement;

    if(!*l) return INT_MIN;


    temp = *l;
    if (!temp->next){
        removedElement = temp->data;
        *l = NULL;
        free(temp);
        return removedElement;
    }
    

    while (temp->next->next != NULL){
        temp = temp->next;
    }

    removedNode = temp->next;
    temp->next = NULL;
    removedElement = removedNode->data;
    free(removedNode);

    return removedElement;
    
}
int removeBeginning(List *l){
    if(!*l) return INT_MIN;

    Node *removedNode = *l;
    int removedElement = removedNode->data;
    *l = (*l)->next;

    free(removedNode);
    
    return removedElement;
}

int removeNode(List *l, Node *n){
    if(!*l || !n) return INT_MIN;

    Node *removedNode;
    int removedElement;

    Node *temp = *l;
    
    if (temp == n){
        removedNode = temp;
        removedElement = temp->data;
        free(removedNode);
        *l = temp->next;
        return removedElement;
    }
    

    while(temp && temp->next != n){
        temp = temp->next;
    }

    if (temp && temp->next) {
        removedNode = temp->next;
        removedElement = temp->next->data;
        temp->next = temp->next->next;
        free(removedNode);
        return removedElement;
    }
    
    return INT_MIN;
}

void addNodeAtPosition(List *l, int data, int position){
    Node *newNode, *temp;
    int i;

    if (position < 0 || position > length(*l)){
        return;
    }
    
    newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = *l;
        *l = newNode;
    } else {
        temp = *l;
        for (i = 0; i < position - 1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return;
}
int length(List l){
    Node *temp = l;
    int length = 0;
    while (temp){
        length++;
        temp = temp->next;
    }
    return length;
}

void swapNodes(List * l, Node * n1, Node * n2);

void fill(List *l, int number){
    if(number < 1) return;

    for(int i = 0; i < number; i++){
        append(l, rand() % 100 + 1);
    }

    return;
}

void reverseEven(List *l);
int isPalindrome(List l);
void removeDuplicates(List *l);

void destroy(List *l){
    if (!*l) return;

    while (*l){
        removeBeginning(l);
    }

    return;
}

void removeAndInsert(List *l, Node *n, int index);