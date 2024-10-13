#include "header.h"

void printMenu();
void handleChoice(Queue *q);


int main(){
    Queue q;
    init(&q);
    while(1){
        printMenu();
        handleChoice(&q);
    }
    return 0;
}

void printMenu(){
    printf("\n\n***********Array ADT Menu:***********\n\n");
    printf("Select any of the instructions given below:\n");
    printf("Enter your choice:\n");
    printf("1. Enqueue an element in the queue.\n");
    printf("2. Dequeue an element from the queue.\n");
    printf("3. Peek the front element of the queue.\n");
    printf("4. Check if the queue is empty.\n");
    printf("5. Display the queue.\n");
    printf("6. Clear the queue.\n");
    printf("7. Exit\n");
}

void handleChoice(Queue *q){
    int choice, data;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the data to enqueue: ");
            scanf("%d", &data);
            enqueue(q, data);
            break;
        case 2:
            data = dequeue(q);
            if(data == INT_MIN){
                printf("Queue is empty!\n");
            }else{
                printf("Dequeued data: %d\n", data);
            }
            break;
        case 3:
            data = peek(q);
            if(data == INT_MIN){
                printf("Queue is empty!\n");
            }else{
                printf("Peeked data: %d\n", data);
            }
            break;
        case 4:
            if(isEmpty(q)){
                printf("Queue is empty!\n");
            }else{
                printf("Queue is not empty!\n");
            }
            break;
        case 5:
            display(q);
            break;
        case 6:
            clear(q);
            printf("Queue cleared!\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
    }
}