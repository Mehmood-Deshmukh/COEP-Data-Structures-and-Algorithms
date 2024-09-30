#include "logic.c"

int main(){
    List l;
    init(&l);
    append(&l, 0);
    append(&l, 1);
    append(&l, 0);
    display(l);
    printf("The Length of Doubly Circular LinkedList is: %d\n", length(l));
    append(&l, 1);
    append(&l, 2);
    append(&l, 3);
    display(l);
    printf("The Length of  Doubly Circular LinkedList is: %d\n", length(l));
    insertAtStart(&l, 12);
    insertAtStart(&l, 23);
    insertAtIndex(&l, 39, 4);
    display(l);
    printf("The Length of  Doubly Circular LinkedList is: %d\n", length(l));
    printf("Removed Element from index 2: %d\n", removeAtIndex(&l, 2));
    display(l);
    printf("Removed Element from start: %d\n", removeStart(&l)); 
    printf("Removed Element from start: %d\n", removeStart(&l)); 
    display(l);
    printf("The Length of  Doubly Circular LinkedList is: %d\n", length(l));
    printf("Removed Element from end: %d\n", removeAtEnd(&l)); 
    display(l);
    printf("The Length of  Doubly Circular LinkedList is: %d\n", length(l));
    reverseList(&l);
    display(l);
    printf("The Length of  Doubly Circular LinkedList is: %d\n", length(l));
    sortList(&l);
    display(l);
    printf("The Length of  Doubly Circular LinkedList is: %d\n", length(l));
    destroy(&l);
    display(l);
    printf("The Length of  Doubly Circular LinkedList is: %d\n", length(l));
}