/* This is the test file provided in the question */


#include "header.h"

int main() {
    Queue q;
    Data d;

    qinit(&q);
    while(scanf("%s%u", d.name, &(d.age)) != -1) enq(&q, d);

    while(!qempty(&q)) {
        d = deq(&q);
        printf("Name: %s, Age: %u\n", d.name, d.age); /* Modified the output format */
    }
    return 0;
}