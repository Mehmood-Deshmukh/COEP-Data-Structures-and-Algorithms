#include <stdio.h>
#include <stdlib.h>
#include "logic.c"

int main() {
    List list;
    init(&list);

    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    display(list);

    printf("\nInserting 0 at the beginning of the linked list:\n");
    insertAtBeginning(&list, 0);
    display(list);

    printf("\nRemoving element from the 2nd Index of the linked list:\n");
    int removedElement = removeAtIndex(&list, 2);
    printf("Removed Element: %d\n", removedElement);
    display(list);

    printf("The length of the list is %d\n", length(list));


    // extra functions test

    printf("\nRemoving element from the end of the linked list:\n");
    int removedEnd = removeEnd(&list);
    printf("Removed Element: %d\n", removedEnd);
    display(list);


    printf("\nRemoving element from the beginning of the linked list:\n");
    int removedBeginning = removeBeginning(&list);
    printf("Removed Element: %d\n", removedBeginning);
    display(list);

    append(&list, 2);
    append(&list, 3);
    append(&list, 4);
    append(&list, 5);

    display(list);

    printf("\nInserting at index 3:\n");
    addNodeAtPosition(&list, 3, 3);
    display(list);
    append(&list, 4);
    append(&list, 5);
    append(&list, 6);
    display(list);

    printf("Testing swap: \n");
    swapNodes(&list, list->next, list->next->next->next->next);
    display(list);

    List testEven;
    init(&testEven);

    append(&testEven, 1);
    append(&testEven, 2);
    append(&testEven, 6);
    append(&testEven, 9);
    append(&testEven, 10);
    append(&testEven, 24);
    append(&testEven, 22);
    append(&testEven, 11);
    append(&testEven, 65);   
    append(&testEven, 13);

    printf("Testing ReverseEven (Before): \n");
    display(testEven);

    reverseEven(&testEven);

    printf("Testing ReverseEven (After):\n");
    display(testEven);

    List palindrome1, palindrome2;
    init(&palindrome1);
    init(&palindrome2);

    append(&palindrome1, 1);
    append(&palindrome1, 2);
    append(&palindrome1, 3);
    append(&palindrome1, 2);
    append(&palindrome1, 1);

    display(palindrome1);
    printf("The List is Palindrome : %s\n", isPalindrome(palindrome1) ? "True" : "False");

    append(&palindrome2, 1);
    append(&palindrome2, 2);
    append(&palindrome2, 3);
    append(&palindrome2, 1);
    append(&palindrome2, 2);
    append(&palindrome2, 1);

    display(palindrome2);
    printf("The List is Palindrome : %s\n", isPalindrome(palindrome2) ? "True" : "False");

    append(&list, 5);
    printf("\nTesting remove Duplicates (Before): \n");
    display(list);

    removeDuplicates(&list);
    printf("Testing remove Duplicates (After):  \n");
    display(list);

    printf("Testing remove and insert (before):  \n");
    display(list);
    removeAndInsert(&list, list->next->next->next, 1);
    printf("Testing remove and insert (after):  \n");
    display(list);

    destroy(&list);
    destroy(&testEven);
    destroy(&palindrome1);
    destroy(&palindrome2);

    display(list);

    fill(&list, 10);
    printf("\nTesting Fill ");
    display(list);

    printf("Testing Remove Node:\n");
    printf("Removed Element: %d\n", removeNode(&list, list->next->next));
    display(list);
    
    return 0;
}