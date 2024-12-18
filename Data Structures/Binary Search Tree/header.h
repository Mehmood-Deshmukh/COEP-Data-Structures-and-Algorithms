#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Node *BST;

/* function prototypes */
void init(BST *root);
Node *iterative_search(BST root, int key);
Node *recursive_search(BST root, int key);

void iterative_insert(BST *root, int data);
void recursive_insert(BST *root, int data);

void iterative_inorder_traversal(BST root);
void recursive_inorder_traversal(BST root);

void iterative_preorder_traversal(BST root);
void recursive_preorder_traversal(BST root);

void iterative_postorder_traversal(BST root);
void recursive_postorder_traversal(BST root);

void level_order_traversal(BST root);

void iterative_delete_node(BST *root, int key);
void recursive_delete_node(BST *root, int key);

void iterative_destroy_tree(BST *root);
void recursive_destroy_tree(BST *root);

int iterative_get_height(BST root);
int recursive_get_height(BST root);

int iterative_count_leaf(BST root);
int recursive_count_leaf(BST root);

int iterative_count_non_leaf(BST root);
int recursive_count_non_leaf(BST root);

void convert_bst_to_min_heap(BST *root);
void print_leaf_nodes_in_ascending_order(BST root);
void print_longest_path_from_root_to_leaf(BST root);

#endif // HEADER_H