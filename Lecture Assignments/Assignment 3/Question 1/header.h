/*
1. Two stacks in one array:
Create a data structure twoStacks that represents two stacks. Implementation of
twoStacks should use only one array, i.e., both stacks should use the same array for
storing elements. Following functions must be supported by twoStacks.
push1(int x) –> pushes x to first stack
push2(int x) –> pushes x to second stack
pop1() –> pops an element from first stack and return the popped element
pop2() –> pops an element from second stack and return the popped element
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 20

typedef struct Stacks{
    int *array;
    int top1;
    int top2;
} Stacks;

void init(Stacks *s);
int isEmpty1(Stacks s);
int isEmpty2(Stacks s);
int isFull(Stacks s);
void push1(Stacks *s, int x);
void push2(Stacks *s, int x);
int pop1(Stacks *s);
int pop2(Stacks *s);
void display1(Stacks s);
void display2(Stacks s);
