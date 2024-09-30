/*
this structure will be the node of our Doubly Linked  List; 
For it to be a "Doubly" LinkedList we need the node to have two pointers  
A previous pointer "prev" which will point to the previous element  
and a Next pointer "next" which will point to the next element 
 
in case of first Node the prev will point to NULL and 
in case of last element the next will point to NULL 
*/


typedef struct Node{
    int data;  // the data (in our case it is an Integer)
    struct Node *next; // the next pointer
    struct Node *prev; // the prev pointer
} Node;

/*
This will be our Data Structure or more specifically the ADT 
for that we will need two pointers, first one to the beginning of the list 
and other at the end of the list 
we will typedef both of them into ADT list
*/
typedef struct List{
    Node *head; //pointer to the first Node
    Node *tail; //pointer to the last Node
} List;

void init(List *l); // this function initializes the list 
void insertAtStart(List *l, int data); // this function inserts an element at the start of the list
void append(List *l, int data); // this function inserts an element at the end of the list
void insertAtIndex(List *l, int data, int index); // this function inserts an element at a given index in the list
int removeStart(List *l); // this function removes element from the start of the list
int removeAtEnd(List *l); // this function removes element from the end of the list
int removeAtIndex(List *l, int index); // this function removes element from a given index of the list
void sortList(List *l); // this function sorts the list
void displayLR(List l); // this function displays the list from left to right
void displayRL(List l); // this function displays the list from right to left
void removeDuplicates(List *l); // this function removes duplicates from the list
int isPalindrome(List l); // this function checks wether the list is palindrome


// some extra functions
int length(List l);
void destroy(List *l);
void reverseList(List *l);
void fill(List *l, int number);