// this structure will be the node of our Doubly Linked  List;
// For it to be a "Doubly" LinkedList we need the node to have two pointers 
// A previous pointer "prev" which will point to the previous element 
// and a Next pointer "next" which will point to the next element


//in case of first Node the prev will point to NULL and
// in case of last element the next will point to NULL

typedef struct Node{
    int data; // the data (in our case it is an Integer as the ASCII values will be stored as Integers)
    struct Node *next; // the next pointer
    struct Node *prev; // the prev pointer
} Node;

// This will be our Data Structure or more specifically the ADT
// for that we will need two pointers, first one to the beginning of the list and
// other at the end of the list
// we can typedef them into a struct which is our Ascii ADT.

typedef struct ascii{
    Node *head; //pointer to the first Node
    Node *tail; // pointer to the last Node
} Ascii;

//These are the functions mentioned in the assignment to implement :

void initAscii(Ascii *l); //  // this function initializes the list
void asciiOf(Ascii *l, char ch);/* This function takes a character as an argument and form a linked list of digits in its ASCII value. For example if ‘A’ is passed as a parameter, it should generate a list {6,5} */
void traverse(Ascii l); // this function displays all the elements of the list.
void destroy(Ascii *l); //  this function destroys the list.




int isEmpty(Ascii l);
int length(Ascii l);
void append(Ascii *l, int data);
void insertAtStart(Ascii *l, int data);
void insertAtIndex(Ascii *l, int data, int index);
int removeStart(Ascii *l);
int removeAtIndex(Ascii *l, int index);
int removeAtEnd(Ascii *l);
void reverseList(Ascii *l);