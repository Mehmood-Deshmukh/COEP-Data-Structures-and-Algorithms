#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "./header.h"

void init(Stack *s, int size){
    if(size < 1){
        return;
    }
    s->size = size;
    s->top = 0;
    s->array = (int *) malloc(sizeof(int) * size);

    return;
}

int isEmpty(Stack s){
    if((s.top) == 0){
        return 1;
    }

    return 0;
}

void isFull(Stack *s){
    if((s->top) == (s->size)){
        s->array = realloc(s->array, (2 * s->size) * sizeof(int));
    }
    return;
}

void push(Stack *s, int data){
    isFull(s);
    s->array[s->top++] = data;
    return;
}

int peek(Stack s){
    if (isEmpty(s)){
        return INT_MIN;
    }

    return s.array[s.top - 1];    
}
int pop(Stack *s){
    if (isEmpty(*s)){
        return INT_MIN;
    }

    return s->array[--(s->top)];
}
void display(Stack s){
    if(s.top == 0){
        printf("The Stack is Empty!\n");
        return;
    }

    printf("Displaying the stack\n");

    for(int i = 0; i < s.top; i++){
        printf("%d ", s.array[i]);
    }
    printf("\n");
}