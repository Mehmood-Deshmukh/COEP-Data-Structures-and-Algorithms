#include "header.h"

int main() {
    BST root = NULL;
    int choice;
    char month[20];
    while (1) {
        printf("1. Insert a month\n");
        printf("2. Remove a month\n");
        printf("3. Traverse the tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the month to insert: ");
                scanf("%s", month);
                insertNode(&root, month);
                break;
            case 2:
                printf("Enter the month to remove: ");
                scanf("%s", month);
                if (removeNode(&root, month) == NULL) {
                    printf("Month not found\n");
                } else {
                    printf("Month removed\n");
                }
                break;
            case 3:
                traverse(root);
                break;
            case 4:
                destroyTree(&root);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

