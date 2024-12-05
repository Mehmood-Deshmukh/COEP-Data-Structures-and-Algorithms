#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/*  Create a new node */
Node* create_node(int key, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

/* Initialize the hash table */
void init_hash_table(HashTable* ht, int size) {
    ht->size = size;
    ht->array = (Node**)malloc(ht->size * sizeof(Node*));

    for (int i = 0; i < ht->size; i++) {
        ht->array[i] = NULL;
    }
}

/* Hash function to map values to key */
int hash(int key, int size) {
    return key % size;
}

/* Insert key-value pair into hash table */
void insert(HashTable* ht, int key, int value) {
    int index = hash(key, ht->size);
    Node* new_node = create_node(key, value);
    /* use chaining */
    if (ht->array[index] != NULL) {
        Node* temp = ht->array[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    } else {
        ht->array[index] = new_node;
    }
}

/* Search for a key in the hash table */
int search(HashTable* ht, int key) {
    int index = hash(key, ht->size);

    if (ht->array[index] != NULL) {
        Node* temp = ht->array[index];
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
    }

    return -1;
}

/* Remove a key from the hash table */
int remove_node(HashTable* ht, int key) {
    int index = hash(key, ht->size);

    if (ht->array[index] != NULL) {
        Node* temp = ht->array[index];
        Node* prev = NULL;
        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL) {
                    ht->array[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                int value = temp->value;
                free(temp);
                return value;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    return -1;
}

/* Display the contents of the hash table */
void display(HashTable ht) {
    for (int i = 0; i < ht.size; i++) {
        if(ht.array[i] != NULL) {
            Node* temp = ht.array[i];
            printf("Index %d: ", i);
            while (temp != NULL) {
                printf("(%d, %d) -> ", temp->key, temp->value);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

