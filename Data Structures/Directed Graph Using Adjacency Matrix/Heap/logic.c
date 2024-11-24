#include "./header.h"
#include "../header.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void init_min_heap(MinHeap *min_heap, int capacity){
    min_heap->edges = (Edge *)malloc(capacity * sizeof(Edge));
    min_heap->size = 0;
    min_heap->capacity = capacity;
}

void swap_edges_min_heap(Edge *edge1, Edge *edge2){
    Edge temp = *edge1;
    *edge1 = *edge2;
    *edge2 = temp;
}

int get_parent_min_heap(int index){
    return (index - 1) / 2;
}

void insert_min_heap(MinHeap *min_heap, Edge edge){
    if(min_heap->size == min_heap->capacity){
        return;
    }

    min_heap->edges[min_heap->size] = edge;
    int current = min_heap->size;
    int parent = get_parent_min_heap(current);

    while(current > 0 && min_heap->edges[current].weight < min_heap->edges[parent].weight){
        swap_edges_min_heap(min_heap->edges + current, min_heap->edges + parent);
        current = parent;
        parent = get_parent_min_heap(current);
    }

    min_heap->size++;
}

void heapify_min_heap(MinHeap *min_heap, int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if(left < min_heap->size && min_heap->edges[left].weight < min_heap->edges[smallest].weight){
        smallest = left;
    }

    if(right < min_heap->size && min_heap->edges[right].weight < min_heap->edges[smallest].weight){
        smallest = right;
    }

    if(smallest != index){
        swap_edges_min_heap(min_heap->edges + index, min_heap->edges + smallest);
        heapify_min_heap(min_heap, smallest);
    }
}

Edge remove_min_heap(MinHeap *min_heap){
    if(min_heap->size == 0){
        Edge edge;
        edge.start_vertex = -1;
        edge.end_vertex = -1;
        edge.weight = -1;
        return edge;
    }

    Edge min_edge = min_heap->edges[0];
    min_heap->size--;
    min_heap->edges[0] = min_heap->edges[min_heap->size];
    heapify_min_heap(min_heap, 0);

    return min_edge;
}

int is_empty_min_heap(MinHeap min_heap){
    return min_heap.size == 0;
}

void free_min_heap(MinHeap *min_heap){
    min_heap->capacity = 0;
    min_heap->size = 0;
    free(min_heap->edges);
}
