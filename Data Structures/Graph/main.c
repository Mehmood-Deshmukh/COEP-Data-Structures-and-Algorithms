#include "header.h"
#include <stdio.h>

int main(){
    Graph g;
    create_graph_from_file(&g, "graph.txt");
    print_graph(g);
    printf("\n");
    for(int i = 0; i < g.vertices; i++){
        breadth_first_search(g, i);
    }

    printf("\n");

    for(int i = 0; i < g.vertices; i++){
        depth_first_search(g, i);
    }
    
    free_graph(&g);
    return 0;
}