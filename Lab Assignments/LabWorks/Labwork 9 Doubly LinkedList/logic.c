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

    if (isEmpty(*l))
    {
        l->head = l->tail = newNode;
        return;
    }

    l->tail->next = newNode;
    newNode->prev = l->tail;
    l->tail = newNode;

    return;
}

void displayLR(List l) {
    if (isEmpty(l))
        return;

    printf("Displaying the LinkedList: ");

    for (Node *temp = l.head; temp; temp = temp->next)
    {
        printf("%d <-> ", temp->data);
    }
    printf("\b\b\b\b     \n");

    return;
}

void displayRL(List l) {
    if (isEmpty(l))
        return;

    printf("Displaying the LinkedList: ");

    for (Node *temp = l.tail; temp; temp = temp->prev)
    {
        printf("%d <-> ", temp->data);
    }
    printf("\b\b\b\b     \n");

    return;
}

int length(List l) {
    int len = 0;
    for (Node *temp = l.head; temp; temp = temp->next)
    {
        len++;
    }

    return len;
}

void insertAtStart(List *l, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if(isEmpty(*l)){
        l->head = l->tail = newNode;
        return;
    }

    newNode->next = l->head;
    l->head->prev = newNode;
    l->head = newNode;

    return;
}

void insertAtIndex(List *l, int data, int index){
    if(index < 0 || index > length(*l)) return;

    if(index == 0){
        insertAtStart(l, data);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    Node *temp = l->head;

    for(int i = 0; i < index - 1 && temp; i++){
        temp = temp->next;
    }

    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;

    if (newNode->next == NULL) {
        l->tail = newNode;
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
    if(isEmpty(*l)){
        l->tail = NULL;
    }else {
        l->head->prev = NULL;
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
        l->tail->next = NULL; 
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

    while (curr){
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    l->head = prev;
    l->tail = temp;
    return;
}

Node *getMid(List *l){
    Node *slow, *fast;
    slow = fast = l->head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void merge(List *l, List *l1, List *l2){
    destroy(l);

    if (l1->head == NULL) {
        *l = *l2;
        return;
    }
    if (l2->head == NULL) {
        *l = *l1;
        return;
    }


    Node *temp1, *temp2;
    temp1 = l1->head;
    temp2 = l2->head;

    while(temp1 && temp2){
        if(temp1->data < temp2->data){
            append(l, temp1->data);
            temp1 = temp1->next;
        }else{
            append(l, temp2->data);
            temp2 = temp2->next;
        }
    }

    while(temp1){
        append(l, temp1->data);
        temp1 = temp1->next;
    }

    while(temp2){
        append(l, temp2->data);
        temp2 = temp2->next;
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
    if(!l->head || !l->head->next) return;

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

    while(temp){
        append(&l2, temp->data);
        temp = temp->next;
    }


    sortList(&l1);
    sortList(&l2);


    merge(l, &l1, &l2);
    return;
}



void removeDuplicates(List *l){
    int len = length(*l);

    int * arr = (int *) calloc(len, sizeof(int));
    if (!arr) return;

    int newlen = 0;
    Node * p = l->head;

    arr[newlen++] = p->data;

    while (p->next)
    {
        int data = p->next->data;
        int duplicate = 0;

        for (int i = 0; i < newlen; i++)
        {
            if (arr[i] == data){
                duplicate = 1;
                break;
            }
        }

        if (duplicate)
        {
            Node * q = p->next;
            p->next = p->next->next;
            p->next->prev = p;
            free(q);
        }
        else{
            arr[newlen++] = data;
            p = p->next;
        }
    }

}


int isPalindrome(List l){
    Node *temp1 = l.head;
    Node *temp2 = l.tail;

    while(temp1 && temp2){
        if(temp1->data != temp2->data) return 0;
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }

    return 1;

}
