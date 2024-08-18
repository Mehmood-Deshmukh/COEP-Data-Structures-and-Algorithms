#include <stdio.h>
#include "logic.c"

#define MAX_ARRAYS 10

void printMenu();
void handleChoice(int choice, Array* arrays[], int maxArrays);

int main() {
    int choice;
    Array *arrays[MAX_ARRAYS] = {NULL};
    while(1){
        printMenu();
        scanf("%d", &choice);
        handleChoice(choice, arrays, MAX_ARRAYS);
    }

    return 0;
}


// function to print a menu for user
void printMenu(){
    printf("\n\n***********Array ADT Menu:***********\n\n");
    printf("Select any of the instructions given below:\n");
    printf("1. Initialize a new Array.\n");
    printf("2. Append an element to an existing Array.\n");
    printf("3. Insert element at a given index.\n");
    printf("4. Remove element at a given index.\n");
    printf("5. Display an Array.\n");
    printf("6. Display the maximum element in an Array.\n");
    printf("7. Display the minimum element in an Array.\n");
    printf("8. Reverse an Array.\n");
    printf("9. Merge two Arrays.\n");
    printf("10. Fill an Array with random elements\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
}

// function to handle user choices
void handleChoice(int choice, Array *arrays[], int maxArrays){
    int arrayNumber;
    if (choice != 1 && choice != 11) {
        printf("\nEnter array number (0-%d): ", maxArrays - 1);
        scanf("%d", &arrayNumber);

        if (arrayNumber < 0 || arrayNumber >= maxArrays) {
            printf("Invalid array number!\n");
            return;
        }

        if (arrays[arrayNumber] == NULL) {
            printf("Array %d is not initialized. Please initialize it first.\n", arrayNumber);
            return;
        }
    }

    switch (choice) {
        case 1: {
            int size;
            printf("\nEnter array number (0-%d): ", maxArrays - 1);
            scanf("%d", &arrayNumber);

            if (arrayNumber < 0 || arrayNumber >= maxArrays) {
                printf("Invalid array number!\n");
                return;
            }

            printf("\nEnter the size of the Array: ");
            scanf("%d", &size);
            if (arrays[arrayNumber] == NULL) {
                arrays[arrayNumber] = (Array *)malloc(sizeof(Array));
            }
            init(arrays[arrayNumber], size);

            printf("\nArray %d initialized with size %d.\n", arrayNumber, size);
            break;
        }
        case 2: {
            int element;
            printf("\nEnter the element to append to the Array: ");
            scanf("%d", &element);
            append(arrays[arrayNumber], element);
            printf("\nElement appended to array %d: %d.\n", arrayNumber, element);
            break;
        }
        case 3: {
            int element, index;
            printf("\nEnter the element to add to the Array: ");
            scanf("%d", &element);
            printf("\nEnter the index at which the element is to be added: ");
            scanf("%d", &index);
            insertAtIndex(arrays[arrayNumber], element, index);
            printf("\nElement %d inserted at index %d in array %d.\n", element, index, arrayNumber);
            break;
        }
        case 4: {
            int index;
            printf("\nEnter the index at which the element is to be removed: ");
            scanf("%d", &index);
            int removedElement = removeAtIndex(arrays[arrayNumber], index);
            printf("\nRemoved Element from array %d: %d\n", arrayNumber, removedElement);
            break;
        }
        case 5: {
            display(*arrays[arrayNumber]);
            break;
        }
        case 6: {
            int maxElement = max(*arrays[arrayNumber]);
            printf("\nMaximum element in the Array %d: %d\n", arrayNumber, maxElement);
            break;
        }
        case 7: {
            int minElement = min(*arrays[arrayNumber]);
            printf("\nMinimum element in the Array %d: %d\n", arrayNumber, minElement);
            break;
        }
        case 8: {
            reverse(arrays[arrayNumber]);
            printf("\nArray %d reversed.\n", arrayNumber);
            break;
        }
        case 9: {
            int arrayNumber2;
            printf("\nEnter the second array number (0-%d): ", maxArrays - 1);
            scanf("%d", &arrayNumber2);

            if (arrayNumber2 < 0 || arrayNumber2 >= maxArrays || arrays[arrayNumber2] == NULL) {
                printf("Invalid second array number or array not initialized!\n");
                return;
            }

            Array mergedArray = merge(*arrays[arrayNumber], *arrays[arrayNumber2]);
            printf("\nArrays %d and %d merged.\n", arrayNumber, arrayNumber2);
            display(mergedArray);
            break;
        }
        case 10: {
            fill(arrays[arrayNumber]);
            break;
        }
        case 11:
            printf("\nExiting....\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
}