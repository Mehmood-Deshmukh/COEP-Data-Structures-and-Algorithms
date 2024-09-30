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
void insertAtStart(List *l, int data);
void insertAtIndex(List *l, int data, int index);
int removeStart(List *l);
int removeAtIndex(List *l, int index);
int removeAtEnd(List *l);
void destroy(List *l);
void reverseList(List *l);
void fill(List *l, int number);
void sortList(List *l);
Node *getMid(List *l);