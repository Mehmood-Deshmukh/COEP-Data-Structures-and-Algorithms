#include "./header.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
int main(){
    MinHeap min_heap;
    init_min_heap(&min_heap, 10);
    for(int i = 0; i < 10; i++){
        Edge edge;
        edge.start_vertex = i;
        edge.end_vertex = i + 1;
        edge.weight = i;
        insert_min_heap(&min_heap, edge);
    }

    while(!is_empty_min_heap(min_heap)){
        Edge edge = remove_min_heap(&min_heap);
        printf("%d %d %d\n", edge.start_vertex, edge.end_vertex, edge.weight);
    }

    return 0;
}

