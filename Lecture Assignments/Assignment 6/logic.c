#include "header.h"


/*
This function initializes the max heap.
It takes a pointer to the max heap as an argument.

It allocates memory for the array that will store the data.
It sets the rear to -1.
It sets the size to MAX_SIZE.
*/
void init_max_heap(max_heap *h){
    h->array = (int *) malloc(sizeof(int) * MAX_SIZE);
    h->rear = -1;
    h->size = MAX_SIZE; 
}

/*
This function initializes the min heap.
It takes a pointer to the min heap as an argument.

It allocates memory for the array that will store the data.
It sets the rear to -1.
It sets the size to MAX_SIZE.
*/
void init_min_heap(min_heap *h){
    h->array = (int *) malloc(sizeof(int) * MAX_SIZE);
    h->rear = -1;
    h->size = MAX_SIZE;
}

/*
This function checks if the max heap is empty.
It returns 1 if the heap is empty, 0 otherwise.
if the rear is -1, then the heap is empty.

*/
int is_empty_max_heap(max_heap h){
    return h.rear == -1;
}

/*
This function checks if the min heap is empty.
It returns 1 if the heap is empty, 0 otherwise.
if the rear is -1, then the heap is empty.
*/

int is_empty_min_heap(min_heap h){
    return h.rear == -1;
}

/*
This function handles the case when the max heap is full.
It takes a pointer to the max heap as an argument.

If the rear is equal to the size of the heap - 1, then the heap is full.
In this case, the function reallocates memory for the array and doubles the size of the heap.
*/

void handle_is_full_max_heap(max_heap *h){
    if(h->rear == h->size - 1){
        h->array = (int *) realloc(h->array, sizeof(int) * h->size * 2);
        h->size = h->size * 2;

    }
    

    return;
}

/*
This function handles the case when the min heap is full.
It takes a pointer to the min heap as an argument.

If the rear is equal to the size of the heap - 1, then the heap is full.
In this case, the function reallocates memory for the array and doubles the size of the heap.
*/

void handle_is_full_min_heap(min_heap *h){
    if(h->rear == h->size - 1){
        h->array = (int *) realloc(h->array, sizeof(int) * h->size * 2);
        h->size = h->size * 2;
    }

    return;
}

/*
This is a helper function that swaps the values of two integers.
*/

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
This is a helper function that returns the index of the parent of a node.

A node at index i has its parent at index (i - 1) / 2.
*/
int get_parent_index(int index){
    return (index - 1) / 2;
}

/*
This function inserts a new element into the max heap.
It takes a pointer to the max heap and the data to be inserted as arguments.

It first checks if the heap is full using the handle_is_full_max_heap function.
It then increments the rear and inserts the data at the rear of the heap.

It then repeatedly swaps the data with its parent until the heap property is satisfied.
*/

void insert_max_heap(max_heap *h, int data){
    handle_is_full_max_heap(h);

    int i = ++h->rear;
    h->array[i] = data;

    while(i > 0 && h->array[get_parent_index(i)] < h->array[i]){
        swap(&h->array[get_parent_index(i)], &h->array[i]);
        i = get_parent_index(i);
    }

    return;
}

/*
This function inserts a new element into the min heap.
It takes a pointer to the min heap and the data to be inserted as arguments.
It first checks if the heap is full using the handle_is_full_min_heap function.

It then increments the rear and inserts the data at the rear of the heap.
It then repeatedly swaps the data with its parent until the heap property is satisfied.
*/

void insert_min_heap(min_heap *h, int data){
    handle_is_full_min_heap(h);

    int i = ++h->rear;
    h->array[i] = data;

    while(i > 0 && h->array[get_parent_index(i)] > h->array[i]){
        swap(&h->array[get_parent_index(i)], &h->array[i]);
        i = get_parent_index(i);
    }

    return;
}

