/*
Implement ADT Binary Search Tree(BST) using a linked list of nodes of structure having Month, left pointer, right pointer, and parent pointers pointing to left sub-trees, right sub-tree, and parent of the node.

Perform a series of insertions on keys - December, January, April, March, July, August, October, February, November, May, June.  Write following functions: 

initBST()         // to initialize the tree. 

insertNode()    // non-recursive function to add a new node to the BST. 

removeNode() // to remove a node from a tree. 

traverse()         // write any of the non-recursive traversal methods.

destroyTree()  // to delete all nodes of a tree.

Write a menu driven program to invoke all above functions.  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *month;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

typedef Node * BST;

/* Function prototypes */

void initBST(BST *root);

void insertNode(BST *root, char *month);

char *removeNode(BST *root, char *month);

void traverse(BST root);

void destroyTree(BST *root);

