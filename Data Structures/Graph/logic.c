#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include "./Queue Implementation using Singly LinkedList/header.h"

void init(Graph *graph, int vertices){
    graph->vertices = vertices;

    graph->adjacency_matrix = (int **)malloc(vertices * sizeof(int *));
    for(int i = 0; i < vertices; i++){
        graph->adjacency_matrix[i] = (int *)calloc(vertices, sizeof(int));
    }

    return;
}

void add_edge(Graph *graph, int source, int destination){
    graph->adjacency_matrix[source][destination] = 1;
    graph->adjacency_matrix[destination][source] = 1;
}

void remove_edge(Graph *graph, int source, int destination){
    graph->adjacency_matrix[source][destination] = 0;
    graph->adjacency_matrix[destination][source] = 0;
}

void print_adjacency_matrix(Graph graph){
    int vertices = graph.vertices;
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            printf("%d ", graph.adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    return;
}

void create_graph_from_file(Graph *graph, char *filename){
    FILE *file = fopen(filename, "r");
    if(!file){
        perror("Error opening file: ");
        return;
    }
    int vertices, temp;

    fscanf(file, "%d", &vertices);

    init(graph, vertices);

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            fscanf(file, "%d", &temp);
            if(temp && i <= j){
                add_edge(graph, i, j);
            }
        }
    }

    fclose(file);
    return;
}


void breadth_first_search(Graph graph, int start_vertex){
    if(!graph.adjacency_matrix) return;


    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));

    Queue queue;
    init_queue(&queue);

    visited[start_vertex] = 1;
    enqueue(&queue, start_vertex);

    while(!is_empty(queue)){
        int current_vertex = dequeue(&queue);
        printf("%d ", current_vertex);

        for(int i = 0; i < vertices; i++){
            if(graph.adjacency_matrix[current_vertex][i] && !visited[i]){
                visited[i] = 1;
                enqueue(&queue, i);
            }
        }
    }

    printf("\n");
    free(visited);
    return;
}

void depth_first_search_helper(Graph graph, int *visited, int current_vertex){
    visited[current_vertex] = 1;
    printf("%d ", current_vertex);

    for(int i = 0; i < graph.vertices; i++){
        if(graph.adjacency_matrix[current_vertex][i] && !visited[i]){
            depth_first_search_helper(graph, visited, i);
        }
    }
}


void depth_first_search(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));

    depth_first_search_helper(graph, visited, start_vertex);

    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            depth_first_search_helper(graph, visited, i);
        }
    }

    printf("\n");
}


void free_graph(Graph *graph) {
    int vertices = graph->vertices;
    for (int i = 0; i < vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    graph->adjacency_matrix = NULL; 
    graph->vertices = 0;
}