#include "logic.c"

int main(){
    Stacks s;
    init(&s);
    push1(&s, 1);
    push1(&s, 2);
    push1(&s, 3);
    push2(&s, 4);
    push2(&s, 5);
    push2(&s, 6);
    display1(s);
    display2(s);
    pop1(&s);
    pop2(&s);
    display1(s);
    display2(s);
    return 0;
}