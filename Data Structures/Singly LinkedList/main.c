#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    List list;
    init(&list);

    printf("Appending elements to the linked list:\n");
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    display(list);

    printf("\nInserting 0 at the beginning of the linked list:\n");
    insert_at_beginning(&list, 0);
    display(list);

    printf("\nRemoving element from the end of the linked list:\n");
    int removed_end = remove_end(&list);
    printf("Removed Element from End: %d\n", removed_end);
    display(list);

    printf("\nRemoving element from the beginning of the linked list:\n");
    int removed_beginning = remove_beginning(&list);
    printf("Removed Element from Beginning: %d\n", removed_beginning);
    display(list);

    printf("\nInserting at index 2:\n");
    add_node_at_position(&list, 3, 2);
    display(list);
    append(&list, 4);
    append(&list, 5);
    append(&list, 6);
    display(list);
    add_node_at_position(&list, 7, 3);
    display(list);

    printf("After swapping: \n");
    swap_nodes(&list, list->next, list->next->next->next->next);
    display(list);

    List test_list;
    init(&test_list);

    append(&test_list, 1);
    append(&test_list, 2);
    append(&test_list, 8);
    append(&test_list, 9);
    append(&test_list, 12);
    append(&test_list, 16);
    append(&test_list, 18);
    append(&test_list, 11);
    append(&test_list, 14);   
    append(&test_list, 13);

    printf("Before Reverse Even: \n");
    display(test_list);

    reverse_even(&test_list);

    printf("After ReverseEven: \n");
    display(test_list);

    List palindrome_test_1, palindrome_test_2;
    init(&palindrome_test_1);
    init(&palindrome_test_2);

    append(&palindrome_test_1, 1);
    append(&palindrome_test_1, 2);
    append(&palindrome_test_1, 3);
    append(&palindrome_test_1, 2);
    append(&palindrome_test_1, 1);

    display(palindrome_test_1);
    printf("Palindrom Test is palindrome: %s\n", is_palindrome(palindrome_test_1) ? "True" : "False");

    append(&palindrome_test_2, 1);
    append(&palindrome_test_2, 2);
    append(&palindrome_test_2, 3);
    append(&palindrome_test_2, 1);
    append(&palindrome_test_2, 2);
    append(&palindrome_test_2, 1);

    display(palindrome_test_2);
    printf("Palindrom Test is palindrome: %s\n", is_palindrome(palindrome_test_2) ? "True" : "False");

    append(&palindrome_test_2, 5);
    printf("\nBefore removing Duplicates: \n");
    display(palindrome_test_2);

    remove_duplicates(&palindrome_test_2);
    printf("After removing duplicates: \n");
    display(palindrome_test_2);

    display(palindrome_test_1);
    remove_and_insert(&palindrome_test_1, palindrome_test_1->next->next->next, 0);
    display(palindrome_test_1);

    destroy(&list);
    destroy(&test_list);
    destroy(&palindrome_test_1);
    destroy(&palindrome_test_2);

    display(list);

    fill(&list, 10);
    printf("\nAfter Fill ");
    display(list);

    printf("Removed Element: %d\n", remove_node(&list, list->next->next));
    printf("After Remove Node:\n");
    display(list);
    
    return 0;
}