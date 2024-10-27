#include "header.h"

int main(){
    int data[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65, 75, 85};

    BST root1;
    init(&root1);
    for(int i = 0; i < 12; i++){
        recursive_insert(&root1, data[i]);
    }

    printf("Recursive Inorder Traversal: ");
    recursive_inorder_traversal(root1);
    printf("\n");

    printf("Recursive Preorder Traversal: ");
    recursive_preorder_traversal(root1);
    printf("\n");

    printf("Recursive Postorder Traversal: ");
    recursive_postorder_traversal(root1);
    printf("\n");

    printf("Recursive Height: %d\n", recursive_get_height(root1));
    printf("Recursive Leaf Count: %d\n", recursive_count_leaf(root1));
    printf("Recursive Non-Leaf Count: %d\n", recursive_count_non_leaf(root1));

    Node *temp = recursive_search(root1, 30);
    if(temp) printf("Recursive Search: %d\n", temp->data);
    else printf("Recursive Search: Not Found\n");

    temp = recursive_search(root1, 100);
    if(temp) printf("Recursive Search: %d\n", temp->data);
    else printf("Recursive Search: Not Found\n");

    printf("Recursive Delete Node: ");
    recursive_delete_node(&root1, 30);
    recursive_delete_node(&root1, 100);

    printf("Recursive Inorder Traversal: ");
    recursive_inorder_traversal(root1);

    recursive_destroy_tree(&root1);

    printf("\n\n");

    BST root2;
    init(&root2);
    for(int i = 0; i < 12; i++){
        iterative_insert(&root2, data[i]);
    }

    printf("Iterative Inorder Traversal: ");
    iterative_inorder_traversal(root2);
    printf("\n");

    printf("Iterative Preorder Traversal: ");
    iterative_preorder_traversal(root2);
    printf("\n");

    printf("Iterative Postorder Traversal: ");
    iterative_postorder_traversal(root2);
    printf("\n");

    printf("Level Order Traversal: ");
    level_order_traversal(root2);


    printf("Iterative Height: %d\n", iterative_get_height(root2));
    printf("Iterative Leaf Count: %d\n", iterative_count_leaf(root2));
    printf("Iterative Non-Leaf Count: %d\n", iterative_count_non_leaf(root2));

    temp = iterative_search(root2, 30);
    if(temp) printf("Iterative Search: %d\n", temp->data);
    else printf("Iterative Search: Not Found\n");

    temp = iterative_search(root2, 100);
    if(temp) printf("Iterative Search: %d\n", temp->data);
    else printf("Iterative Search: Not Found\n");

    printf("Iterative Delete Node: ");
    iterative_delete_node(&root2, 30);
    iterative_delete_node(&root2, 100);

    printf("Iterative Inorder Traversal: ");
    iterative_inorder_traversal(root2);

    iterative_destroy_tree(&root2);

    return 0;
}