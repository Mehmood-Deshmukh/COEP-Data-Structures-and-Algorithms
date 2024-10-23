#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "./Queue Implementation using Singly LinkedList/header.h"


#define SIZE 10

typedef struct BST{
    int *array;
    int size;
} BST;


void init(BST *b);

void insert(BST *b, int data);
void recursiveInsert(BST *b, int data);

void inorderTraversal(BST b);
void preorderTraversal(BST b);
void postorderTraversal(BST b);

int countLeafNodes(BST b);
int countNonLeafNodes(BST b);


int recursiveHeight(BST b);
int iterativeHeight(BST b);