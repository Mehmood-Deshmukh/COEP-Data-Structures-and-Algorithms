#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void init(List *l) {
    l->head = l->tail = NULL;
    return;
}

int is_empty(List l) {
    return (!l.head);
}

void append(List *l, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) return;

    new_node->data = data;
    new_node->next = new_node->prev = NULL;

    if (is_empty(*l)){
        l->head = l->tail = new_node;
        return;
    }

    l->tail->next = new_node;
    new_node->prev = l->tail;
    l->tail = new_node;

    return;
}

void display(List l) {
    if (is_empty(l)) return;

    printf("Displaying the LinkedList: ");

    for (Node *temp = l.head; temp; temp = temp->next){
        printf("%d <-> ", temp->data);
    }
    printf("\b\b\b\b     \n");

    return;
}

int length(List l) {
    int len = 0;
    for (Node *temp = l.head; temp; temp = temp->next){
        len++;
    }

    return len;
}

void insert_at_start(List *l, int data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(!new_node) return;

    new_node->data = data;
    new_node->next = new_node->prev = NULL;

    if(is_empty(*l)){
        l->head = l->tail = new_node;
        return;
    }

    new_node->next = l->head;
    l->head->prev = new_node;
    l->head = new_node;

    return;
}

void insert_at_index(List *l, int data, int index){
    if(index < 0 || index > length(*l)) return;

    if(index == 0){
        insert_at_start(l, data);
        return;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if(!new_node) return;

    new_node->data = data;
    new_node->next = new_node->prev = NULL;

    Node *temp = l->head;

    for(int i = 0; i < index - 1 && temp; i++){
        temp = temp->next;
    }

    new_node->next = temp->next;
    if (temp->next) temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;

    if (new_node->next == NULL) {
        l->tail = new_node;
    }

    return;

}


int remove_start(List *l){
    if(is_empty(*l)) return INT_MIN;

    Node *removed_node;
    int removed_element;

    removed_node = l->head;
    removed_element = removed_node->data;

    l->head = removed_node->next;
    if(is_empty(*l)){
        l->tail = NULL;
    }else {
        l->head->prev = NULL;
    }

    free(removed_node);

    return removed_element;
}

int remove_at_index(List *l, int index){
    if(is_empty(*l) || index < 0 || index >= length(*l)) return INT_MIN;
    if(index == 0) return remove_start(l);
    

    Node *removed_node, *temp = l->head;
    int removed_element;

    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }

    removed_node = temp->next;
    temp->next = removed_node->next;
    if(removed_node->next){
        removed_node->next->prev = temp;
    }else{
        l->tail = temp;
    }

    removed_element = removed_node->data;
    free(removed_node);

    return removed_element;
}

int remove_at_end(List *l){
    if(is_empty(*l)) return INT_MIN;

    Node *removed_node;
    int removed_element;

    removed_node = l->tail;
    removed_element = removed_node->data;
    l->tail = l->tail->prev;
    if(!l->tail){
        l->head = NULL;
    }else{
        l->tail->next = NULL; 
    }


    free(removed_node);
    return removed_element;
}

void destroy(List *l){
    if(is_empty(*l)) return;

    while(!is_empty(*l)) remove_start(l);

    return;
}

void reverse_list(List *l){
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