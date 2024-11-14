#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "./header.h"

void init(Stack *s){
    s->size = SIZE;
    s->top = 0;
    s->array = (int *) malloc(sizeof(int) * SIZE);

    return;
}

int is_empty(Stack s){
    if(s.top == 0) return 1;

    return 0;
}

void is_full(Stack *s){
    if(s->top == s->size){
        s->size *= 2;
        s->array = realloc(s->array, s->size * sizeof(int));
    }
    return;
}

void push(Stack *s, int data){
    is_full(s);
    s->array[s->top++] = data;
    return;
}

int peek(Stack s){
    if (is_empty(s)) return INT_MIN;

    return s.array[s.top - 1];    
}
int pop(Stack *s){
    if (is_empty(*s)) return INT_MIN;

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

void sort(Stack *s){
    Stack temp;
    init(&temp);

    while(!is_empty(*s)){
        int data = pop(s);

        while(!is_empty(temp) && peek(temp) > data){
            push(s, pop(&temp));
        }

        push(&temp, data);
    }

    while(!is_empty(temp)){
        push(s, pop(&temp));
    }
}