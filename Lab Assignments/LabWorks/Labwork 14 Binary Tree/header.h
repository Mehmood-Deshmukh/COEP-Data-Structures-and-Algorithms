#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct Node *BT;


/* function protototypes */

void init(BT *bt);

void insert(BT *bt, int data);

void inorder(BT bt);
void preorder(BT bt);
void postorder(BT bt);

int countLeaf(BT bt);
int countNonLeaf(BT bt);