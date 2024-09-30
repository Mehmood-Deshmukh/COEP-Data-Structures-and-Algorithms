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

/* Including the necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 20 /* we will define the size here which can be changed later on but its necessary as we are using an array to implement the 2 stacks */

/* This is our structure for 2 Stacks in an array
Basically my approach is simple:
    1. For the first Stack we push from the start of the array incrementing the top1
    2. For the second stack we push from the end of the array in reverse order decrementing the top2
    3. The full condition will occur when top1 + 1 == top2

This is more space efficient compared to my other idea where i had decided to use half the stack for stack1 and other half for stack 2

*/
typedef struct Stacks{
    int *array; /* pointer to the array of elements */
    int top1; /* top of stack1 */
    int top2; /* top of stack2 */
} Stacks;


/* These are all the functions we can define for our Stacks */
void init(Stacks *s); /* Intializes the Stacks */
int isEmpty1(Stacks s); /* Checks if the first Stack is empty */
int isEmpty2(Stacks s); /* Checks if the second Stack is empty */
int isFull(Stacks s); /* Check whether the stacks are full */
void push1(Stacks *s, int x); /* push element to first stack */
void push2(Stacks *s, int x); /* push element to the second stack */
int pop1(Stacks *s); /* pop element from first stack */
int pop2(Stacks *s); /* pop element from second stack */
void display1(Stacks s); /* display the first stack */
void display2(Stacks s); /* display the second stack */
