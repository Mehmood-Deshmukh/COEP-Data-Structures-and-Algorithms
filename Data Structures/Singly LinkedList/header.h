typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef Node * List;

void init(List *l);
void display(List l);
void append(List *l, int data);
void insert_at_beginning(List *l, int data);
int remove_end(List *l);
int remove_beginning(List *l);
int remove_node(List *l, Node *n);
void add_node_at_position(List *l, int data, int position);
int length(List l);
void swap_nodes(List * l, Node * n1, Node * n2);
void fill(List *l, int number);
void reverse_even(List *l);
int is_palindrome(List l);
void remove_duplicates(List *l);
void destroy(List *l);
void remove_and_insert(List *l, Node *n, int index);