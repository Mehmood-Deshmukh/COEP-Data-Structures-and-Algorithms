#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    List l;
    init(&l);
    append(&l, 0);
    append(&l, 1);
    append(&l, 0);
    display(l);
    printf("The Length of Doubly LinkedList is: %d\n\n", length(l));
    append(&l, 1);
    append(&l, 2);
    append(&l, 3);
    display(l);
    printf("The Length of Doubly LinkedList is: %d\n\n", length(l));
    insert_at_start(&l, 12);
    insert_at_start(&l, 23);
    insert_at_index(&l, 39, 4);
    display(l);
    printf("The Length of Doubly LinkedList is: %d\n\n", length(l));
    printf("Removed Element from index 2: %d\n", remove_at_index(&l, 2));
    printf("Removed Element from start: %d\n", remove_start(&l)); 
    printf("Removed Element from start: %d\n", remove_start(&l)); 
    display(l);
    printf("The Length of Doubly LinkedList is: %d\n\n", length(l));
    printf("Removed Element from end: %d\n", remove_at_end(&l)); 
    display(l);
    printf("The Length of Doubly LinkedList is: %d\n\n", length(l));
    reverse_list(&l);
    display(l);
    printf("The Length of Doubly LinkedList is: %d\n\n", length(l));
    destroy(&l);
    display(l);
    printf("The Length of Doubly LinkedList is: %d\n\n", length(l));
}