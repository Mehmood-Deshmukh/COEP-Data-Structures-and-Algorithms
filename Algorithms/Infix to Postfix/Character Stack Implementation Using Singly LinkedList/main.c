#include "logic.c"

int main(){
    Stack s;

    init(&s);

    push(&s, 'a');
    push(&s, 'b');
    push(&s, 'm');
    push(&s, 'd');
    push(&s, 's');
    push(&s, 'g');

    display(s);

    push(&s, 'f');
    push(&s, 'o');

    display(s);

    pop(&s);
    pop(&s);
    pop(&s);

    display(s);

    printf("Let's take a peek on to the stack: I saw '%c'\n", cpeek(s));

    return 0;
}