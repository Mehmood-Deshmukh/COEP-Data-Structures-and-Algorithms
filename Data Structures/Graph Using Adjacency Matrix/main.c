#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Graph g;
    create_graph_from_file(&g, argv[1]);
    print_adjacency_matrix(g);
    printf("\n"); 
    for(int i = 0; i < g.vertices; i++){
        breadth_first_search(g, i);
    }

    printf("\n");

    for(int i = 0; i < g.vertices; i++){
        depth_first_search(g, i);
    }
    printf("\n");

    for(int i = 0; i < g.vertices; i++){
        iterative_depth_first_search(g, i);
    }

    printf("\n");

    for(int i = 0; i < g.vertices; i++){
        Edge *mst = minimum_spanning_tree(g, i);
        for(int j = 0; j < g.vertices - 1; j++){
            printf("%d-%d ", mst[j].start_vertex, mst[j].end_vertex);
        }
        printf("\n");
        free(mst);
    } 

    printf("is the graph cyclic ? %s\n", detect_cycle(g) ? "true" : "false");
    
    free_graph(&g);
    return 0;
}