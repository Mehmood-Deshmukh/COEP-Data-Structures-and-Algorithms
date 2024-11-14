#include "header.h"
#include <stdio.h>

int main(){
    Queue q;
    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printf("Dequeued Element: %d\n", dequeue(&q));
    printf("Dequeued Element: %d\n", dequeue(&q));
    printf("Dequeued Element: %d\n", dequeue(&q));
    printf("Dequeued Element: %d\n", dequeue(&q));

    printf("Peeked Element: %d\n", peek(q));
    printf("Is Queue Empty: %s\n", is_empty(q) ? "True" : "False");
    dequeue(&q);
    printf("Is Queue Empty: %s\n", is_empty(q) ? "True" : "False");

    return 0;
}