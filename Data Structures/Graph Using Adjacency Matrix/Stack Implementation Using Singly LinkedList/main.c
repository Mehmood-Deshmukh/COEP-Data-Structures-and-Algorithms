#include "logic.c"

int main(){
    Stack s;

    init_stack(&s);

    push(&s, 6);
    push(&s, 7);
    push(&s, -5);
    push(&s, 0);
    push(&s, -2);
    push(&s, 1);

    display_stack(s);

    push(&s, -65);
    push(&s, 48);

    display_stack(s);

    pop(&s);
    pop(&s);
    pop(&s);

    display_stack(s);

    printf("Let's take a peek on to the stack: I saw %d\n", peek(s));

    return 0;
}