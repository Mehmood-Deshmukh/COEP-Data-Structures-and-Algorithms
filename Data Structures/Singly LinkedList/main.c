#include "./logic.c"

int main() {
    List l;
    init(&l);
    display(l);
    append(&l, 1);
    append(&l, 2);
    append(&l, 3);
    display(l);
    insertAtBeginning(&l, 0);
    display(l);
    removeEnd(&l);
    display(l);
    removeBeginning(&l);
    display(l);
    return 0;
}