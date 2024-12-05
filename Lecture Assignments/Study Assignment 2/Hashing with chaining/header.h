#define SIZE 10

/* Data structure to store key-value pairs */
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

/* Data structure to store hash table */
typedef struct HashTable {
    struct Node** array;
    int size;
} HashTable;

/* function prototypes */
Node* create_node(int key, int value);
void init_hash_table(HashTable* ht, int size);
int hash(int key, int size);
void insert(HashTable* ht, int key, int value);
int search(HashTable* ht, int key);
int remove_node(HashTable* ht, int key);
void display(HashTable ht);
void analyze(HashTable* ht, float load_factor);