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
    printf("\n");
    
    printf("Does the graph contain cycle? %s\n", detect_cycle_depth_first_search(g) ? "yes" : "no");
    printf("Does the graph contain cycle? %s\n", detect_cycle_iterative_depth_first_search(g) ? "yes" : "no");

    for(int i = 0; i < g.vertices; i++){
        Edge *mst = minimum_spanning_tree_prims_algorithm(g, i);
        for(int j = 0; j < g.vertices - 1; j++){
            printf("%d-%d ", mst[j].start_vertex, mst[j].end_vertex);
        }
        printf("\n");
        free(mst);
    } 

    printf("--------------------------------\n");

    for(int i = 0; i < g.vertices; i++){
        Edge *mst = minimum_spanning_tree_prims_algorithm_using_min_heap(g, i);
        for(int j = 0; j < g.vertices - 1; j++){
            printf("%d-%d ", mst[j].start_vertex, mst[j].end_vertex);
        }
        printf("\n");
        free(mst);
    }

    Edge **shortest_paths = shortest_path_from_source_dijkstras_algorithm(g, 0);
    for(int i = 0; i < g.vertices; i++){
        int total_weight = 0;
        for(int j = 0; j < g.vertices; j++){
            if(shortest_paths[i][j].start_vertex == -1) break;
            total_weight += shortest_paths[i][j].weight;
            printf("%d-%d ", shortest_paths[i][j].start_vertex, shortest_paths[i][j].end_vertex);
        }
        printf("Total weight: %d\n", total_weight);
        printf("\n");
    }

    for(int i = 0; i < g.vertices; i++){
        free(shortest_paths[i]);
    }
    
    free(shortest_paths);
}