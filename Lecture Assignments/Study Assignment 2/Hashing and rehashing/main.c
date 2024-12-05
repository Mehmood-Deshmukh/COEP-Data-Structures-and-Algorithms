#include <stdio.h>
#include "./header.h"

int main() {
    HashTable ht;
    init_hash_table(&ht, SIZE);

    insert(&ht, 1, 10);
    insert(&ht, 2, 20);
    insert(&ht, 3, 30);
    insert(&ht, 4, 40);
    insert(&ht, 5, 50);

    display(ht);

    int key = 3;
    printf("Searching for key %d, found value: %d\n", key, search(&ht, key));

    key = 5;
    printf("Removing key %d, removed value: %d\n", key, remove_node(&ht, key));

    display(ht);

    printf("Testing collision\n");
    insert(&ht, 1, 100);
    display(ht);

    return 0;
}