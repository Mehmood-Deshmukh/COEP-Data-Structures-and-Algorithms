#define MAX_SIZE 10

typedef struct max_heap{
    int *array;
    int rear;
    int size;
} max_heap;

typedef struct min_heap{
    int *array;
    int rear;
    int size;
} min_heap;

void init_max_heap(max_heap *h);
void init_min_heap(min_heap *h);

int is_empty_max_heap(max_heap h);
int is_empty_min_heap(min_heap h);

void handle_is_full_max_heap(max_heap *h);
void handle_is_full_min_heap(min_heap *h);

void swap(int *a, int *b);
int get_parent_index(int index);

void insert_max_heap(max_heap *h, int data);
void insert_min_heap(min_heap *h, int data);

void heapify_max_heap(max_heap *h);
void heapify_min_heap(min_heap *h);

int remove_max_heap(max_heap *h);
int remove_min_heap(min_heap *h);

void print_max_heap(max_heap h);
void print_min_heap(min_heap h);

void free_max_heap(max_heap *h);
void free_min_heap(min_heap *h);

void heap_sort_max_heap(int *array, int size);
void heap_sort_min_heap(int *array, int size);

