#ifndef HEAP_HEADER_H
#define HEAP_HEADER_H

#include "../header.h"

typedef struct MinHeap{
    Edge *edges;
    int size;
    int capacity;
} MinHeap;

void init_min_heap(MinHeap *min_heap, int capacity);
void insert_min_heap(MinHeap *min_heap, Edge edge);
Edge remove_min_heap(MinHeap *min_heap);
int is_empty_min_heap(MinHeap min_heap);
void heapify(MinHeap *min_heap, int index);

#endif