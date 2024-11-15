#include "header.h"

void init_max_heap(max_heap *h){
    h->array = (int *) malloc(sizeof(int) * MAX_SIZE);
    h->rear = -1;
    h->size = MAX_SIZE; 
}


void init_min_heap(min_heap *h){
    h->array = (int *) malloc(sizeof(int) * MAX_SIZE);
    h->rear = -1;
    h->size = MAX_SIZE;
}

int is_empty_max_heap(max_heap h){
    return h.rear == -1;
}

int is_empty_min_heap(min_heap h){
    return h.rear == -1;
}

void handle_is_full_max_heap(max_heap *h){
    if(h->rear == h->size - 1){
        h->array = (int *) realloc(h->array, sizeof(int) * h->size * 2);
        h->size = h->size * 2;

    }
    

    return;
}

void handle_is_full_min_heap(min_heap *h){
    if(h->rear == h->size - 1){
        h->array = (int *) realloc(h->array, sizeof(int) * h->size * 2);
        h->size = h->size * 2;
    }

    return;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int get_parent_index(int index){
    return (index - 1) / 2;
}

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

int remove_max_heap(max_heap *h){
    if(is_empty_max_heap(*h)){
        return INT_MIN;
    }

    int data = h->array[0];
    h->array[0] = h->array[h->rear--];
    heapify_max_heap(h);

    return data;
}

int remove_min_heap(min_heap *h){
    if(is_empty_min_heap(*h)){
        return INT_MAX;
    }

    int data = h->array[0];
    h->array[0] = h->array[h->rear--];
    heapify_min_heap(h);

    return data;
}

void print_max_heap(max_heap h){
    if(is_empty_max_heap(h)) return;

    for(int i = 0; i <= h.rear; i++){
        printf("%d ", h.array[i]);
    }

    printf("\n");
}

void print_min_heap(min_heap h){
    if(is_empty_min_heap(h)) return;

    for(int i = 0; i <= h.rear; i++){
        printf("%d ", h.array[i]);
    }

    printf("\n");
}

void free_max_heap(max_heap *h){
    free(h->array);
    h->rear = -1;
    h->size = 0;
}

void free_min_heap(min_heap *h){
    free(h->array);
    h->rear = -1;
    h->size = 0;
}


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
