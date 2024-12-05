#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Initialize the hash table */
void init_hash_table(HashTable* ht, int size) {
    ht->size = size;
    ht->array = (Data*)malloc(ht->size * sizeof(Data));

    for (int i = 0; i < ht->size; i++) {
        ht->array[i] = (Data){-1, -1};
    }
}

/* Hash function to map values to key */
int hash(int key, int size) {
    return key % size;
}

/* Insert key-value pair into hash table */
void insert(HashTable* ht, int key, int value) {
    int index = hash(key, ht->size);
    
    if (ht->array[index].key == -1) {
        ht->array[index] = (Data){key, value};
    } else {
        printf("Collision detected for key %d\n", key);
    }

}

/* Search for a key in the hash table */
int search(HashTable* ht, int key) {
    int index = hash(key, ht->size);

    if (ht->array[index].key == key) {
        return ht->array[index].value;
    }

    return -1;
}

/* Remove a key from the hash table */
int remove_node(HashTable* ht, int key) {
    int index = hash(key, ht->size);

    if (ht->array[index].key == key) {
        ht->array[index] = (Data){-1, -1};
        return key;
    }

    return -1;
}

/* Display the contents of the hash table */
void display(HashTable ht) {
    for (int i = 0; i < ht.size; i++) {
        if(ht.array[i].key != -1)
            printf("Index: %d, Key: %d, Value: %d\n", i, ht.array[i].key, ht.array[i].value);
    }
}
