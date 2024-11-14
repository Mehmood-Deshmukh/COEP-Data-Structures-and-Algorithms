#include "header.h"
#include <stdlib.h> 
#include <stdio.h>

int main(){
    Queue q;
    init(&q);

    for (int i = 0; i < 10; i++){
        enqueue(&q, rand() % 100 + 1);
    }

    display(q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(q);

    printf("Let's take a peek: %d\n", peek(q));

    enqueue(&q, 56);
    for (int i = 0; i < 7; i++){
        enqueue(&q, rand() % 100 + 1);
    }
    display(q);
    
    return 0;  
}