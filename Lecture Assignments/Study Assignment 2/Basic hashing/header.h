#define SIZE 10

typedef struct Data {
    int key;
    int value;
} Data;


typedef struct HashTable{
    int size;
    Data* array;
} HashTable;


void init_hash_table(HashTable* ht, int size);
int hash(int key, int size);
void insert(HashTable* ht, int key, int value);
int search(HashTable* ht, int key);
int remove_node(HashTable* ht, int key);
void display(HashTable ht);
