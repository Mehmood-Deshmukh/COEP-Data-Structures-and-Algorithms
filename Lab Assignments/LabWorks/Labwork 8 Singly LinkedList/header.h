/*
 This will be the structure of the node of our Singly Linked List
it will contain an integer i.e data and a pointer to the next Node
in case of last Node the next pointer will point to NULL
*/
typedef struct Node {
    int data; /* the data (in our case it is an Integer)*/
    struct Node *next; /*the next pointer*/
} Node;

/*
To make an ADT all we need is a pointer to the first Node.
So we will typedef it as 'List'
*/
typedef Node * List;

/*These are the functions mentioned in the assignment to implement : */
void init(List *l);  /* this function initializes the list */
void append(List *l, int data); /* this function adds an element at the end of the list. */
void display(List l);  /* this function displays the entire list. */
void insertAtBeginning(List *l, int data); /* this function adds an element at the beginning of the list. */
int removeAtIndex(List *l, int index);  /* this function removes an element at the given index from the list. */
int length(List l); /* this function returns the length of the list. */


/*This are some of the extra functions that i have implemented*/
void addNodeAtPosition(List *l, int data, int position); 
int removeEnd(List *l);
int removeBeginning(List *l);
int removeNode(List *l, Node *n);
void swapNodes(List * l, Node * n1, Node * n2);
void fill(List *l, int number);
void reverseEven(List *l);
int isPalindrome(List l);
void removeDuplicates(List *l);
void destroy(List *l);
void removeAndInsert(List *l, Node *n, int index);