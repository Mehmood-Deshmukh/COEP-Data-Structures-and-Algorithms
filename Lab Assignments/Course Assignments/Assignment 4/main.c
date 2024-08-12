#include "./logic.c"

int main(){
    Queue q;
    init(&q);

    for (int i = 0; i < 10; i++){
        enQueue(&q, rand() % 10 + '0');
    }

    display(q);

    deQueue(&q);
    deQueue(&q);
    deQueue(&q);
    deQueue(&q);

    display(q);

    printf("Let's take a peek: %c\n", peek(q));

    enQueue(&q, 'a');
    for (int i = 0; i < 7; i++){
        enQueue(&q, rand() % 10 + '0');
    }
    display(q);
    
    return 0;  
}