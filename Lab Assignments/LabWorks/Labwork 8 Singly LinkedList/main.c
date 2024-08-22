#include <stdio.h>
#include <stdlib.h>
#include "logic.c"

int main() {
    List list;
    init(&list);

    printf("Appending elements to the linked list:\n");
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    display(list);

    printf("\nInserting 0 at the beginning of the linked list:\n");
    insertAtBeginning(&list, 1);
    display(list);

    printf("\nRemoving element from the end of the linked list:\n");
    int removedEnd = removeEnd(&list);
    printf("Removed Element from End: %d\n", removedEnd);
    display(list);

    printf("\nRemoving element from the beginning of the linked list:\n");
    int removedBeginning = removeBeginning(&list);
    printf("Removed Element from Beginning: %d\n", removedBeginning);
    display(list);

    printf("\nInserting at index 2:\n");
    addNodeAtPosition(&list, 3, 2);
    display(list);
    append(&list, 4);
    append(&list, 5);
    append(&list, 6);
    display(list);
    addNodeAtPosition(&list, 7, 3);
    display(list);

    printf("After swapping: \n");
    swapNodes(&list, list->next, list->next->next->next->next);
    display(list);

    List testList;
    init(&testList);

    append(&testList, 1);
    append(&testList, 2);
    append(&testList, 8);
    append(&testList, 9);
    append(&testList, 12);
    append(&testList, 16);
    append(&testList, 18);
    append(&testList, 11);
    append(&testList, 14);   
    append(&testList, 13);

    printf("Before ReverseEven: \n");
    display(testList);

    reverseEven(&testList);

    printf("After ReverseEven: \n");
    display(testList);

    List palindromeTest1, palindromeTest2;
    init(&palindromeTest1);
    init(&palindromeTest2);

    append(&palindromeTest1, 1);
    append(&palindromeTest1, 2);
    append(&palindromeTest1, 3);
    append(&palindromeTest1, 2);
    append(&palindromeTest1, 1);

    display(palindromeTest1);
    printf("Palindrom Test is palindrome: %s\n", isPalindrome(palindromeTest1) ? "True" : "False");

    append(&palindromeTest2, 1);
    append(&palindromeTest2, 2);
    append(&palindromeTest2, 3);
    append(&palindromeTest2, 1);
    append(&palindromeTest2, 2);
    append(&palindromeTest2, 1);

    display(palindromeTest2);
    printf("Palindrom Test is palindrome: %s\n", isPalindrome(palindromeTest2) ? "True" : "False");

    append(&palindromeTest2, 5);
    printf("\nBefore removing Duplicates: \n");
    display(palindromeTest2);

    removeDuplicates(&palindromeTest2);
    printf("After removing duplicates: \n");
    display(palindromeTest2);

    display(palindromeTest1);
    removeAndInsert(&palindromeTest1, palindromeTest1->next->next->next, 0);
    display(palindromeTest1);

    destroy(&list);
    destroy(&testList);
    destroy(&palindromeTest1);
    destroy(&palindromeTest2);

    display(list);

    fill(&list, 10);
    printf("\nAfter Fill ");
    display(list);

    printf("Removed Element: %d\n", removeNode(&list, list->next->next));
    printf("After Remove Node:\n");
    display(list);
    
    return 0;
}