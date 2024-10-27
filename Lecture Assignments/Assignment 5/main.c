#include "header.h"

void print_menu();
void handle_choice(BST *root, int choice);           
void lower_string(char s[]);                                                                                                         

int main() {
    BST root;
    init_bst(&root);
    int choice;
    while(1){
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handle_choice(&root, choice);
    }
    return 0;
}

void lower_string(char s[]) {
    for(int i = 0; s[i]; i++){
        s[i] = tolower(s[i]);
    }
}

void print_menu() {
    printf("\n1. Insert a node\n");
    printf("2. Remove a node\n");
    printf("3. Inorder traversal\n");
    printf("4. Preorder traversal\n");
    printf("5. Postorder traversal\n");
    printf("6. Level order traversal\n");
    printf("7. Destroy tree\n");
    printf("8. Count leaf nodes\n");
    printf("9. Count non-leaf nodes\n");
    printf("10. Get height of tree\n");
    printf("11. Exit\n");
}

void handle_choice(BST *root, int choice) {
    char month[20];
    switch(choice){
        case 1:
            printf("Enter month: ");
            scanf("%s", month);
            lower_string(month);
            iterative_insert_node(root, month);
            break;
        case 2:
            printf("Enter month: ");
            scanf("%s", month);
            lower_string(month);
            iterative_remove_node(root, month);
            break;
        case 3:
            iterative_inorder_traversal(*root);
            break;
        case 4:
            iterative_preorder_traversal(*root);
            break;
        case 5:
            iterative_postorder_traversal(*root);
            break;
        case 6:
            level_order_traversal(*root);
            break;
        case 7:
            iterative_destroy_tree(root);
            break;
        case 8:
            printf("Leaf nodes: %d\n", iterative_count_leaf(*root));
            break;
        case 9:
            printf("Non-leaf nodes: %d\n", iterative_count_non_leaf(*root));
            break;
        case 10:
            printf("Height of tree: %d\n", iterative_get_height(*root));
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
}
