#include <stdio.h>
#include "logic.c"

int main() {
    Stack s;
    init(&s, 1);
    display(s);
    printf("Is the Stack Empty? %d\n", isEmpty(s));

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    display(s);

    pop(&s);
    pop(&s);

    display(s);

    printf("Peeked Element: %d\n", peek(s));

    pop(&s);

    printf("Is the Stack Empty? %d\n", isEmpty(s));
    return 0;
}