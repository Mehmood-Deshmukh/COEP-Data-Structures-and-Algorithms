#include "logic.c"

int main(){
    List l;
    init(&l);
    append(&l, 0);
    append(&l, 1);
    append(&l, 0);
    display(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));
    append(&l, 1);
    append(&l, 2);
    append(&l, 3);
    display(l);
    printf("The Length of Doubly LinkedList is: %d", length(l));
}