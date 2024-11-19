#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Queue q;
    init_queue(&q);

    for (int i = 0; i < 10; i++){
        enqueue(&q, rand() % 100 + 1);
    }

    display_queue(q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display_queue(q);

    printf("Let's take a peek: %d\n", peek_queue(q));

    enqueue(&q, 56);
    for (int i = 0; i < 7; i++){
        enqueue(&q, rand() % 100 + 1);
    }
    display_queue(q);
    
    return 0;  
}