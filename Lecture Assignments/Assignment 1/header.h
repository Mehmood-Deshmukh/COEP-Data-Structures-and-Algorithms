typedef struct Array{
    int *A;
    int size;
    int len;
} Array;

void init(Array *a, int size);
void append(Array *a, int element);
void insertAtIndex(Array *a, int element, int position);
int removeAtIndex(Array *a, int position);
void display(Array a);
int max(Array a);
int min(Array a);
Array merge(Array a1, Array a2);
void sort(Array *a);
void fill(Array *a);
void reverse(Array *a);