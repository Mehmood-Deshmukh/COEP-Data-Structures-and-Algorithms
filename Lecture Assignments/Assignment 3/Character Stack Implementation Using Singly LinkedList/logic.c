#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./header.h"

void cinit(cStack *s){
    *s = NULL; 
    return;  
}

void cpush(cStack *s, char data){
    cNode *newNode = (cNode *)malloc(sizeof(cNode));
    if(!newNode) return;

    newNode->data = data;
    newNode->next = *s;

    *s = newNode;
    return;
}

char cpop(cStack *s){
    if(cisEmpty(*s)) return '\0';

    cNode *removedNode;
    char removedElement;

    removedNode = *s;
    removedElement = removedNode->data;
    *s = (*s)->next;

    free(removedNode);
    return removedElement;
}

char cpeek(cStack s){
    if(cisEmpty(s)) return '\0';

    return s->data;
}

int cisEmpty(cStack s){
    if(!s) return 1;

    return 0;
}

void cdisplay(cStack s){
    if(cisEmpty(s)){
        printf("Stack is Empty!\n");
        return;
    }

    printf("Displaying stack: ");
    cNode *temp = s;
    while(temp){
        printf("%c | ", temp->data);
        temp = temp->next;
    }

    printf("\b\b \n");
    return;
}