typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List{
    Node *head;
    Node *tail;
} List;

void init(List *l);
void append(List *l, int data);
void display(List l);
int length(List l);
void insert_at_start(List *l, int data);
void insert_at_index(List *l, int data, int index);
int remove_start(List *l);
int remove_at_index(List *l, int index);
int remove_at_end(List *l);
void destroy(List *l);
void reverse_list(List *l);