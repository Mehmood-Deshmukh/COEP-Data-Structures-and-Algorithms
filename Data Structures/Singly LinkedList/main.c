#include "./logic.c"

int main() {
    List l;
    init(&l);
    display(l);
    append(&l, 1);
    append(&l, 2);
    append(&l, 3);
    display(l);
    printf("%d\n", length(l));
    insertAtBeginning(&l, 0);
    printf("%d\n", length(l));
    display(l);
    removeEnd(&l);
    display(l);
    removeBeginning(&l);
    display(l);
    printf("%d\n", length(l));
    removeNode(&l, l->next);
    display(l);
    printf("%d\n", length(l));
    addNodeAtPosition(&l, 1, 1);
    addNodeAtPosition(&l, 6, 0);
    addNodeAtPosition(&l, 90, 3);
    display(l);
    destroy(&l);
    display(l);
    fill(&l, 7);
    display(l);
    return 0;
}