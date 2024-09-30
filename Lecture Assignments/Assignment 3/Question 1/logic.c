#include "header.h" /* including the header file */

/*
To initialize the Stacks all we need to do is:
    1. malloc memory for the array
    2. set top1 as -1
    3. set top2 as SIZE


    if malloc fails return 
*/
void init(Stacks *s){
    s->array = (int *)malloc(SIZE * sizeof(int));
    if(!s->array) return;

    s->top1 = -1;
    s->top2 = SIZE;
}

/*
if top1 is still at -1, it means the stack1 is empty
*/
int isEmpty1(Stacks s){
    return s.top1 == -1;
}

/*
if the top2 is still at SIZE, it means that stack2 is empty
*/
int isEmpty2(Stacks s){
    return s.top2 == SIZE;
}

/*
The isFull condition will be when all the elements of the malloced array are full, this happens when top1 + 1 == top2
*/
int isFull(Stacks s){
    return s.top1 + 1 == s.top2;
}

/*
To push element to stack1 we increment top and place the element at top1 index

if the stacks are full we simply return
*/

void push1(Stacks *s, int x){
    if(isFull(*s)) return;

    s->array[++s->top1] = x;
}

/*
To push element to stack2 we decrement top and place the element at at top2 index

if the stacks are full we simply return
*/

void push2(Stacks *s, int x){
    if(isFull(*s)) return;

    s->array[--s->top2] = x;
}
/*
to pop element from stack1 we simply return the element at top1 index and then decrement top1

if stack1 is empty we return INT_MIN
*/
int pop1(Stacks *s){
    if(isEmpty1(*s)) return INT_MIN;

    return s->array[s->top1--];
}

/*
to pop element from stack2 we simply return the element at top2 index and then increment top2

if stack2 is empty we return INT_MIN
*/
int pop2(Stacks *s){
    if(isEmpty2(*s)) return INT_MIN;

    return s->array[s->top2++];
}

/*
to display stack1 we simply traverse from 0th index to top1 and print each element

we also handle the case when stack1 is empty
*/
void display1(Stacks s){
    if(isEmpty1(s)) return;

    int i;
    for(i = 0; i <= s.top1; i++){
        printf("%d | ", s.array[i]);
    }
    printf("\b\b\b   \n");

    return;
}

/*
to display stack1 we simply traverse from last index to top2 in reverse order and print each element

we also handle the case when stack2 is empty
*/
void display2(Stacks s){
    if(isEmpty2(s)) return;

    int i;
    for(i = SIZE - 1; i >= s.top2; i--){
        printf("%d | ", s.array[i]);
    }
    printf("\b\b\b   \n");

    return;
}

