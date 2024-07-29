#include <stdio.h>
#include "..\..\..\Data Structures\Singly LinkedList\logic.c"

void reverse(List *head);
int main() {
    List list;
    init(&list);
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    display(list);

    reverse(&list);
    
    printf("After reversing: \n");
    display(list);

    return 0;
}

void reverse(List *head){
    Node *curr, *prev, *next;
    curr = *head;
    prev = NULL;
    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}