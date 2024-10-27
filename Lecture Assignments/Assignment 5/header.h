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
#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
This is the structure of a node in the binary search tree.
it contains:
    - month: the month name
    - left: pointer to the left child
    - right: pointer to the right child
    - parent: pointer to the parent of the node
*/

typedef struct Node {
    char *month;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

/*
This is the binary search tree structure.
it contains:
    - root: pointer to the root of the tree
*/

typedef Node * BST;

/* Function prototypes */

void init_bst(BST *root);

void recursive_insert_node(BST *root, char *month);
void iterative_insert_node(BST *root, char *month);

void recursive_remove_node(BST *root, char *month);
void iterative_remove_node(BST *root, char *month);


void recursive_inorder_traversal(BST root);
void iterative_inorder_traversal(BST root);

void recursive_preorder_traversal(BST root);
void iterative_preorder_traversal(BST root);

void recursive_postorder_traversal(BST root);
void iterative_postorder_traversal(BST root);

void level_order_traversal(BST root);

void recursive_destroy_tree(BST *root);
void iterative_destroy_tree(BST *root);

int iterative_count_leaf(BST root);
int recursive_count_leaf(BST root);

int iterative_count_non_leaf(BST root);
int recursive_count_non_leaf(BST root);

int iterative_get_height(BST root);
int recursive_get_height(BST root);

#endif