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
    for(int i = 0; i < g.vertices; i++){
        breadth_first_search(g, i);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < g.vertices; i++){
        depth_first_search(g, i);
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < g.vertices; i++){
        iterative_depth_first_search(g, i);
        printf("\n");
    }
}