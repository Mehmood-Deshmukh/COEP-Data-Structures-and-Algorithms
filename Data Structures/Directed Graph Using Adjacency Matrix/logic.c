#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include "./Queue Implementation using Singly LinkedList/header.h"
#include "./Stack Implementation Using Singly LinkedList/header.h"

void init(Graph *graph, int vertices){
    graph->vertices = vertices;
    graph->edges = 0;
    graph->adjacency_matrix = (int **)malloc(vertices * sizeof(int *));
    if(!graph->adjacency_matrix) return;
    for(int i = 0; i < vertices; i++){
        graph->adjacency_matrix[i] = (int *)calloc(vertices, sizeof(int));
        if(!graph->adjacency_matrix[i]) return;
    }
}

void add_edge(Graph *graph, int source, int destination, int weight){
    graph->adjacency_matrix[source][destination] = weight;
    graph->edges++;
}

void remove_edge(Graph *graph, int source, int destination){
    graph->adjacency_matrix[source][destination] = 0;
}

void print_adjacency_matrix(Graph graph){
    int vertices = graph.vertices;
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            printf("%d ", graph.adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

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
            if(temp) add_edge(graph, i, j, temp);
        }
    }

    fclose(file);

    return;
}

void breadth_first_search(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    if(start_vertex < 0 || start_vertex >= vertices) return;

    int *visited = (int *)calloc(vertices, sizeof(int));
    if(!visited) return;

    Queue queue;
    init_queue(&queue);
    enqueue(&queue, start_vertex);
    visited[start_vertex] = 1;

    while(!is_empty_queue(queue)){
        int current_vertex = dequeue(&queue);
        printf("%d ", current_vertex);


        for(int i = 0; i < vertices; i++){
            if(graph.adjacency_matrix[current_vertex][i] && !visited[i]){
                enqueue(&queue, i);
                visited[i] = 1;
            }
        }
    }

    free(visited);
    free_queue(&queue);
    return;
}

void depth_first_search_helper(Graph graph, int *visited, int current_vertex){
    visited[current_vertex] = 1;
    printf("%d ", current_vertex);
    int vertices = graph.vertices;
    for(int i = 0; i < vertices; i++){
        if(graph.adjacency_matrix[current_vertex][i] && !visited[i]) depth_first_search_helper(graph, visited, i);
    }
}

void depth_first_search(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    if(start_vertex < 0 || start_vertex >= vertices) return;

    int *visited = (int *)calloc(vertices, sizeof(int));
    if(!visited) return;

    depth_first_search_helper(graph, visited, start_vertex);

    for(int i = 0; i < vertices; i++){
        if(!visited[i]) depth_first_search_helper(graph, visited, i);
    }

    free(visited);
}

void iterative_depth_first_search(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    if(start_vertex < 0 || start_vertex >= vertices) return;

    int *visited = (int *)calloc(vertices, sizeof(int));
    if(!visited) return;

    Stack stack;
    init_stack(&stack);
    push(&stack, start_vertex);
    while(!is_empty_stack(stack)){
        int current_vertex = pop(&stack);
        if(!visited[current_vertex]){
            printf("%d ", current_vertex);
            visited[current_vertex] = 1;
        }
        for(int i = vertices; i >= 0; i--){
            if(graph.adjacency_matrix[current_vertex][i] && !visited[i]) push(&stack, i);
        }
        
    }

    free(visited);
}