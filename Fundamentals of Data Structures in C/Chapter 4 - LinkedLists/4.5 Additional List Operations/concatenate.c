#include <stdio.h>
#include "..\..\..\Data Structures\Singly LinkedList\logic.c"

List concatenate(List head1, List head2);
int main() {
    List list1, list2, List3;
    init(&list1);
    init(&list2);
    append(&list1, 1);
    append(&list1, 2);
    append(&list1, 3);

    printf("First ");
    display(list1);

    append(&list2, 4);
    append(&list2, 5);
    append(&list2, 6);

    printf("Second ");
    display(list2);

    List3 = concatenate(list1, list2);
    
    printf("After concatenatnig: \n");
    display(List3);

    return 0;
}

List concatenate(List head1, List head2){
    if(!head1) return head2;
    if(!head2) return head1;

    Node *temp;
    for (temp = head1;temp->next; temp = temp->next);

    temp->next = head2;
    return head1;
}