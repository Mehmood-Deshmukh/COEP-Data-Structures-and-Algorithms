#include <stdio.h>
#include "header.h"

int main() {
    Stack s;
    init(&s);
    display(s);
    printf("Is the Stack Empty? %d\n", is_empty(s));

    push(&s, 8);
    push(&s, 6);
    push(&s, 3);
    push(&s, 2);
    push(&s, 12);
    push(&s, 21);
    push(&s, 1);

    display(s);
    sort(&s);
    printf("Sorted Stack: ");
    display(s);

    pop(&s);
    pop(&s);

    display(s);

    printf("Peeked Element: %d\n", peek(s));

    pop(&s);

    printf("Is the Stack Empty? %d\n", is_empty(s));
    return 0;
}