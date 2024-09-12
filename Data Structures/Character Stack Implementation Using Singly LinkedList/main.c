#include "logic.c"

int main(){
    cStack s;

    cinit(&s);

    cpush(&s, 'a');
    cpush(&s, 'b');
    cpush(&s, 'm');
    cpush(&s, 'd');
    cpush(&s, 's');
    cpush(&s, 'g');

    cdisplay(s);

    cpush(&s, 'f');
    cpush(&s, 'o');

    cdisplay(s);

    cpop(&s);
    cpop(&s);
    cpop(&s);

    cdisplay(s);

    printf("Let's take a peek on to the stack: I saw '%c'\n", cpeek(s));

    return 0;
}