/*
This function heapifies the max heap.
It takes a pointer to the max heap as an argument.

It starts at the root of the heap and repeatedly swaps the root with its largest child until the heap property is satisfied.
*/
void heapify_max_heap(max_heap *h){
    int i = 0;
    int left_child_index;
    int right_child_index;
    int largest_child_index;

    while(1){
        left_child_index = 2 * i + 1;
        right_child_index = 2 * i + 2;
        largest_child_index = i;

        if(left_child_index <= h->rear && h->array[left_child_index] > h->array[largest_child_index]){
            largest_child_index = left_child_index;
        }

        if(right_child_index <= h->rear && h->array[right_child_index] > h->array[largest_child_index]){
            largest_child_index = right_child_index;
        }

        if(largest_child_index == i){
            break;
        }

        swap(&h->array[i], &h->array[largest_child_index]);
        i = largest_child_index;
    }

    return;
}

/*
This function heapifies the min heap.
It takes a pointer to the min heap as an argument.

It starts at the root of the heap and repeatedly swaps the root with its smallest child until the heap property is satisfied.
*/

void heapify_min_heap(min_heap *h){
    int i = 0;
    int left_child_index;
    int right_child_index;
    int smallest_child_index;

    while(1){
        left_child_index = 2 * i + 1;
        right_child_index = 2 * i + 2;
        smallest_child_index = i;

        if(left_child_index <= h->rear && h->array[left_child_index] < h->array[smallest_child_index]){
            smallest_child_index = left_child_index;
        }

        if(right_child_index <= h->rear && h->array[right_child_index] < h->array[smallest_child_index]){
            smallest_child_index = right_child_index;
        }

        if(smallest_child_index == i){
            break;
        }

        swap(&h->array[i], &h->array[smallest_child_index]);
        i = smallest_child_index;
    }

    return;
}

/*
This function removes the maximum element from the max heap.
It takes a pointer to the max heap as an argument.

It returns INT_MIN if the heap is empty.
It returns the maximum element in the heap.
It then replaces the root with the last element in the heap and heapifies the heap.
*/

int remove_max_heap(max_heap *h){
    if(is_empty_max_heap(*h)){
        return INT_MIN;
    }

    int data = h->array[0];
    h->array[0] = h->array[h->rear--];
    heapify_max_heap(h);

    return data;
}

/*
This function removes the minimum element from the min heap.
It takes a pointer to the min heap as an argument.

It returns INT_MAX if the heap is empty.
It returns the minimum element in the heap.
It then replaces the root with the last element in the heap and heapifies the heap.
*/

int remove_min_heap(min_heap *h){
    if(is_empty_min_heap(*h)){
        return INT_MAX;
    }

    int data = h->array[0];
    h->array[0] = h->array[h->rear--];
    heapify_min_heap(h);

    return data;
}

/*
This function prints the max heap.
*/

void print_max_heap(max_heap h){
    if(is_empty_max_heap(h)) return;

    for(int i = 0; i <= h.rear; i++){
        printf("%d ", h.array[i]);
    }

    printf("\n");
}

/*
This function prints the min heap.
*/

void print_min_heap(min_heap h){
    if(is_empty_min_heap(h)) return;

    for(int i = 0; i <= h.rear; i++){
        printf("%d ", h.array[i]);
    }

    printf("\n");
}

/*
This function frees the memory allocated for the max heap.
*/

void free_max_heap(max_heap *h){
    free(h->array);
    h->rear = -1;
    h->size = 0;
}

/*
This function frees the memory allocated for the min heap.
*/

void free_min_heap(min_heap *h){
    free(h->array);
    h->rear = -1;
    h->size = 0;
}

/*
This function sorts an array using the max heap.

It first initializes the max heap and inserts all the elements of the array into the heap.
It then removes the elements from the heap in descending order and stores them back in the array in 
reverse order.
*/

void heap_sort_max_heap(int *array, int size){
    max_heap h;
    init_max_heap(&h);

    for(int i = 0; i < size; i++){
        insert_max_heap(&h, array[i]);
    }

    for(int i = size - 1; i >= 0; i--){
        array[i] = remove_max_heap(&h);
    }

    free_max_heap(&h);

    return;
}

/*
This function sorts an array using the min heap.

It first initializes the min heap and inserts all the elements of the array into the heap.
It then removes the elements from the heap in ascending order and stores them back in the array.
*/

void heap_sort_min_heap(int *array, int size){
    min_heap h;
    init_min_heap(&h);

    for(int i = 0; i < size; i++){
        insert_min_heap(&h, array[i]);
    }

    for(int i = 0; i < size; i++){
        array[i] = remove_min_heap(&h);
    }

    free_min_heap(&h);

    return;
}
