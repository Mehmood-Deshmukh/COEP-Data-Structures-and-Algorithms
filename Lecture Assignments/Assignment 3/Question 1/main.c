#include "logic.c"

int main(){
    Stacks s;
    init(&s); /* initialize the stacks */

    /* Push elements to stack1 */
    push1(&s, 1);
    push1(&s, 2);
    push1(&s, 3);

    /* Push elements to stack2 */
    push2(&s, 4);
    push2(&s, 5);
    push2(&s, 6);

    /* display the stacks */
    display1(s);
    display2(s);

    /* Pop elements from the stacks */
    pop1(&s);
    pop2(&s);

    /* Display the stacks again */
    display1(s);
    display2(s);
    return 0;
}