#include "header.h"

void init(Stacks *s){
    s->array = (int *)malloc(SIZE * sizeof(int));
    if(!s->array) return;

    s->top1 = -1;
    s->top2 = SIZE;
}

int isEmpty1(Stacks s){
    return s.top1 == -1;
}
int isEmpty2(Stacks s){
    return s.top2 == SIZE;
}
int isFull(Stacks s){
    return s.top1 + 1 == s.top2;
}

void push1(Stacks *s, int x){
    if(isFull(*s)) return;

    s->array[++s->top1] = x;
}

void push2(Stacks *s, int x){
    if(isFull(*s)) return;

    s->array[--s->top2] = x;
}

int pop1(Stacks *s){
    if(isEmpty1(*s)) return INT_MIN;

    return s->array[s->top1--];
}
int pop2(Stacks *s){
    if(isEmpty2(*s)) return INT_MIN;

    return s->array[s->top2++];
}

void display1(Stacks s){
    if(isEmpty1(s)) return;

    int i;
    for(i = 0; i <= s.top1; i++){
        printf("%d | ", s.array[i]);
    }
    printf("\b\b\b   \n");

    return;
}
void display2(Stacks s){
    if(isEmpty2(s)) return;

    int i;
    for(i = SIZE - 1; i >= s.top2; i--){
        printf("%d | ", s.array[i]);
    }
    printf("\b\b\b   \n");

    return;
}

