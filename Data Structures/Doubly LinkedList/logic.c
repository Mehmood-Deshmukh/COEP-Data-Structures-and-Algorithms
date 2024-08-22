#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void init(List *l)
{
    l->head = l->tail = NULL;
    return;
}

int isEmpty(List l)
{
    return (!l.head);
}

void append(List *l, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        return;

    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if (!l->head)
    {
        l->head = l->tail = newNode;
        return;
    }

    l->tail->next = newNode;
    newNode->prev = l->tail;
    l->tail = newNode;

    return;
}

void display(List l)
{
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

int length(List l)
{
    int len = 0;
    for (Node *temp = l.head; temp; temp = temp->next)
    {
        len++;
    }

    return len;
}