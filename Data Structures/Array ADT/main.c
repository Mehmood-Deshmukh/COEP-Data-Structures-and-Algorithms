#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    Array a1, a2, a3;
    init(&a1, 12);
    init(&a2, 10);

    printf("Using fill function to add elements to a1 :\n");
    fill(&a1);

    printf("\nDisplaying a1:\n");
    display(a1);

    printf("Using append function to add elements to a2:\n");
    append(&a2, 15);
    append(&a2, 44);
    append(&a2, 6);
    append(&a2, 52);

    printf("\nDisplaying a2:\n");
    display(a2);

    printf("\nInserting 20 at position 2 in a2:\n");
    insert_at_index(&a2, 20, 2);
    display(a2);


    printf("\nRemoving element at index 1 from a2:\n");
    int removedElement = remove_at_index(&a2, 1);
    printf("Removed Element: %d\n", removedElement);
    display(a2);

    printf("\nReversing a1:\n");
    reverse(&a1);
    display(a1);

    printf("\nFinding minimum element in a2:\n");
    int minimum = min(a2);
    printf("Minimum Element: %d\n", minimum);

    printf("\nFinding maximum element in a2:\n");
    int maximum = max(a2);
    printf("Maximum Element: %d\n", maximum);

    printf("\nSorting a1:\n");
    sort(&a1);
    display(a1);

    printf("\nJoining a1 and a2 into a3:\n");
    a3 = merge(a1, a2);
    display(a3);

    free(a1.A);
    free(a2.A);
    free(a3.A);

    return 0;
}