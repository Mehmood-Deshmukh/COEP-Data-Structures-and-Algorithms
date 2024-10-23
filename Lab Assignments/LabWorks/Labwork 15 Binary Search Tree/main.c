#include "header.h"

int main(){
    BST b;
    init(&b);
    insert(&b, 4);
    insert(&b, 3);
    insert(&b, 2);
    insert(&b, 1);
    insert(&b, 6);
    insert(&b, 8);
    inorderTraversal(b);
    preorderTraversal(b);
    postorderTraversal(b);

    printf("Recursive Height: %d\n", recursiveHeight(b));
    printf("Iterative Height: %d\n", iterativeHeight(b));

    printf("Leaf Nodes: %d\n", countLeafNodes(b));
    printf("Non Leaf Nodes: %d\n", countNonLeafNodes(b));

    printf("//////////////////////////\n");

    BST c;
    init(&c);

    recursiveInsert(&c, 4);
    recursiveInsert(&c, 3);
    recursiveInsert(&c, 2);
    recursiveInsert(&c, 1);
    recursiveInsert(&c, 6);
    recursiveInsert(&c, 8);

    inorderTraversal(c);
    preorderTraversal(c);
    postorderTraversal(c);

    printf("Recursive Height: %d\n", recursiveHeight(c));
    printf("Iterative Height: %d\n", iterativeHeight(c));

    printf("Leaf Nodes: %d\n", countLeafNodes(c));
    printf("Non Leaf Nodes: %d\n", countNonLeafNodes(c));

    return 0;
}