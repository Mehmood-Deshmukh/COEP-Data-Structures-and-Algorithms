
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void init(List *l) {
    l->head = l->tail = NULL;
    return;
}

int isEmpty(List l) {
    return (!l.head);
}

void append(List *l, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        return;

    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if (isEmpty(*l)){
        l->head = l->tail = newNode;
        newNode->next = newNode->prev = newNode;
        return;
    }

    l->tail->next = newNode;
    newNode->prev = l->tail;
    l->tail = newNode;

    newNode->next = l->head;
    l->head->prev = newNode;

    return;
}

void display(List l) {
    if (isEmpty(l)){
        return;
    }

    printf("Displaying the LinkedList: ");
    Node *temp = l.head;
    do{
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while(temp != l.head);


    printf("\b\b\b\b     \n");

    return;
}

int length(List l) {
    if(isEmpty(l)) return 0;
    int len = 0;
    Node *temp = l.head;
    do{
        len++;
        temp = temp->next;
    } while(temp != l.head);

    return len;
}

void insertAtStart(List *l, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(isEmpty(*l)){
        l->head = l->tail = newNode;
        newNode->next = newNode->prev = newNode;
        return;
    }

    newNode->next = l->head;
    l->head->prev = newNode;
    l->head = newNode;

    l->tail->next = newNode;
    l->head->prev = l->tail;

    return;
}

void insertAtIndex(List *l, int data, int index){
    if(index < 0 || index > length(*l) || isEmpty(*l)) return;

    if(index == 0){
        insertAtStart(l, data);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    Node *temp = l->head;

    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }

    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;

    if (newNode->next == l->head) {
        l->tail = newNode;
        l->head->prev = newNode;
    }

    return;

}


int removeStart(List *l){
    if(isEmpty(*l)) return INT_MIN;

    Node *removedNode;
    int removedElement;

    removedNode = l->head;
    removedElement = removedNode->data;

    l->head = removedNode->next;

    if(l->head == removedNode){
        l->tail = l->head =  NULL;
    }else {
        l->head->prev = l->tail;
        l->tail->next = l->head;
    }

    free(removedNode);

    return removedElement;
}

int removeAtIndex(List *l, int index){
    if(isEmpty(*l) || index < 0 || index > length(*l)) return INT_MIN;
    if(index == 0){
        return removeStart(l);
    }

    Node *removedNode, *temp = l->head;
    int removedElement;

    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }

    removedNode = temp->next;
    temp->next = removedNode->next;
    if(removedNode->next){
        removedNode->next->prev = temp;
    }else{
        l->tail = temp;
        temp->next = l->head;
    }

    removedElement = removedNode->data;
    free(removedNode);

    return removedElement;
}

int removeAtEnd(List *l){
    if(isEmpty(*l)) return INT_MIN;

    Node *removedNode;
    int removedElement;

    removedNode = l->tail;
    removedElement = removedNode->data;
    l->tail = l->tail->prev;
    if(!l->tail){
        l->head = NULL;
    }else{
        l->tail->next = l->head; 
    }


    free(removedNode);
    return removedElement;
}

void destroy(List *l){
    if(isEmpty(*l)) return;

    while(!isEmpty(*l)){
        removeStart(l);
    }

    return;
}

void reverseList(List *l){
    Node *curr, *next, *prev, *temp;
    prev = NULL;
    temp = curr = l->head;

    do{
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }while (curr != l->head);

    l->head = prev;
    l->tail = temp;

    l->head->prev = l->tail;
    l->tail->next = l->head;
    return;
}

Node *getMid(List *l){
    Node *slow, *fast;
    slow = fast = l->head;
    
    do{
        slow = slow->next;
        fast = fast->next->next;
    } while(fast!= l->head && fast->next != l->head);


    return slow;
}

void merge(List *l, List *l1, List *l2){
    destroy(l);

    Node *temp1, *temp2;
    temp1 = l1->head;
    temp2 = l2->head;
    int count1 = 0;
    int count2 = 0;

    do{
        if(temp1->data < temp2->data){
            append(l, temp1->data);
            temp1 = temp1->next;
            count1++;
        }else{
            append(l, temp2->data);
            temp2 = temp2->next;
            count2++;
        }
    }while((temp1 != l1->head || count1 == 0) && (temp2 != l2->head || count2 == 0));


    while(temp1 != l1->head || count1 == 0){
        append(l, temp1->data);
        temp1 = temp1->next;
        count1++;
    }

    while(temp2 != l2->head || count2 == 0){
        append(l, temp2->data);
        temp2 = temp2->next;
        count2++;
    }

}

void fill(List *l, int number){
    if(number < 1) return;

    for(int i = 0; i < number; i++){
        append(l, rand() % 100 + 1);
    }

    return;
}

void sortList(List *l){
    if(l->head->next == l->head) return;

    Node *mid = getMid(l);

    List l1, l2;
    init(&l1);
    init(&l2);

    Node *temp = l->head;
    while(temp != mid){
        append(&l1, temp->data);
        temp = temp->next;
    }

    temp = mid;

    while(temp != l->head){
        append(&l2, temp->data);
        temp = temp->next;
    }

    sortList(&l1);
    sortList(&l2);


    merge(l, &l1, &l2);
    return;
}