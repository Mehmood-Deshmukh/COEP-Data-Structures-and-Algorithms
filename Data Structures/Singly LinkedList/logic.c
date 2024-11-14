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
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) return;
    
    new_node->data = data;
    new_node->next = NULL;

    if(!*l){
        *l = new_node;
        return;
    }

    Node *temp = *l;

    while(temp->next) temp = temp->next;
    
    temp->next = new_node;
    return;
}

void insert_at_beginning(List *l, int data){
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) return;
    
    new_node->data = data;
    new_node->next = *l;

    *l = new_node;
    return;
}
int remove_end(List *l){
    Node *temp, *removed_node;
    int removed_element;

    if(!*l) return INT_MIN;


    temp = *l;
    if (!temp->next){
        removed_element = temp->data;
        *l = NULL;
        free(temp);
        return removed_element;
    }
    

    while (temp->next->next){
        temp = temp->next;
    }

    removed_node = temp->next;
    temp->next = NULL;
    removed_element = removed_node->data;
    free(removed_node);

    return removed_element;
    
}
int remove_beginning(List *l){
    if(!*l) return INT_MIN;

    Node *removed_node = *l;
    int removed_element = removed_node->data;
    *l = (*l)->next;

    free(removed_node);
    
    return removed_element;
}

int remove_node(List *l, Node *n){
    if(!*l || !n) return INT_MIN;

    Node *removed_node;
    int removed_element;

    Node *temp = *l;
    
    if (temp == n){
        return remove_beginning(l);
    }
    

    while(temp && temp->next != n){
        temp = temp->next;
    }

    if(!temp) return INT_MIN;

    removed_node = temp->next;
    removed_element = removed_node->data;
    temp->next = temp->next->next;
    free(removed_node);
    
    return removed_element;
}

void add_node_at_position(List *l, int data, int position){
    int len = length(*l);
    if (position < 0 || position > len){
        return;
    }

    if(position == 0){
        insert_at_beginning(l, data);
        return;
    }

    Node *new_node, *temp;
    int i;
    
    new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    temp = *l;
    for (i = 0; i < position - 1; i++){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;

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

void swap_nodes(List * l, Node * n1, Node * n2){
    if (!*l || !n1 || !n2) return;

    if (n1 == n2) return;

    Node *temp1 = *l, *temp2 = *l;
    Node *prev1 = NULL, *prev2 = NULL;

    while (temp1 && temp1 != n1){
        prev1 = temp1;
        temp1 = temp1->next;
    }

    while (temp2 && temp2 != n2){
        prev2 = temp2;
        temp2 = temp2->next;
    }

    if (!temp1 || !temp2) return;

    if (prev1) prev1->next = temp2;
    else *l = temp2;

    if (prev2) prev2->next = temp1;
    else *l = temp1;

    Node *temp = temp2->next;
    temp2->next = temp1->next;
    temp1->next = temp;

    return;   
}

void fill(List *l, int number){
    if(number < 1) return;

    for(int i = 0; i < number; i++){
        append(l, rand() % 100 + 1);
    }

    return;
}

void reverse_sequence(List *l, Node *prev, Node *start, Node *end, Node *next) {
    Node *current = start;
    Node *prev_node = next;
    Node *temp;

    while (current != next) {
        temp = current->next;
        current->next = prev_node;
        prev_node = current;
        current = temp;
    }

    if (prev) {
        prev->next = end;
    } else {
        *l = end;
    }
}

void reverse_even(List *l){
    if (!*l) return;

    Node *prev = NULL, *start = NULL, *end = NULL, *next = NULL;
    Node *current = *l;

    while (current) {
        if (current->data % 2) {
            if (!start) start = current;
            end = current;
        } else {
            if (start) {
                next = end->next;
                reverse_sequence(l, prev, start, end, next);
                start = end = NULL;
            }
            prev = current;
        }
        current = current->next;
    }

    if (start) {
        reverse_sequence(l, prev, start, end, NULL);
    }

    return;
}


int is_palindrome(List l){
    int len = length(l);
    if (len == 1) return 1;

    int half_length = len / 2;
    int * arr = (int *) malloc(half_length * sizeof(int));

    Node *temp = l;

    for (int i = 0; i < half_length; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }

    if (len % 2) temp = temp->next;

    for (int i = half_length - 1; i >= 0; i--)
    {
        if (arr[i] != temp->data) return 0;
        temp = temp->next;
    }
    
    return 1; 
}

void remove_duplicates(List *l){
    int len = length(*l);

    int *arr = (int *) calloc(len, sizeof(int));
    if (!arr) return;

    int newlen = 0;
    Node *temp = *l;

    arr[newlen++] = temp->data;

    while (temp->next){
        int data = temp->next->data;
        int duplicate = 0;

        for (int i = 0; i < newlen; i++){
            if (arr[i] == data){
                duplicate = 1;
                break;
            }
        }

        if (duplicate){
            Node *removed_node = temp->next;
            temp->next = temp->next->next;
            free(removed_node);
        }else{
            arr[newlen++] = data;
            temp = temp->next;
        }
    }

}

void destroy(List *l){
    if (!*l) return;

    while (*l){
        remove_beginning(l);
    }

    return;
}

void remove_and_insert(List *l, Node *n, int index){
    if (!*l) return;    

    if (*l == n) {
        *l = n->next;
    } else {
        Node *temp1 = *l;
        while (temp1->next && temp1->next != n) {
            temp1 = temp1->next;
        }
        if (!temp1->next) return; 
        temp1->next = n->next;
    }

    if (!index){
        n->next = *l;
        *l = n;
        return; 
    }
    
    Node *temp2 = *l;

    for (int i = 0; i < index - 1; i++){
        temp2 = temp2->next;
    }

    n->next = temp2->next;
    temp2->next = n;

    return;
    
}