#include "header.h"

void initBST(BST *root) {
    (*root)->month = '\0';
    (*root)->left = (*root)->right = (*root)->parent = NULL;
}

void insertNode(BST *root, char *month) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->month = (char *)malloc(strlen(month) + 1);
    strcpy(temp->month, month);
    temp->left = temp->right = temp->parent = NULL;


    if (*root == NULL) {
        *root = temp;
        return;
    }
    
    Node *current = *root;
    while (1) {
        if (strcmp(month, current->month) < 0) {
            if (current->left == NULL) {
                current->left = temp;
                temp->parent = current;
                return;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = temp;
                temp->parent = current;
                return;
            }
            current = current->right;
        }
    }
}

char *removeNode(BST *root, char *month) {
    Node *current = *root;
    while (current != NULL && strcmp(month, current->month) != 0) {
        if (strcmp(month, current->month) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == NULL) {
        return NULL;
    }


    char *removedData = current->month;
    if (current->left == NULL && current->right == NULL) {
        if (current->parent == NULL) {
            *root = NULL;
        } else if (current->parent->left == current) {
            current->parent->left = NULL;
        } else {
            current->parent->right = NULL;
        }
        free(current);

    } else if (current->left == NULL) {
        if (current->parent == NULL) {
            *root = current->right;
        } else if (current->parent->left == current) {
            current->parent->left = current->right;
        } else {
            current->parent->right = current->right;
        }
        free(current);
    } else if (current->right == NULL) {
        if (current->parent == NULL) {
            *root = current->left;
        } else if (current->parent->left == current) {
            current->parent->left = current->left;
        } else {
            current->parent->right = current->left;
        }
        free(current);
        
    } else {
        Node *temp = current->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        current->month = temp->month;
        if (temp->parent->left == temp) {
            temp->parent->left = temp->right;
        } else {
            temp->parent->right = temp->right;
        }
        free(temp);
    }


    return removedData;
}

void traverse(BST root) {
    if (root == NULL) {
        return;
    }
    traverse(root->left);
    printf("%s\n", root->month);
    traverse(root->right);
}

void destroyTree(BST *root) {
    if (*root == NULL) {
        return;
    }
    destroyTree(&(*root)->left);
    destroyTree(&(*root)->right);
    free(*root);
    *root = NULL;
}

