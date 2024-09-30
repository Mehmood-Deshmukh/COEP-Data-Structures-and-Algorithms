#include "logic.c"

int main(){
    List l;
    init(&l);
    append(&l, 0);
    append(&l, 1);
    append(&l, 0);
    displayLR(l);
    displayRL(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));
    append(&l, 1);
    append(&l, 2);
    append(&l, 3);
    displayLR(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));
    insertAtStart(&l, 12);
    insertAtStart(&l, 23);
    insertAtIndex(&l, 39, 4);
    displayLR(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));
    printf("Removed Element from index 2: %d\n", removeAtIndex(&l, 2));
    printf("Removed Element from start: %d\n", removeStart(&l)); 
    printf("Removed Element from start: %d\n", removeStart(&l)); 
    displayLR(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));
    printf("Removed Element from end: %d\n", removeAtEnd(&l)); 
    displayLR(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));
    reverseList(&l);
    displayLR(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));
    sortList(&l);
    displayLR(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));
    removeDuplicates(&l);
    displayLR(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));
    destroy(&l);
    displayLR(l);
    printf("The Length of Doubly LinkedList is: %d\n", length(l));

    List palindrome1, palindrome2;
    init(&palindrome1);
    init(&palindrome2);

    append(&palindrome1, 1);
    append(&palindrome1, 2);
    append(&palindrome1, 3);
    append(&palindrome1, 2);
    append(&palindrome1, 1);

    displayLR(palindrome1);
    printf("The List is Palindrome : %s\n", isPalindrome(palindrome1) ? "True" : "False");

    append(&palindrome2, 1);
    append(&palindrome2, 2);
    append(&palindrome2, 3);
    append(&palindrome2, 1);
    append(&palindrome2, 2);
    append(&palindrome2, 1);

    displayLR(palindrome2);
    printf("The List is Palindrome : %s\n", isPalindrome(palindrome2) ? "True" : "False");
}