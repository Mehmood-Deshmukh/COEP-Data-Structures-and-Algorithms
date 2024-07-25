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
        removedElement = removedNode->data;
        *l = temp->next;
        free(removedNode);
        return removedElement;
    }
    

    while(temp && temp->next != n){
        temp = temp->next;
    }

    if(!temp) return INT_MIN;

    removedNode = temp->next;
    removedElement = removedNode->data;
    temp->next = temp->next->next;
    free(removedNode);
    
    return removedElement;
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

void swapNodes(List * l, Node * n1, Node * n2){
    if (n1 == n2 || !n1 || !n2 || !(*l)) return;

    List * master = l;

    while ((*master) != n1)
    {
        master = &(*master)->next;
    }

    (*master) = n2;

    master = &n1->next;

    while ((*master) != n2)
    {
        master = &(*master)->next;
    }

    (*master) = n1;

    Node * temp = n1->next;
    n1->next = n2->next;
    n2->next = temp;

    return;    
}

void fill(List *l, int number){
    if(number < 1) return;

    for(int i = 0; i < number; i++){
        append(l, rand() % 100 + 1);
    }

    return;
}

void reverseEven(List *l){
    if (length(*l) - 2 < 0) return;

    Node * p = *l, *q, *r, *s;

    while (p->next)
    {
        q = r = s = NULL;
        if (p->data % 2 == 0){
            q = p;
            r = p;
        }
        else if (p->next->data % 2 == 1){
            p = p->next;
            continue;
        }
        else {
            q = p->next;
            r = q;
        }

        while (r->next->data % 2 == 0)
        {
            r = r->next;
        }

        if (q == r){
            p = r->next;
            continue;
        }
        else s = q->next;

        if (q == p){
            *l = r;
        }
        else {
            p->next = r;
        }

        q->next = r->next;
        p = q;
        q = s;
        s = s->next;

        while (p != r)
        {
            q->next = p;
            p = q;
            q = s;
            s = s->next;
        }
        
        p = q;       
    }

    return;
    
}

int isPalindrome(List l){
    int len = length(l);
    if (len - 2 < 0) return 1;

    int halfLength = len / 2;
    int * arr = (int *) malloc(halfLength * sizeof(int));

    Node * p = l;

    for (int i = 0; i < halfLength; i++)
    {
        arr[i] = p->data;
        p = p->next;
    }

    if (len % 2 == 1) p = p->next;

    for (int i = halfLength - 1; i >= 0; i--)
    {
        if (arr[i] != p->data) return 0;
        p = p->next;
    }
    
    return 1; 
}

void removeDuplicates(List *l){
    int len = length(*l);

    int * arr = (int *) calloc(len, sizeof(int));
    if (!arr) return;

    int newlen = 0;
    Node * p = *l;

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
            free(q);
        }
        else{
            arr[newlen++] = data;
            p = p->next;
        }
    }

}

void destroy(List *l){
    if (!*l) return;

    while (*l){
        removeBeginning(l);
    }

    return;
}

void removeAndInsert(List *l, Node *n, int index){
    if (!*l) return;    

    if (*l == n) {
        *l = n->next;
    } else {
        Node *p = *l;
        while (p->next != n && p->next != NULL) {
            p = p->next;
        }
        if (p->next == NULL) return; 
        p->next = n->next;
    }

    if (!index)
    {
        n->next = *l;
        *l = n;
        return; 
    }
    
    Node *q = *l;

    for (int i = 0; i < index - 1; i++)
    {
        q = q->next;
    }

    n->next = q->next;
    q->next = n;

    return;
    
}