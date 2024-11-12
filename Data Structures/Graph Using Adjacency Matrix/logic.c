#include "header.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "./Queue Implementation using Singly LinkedList/header.h"
#include "./Stack Implementation Using Singly LinkedList/header.h" 

void init(Graph *graph, int vertices){
    graph->vertices = vertices;

    graph->adjacency_matrix = (int **)malloc(vertices * sizeof(int *));
    for(int i = 0; i < vertices; i++){
        graph->adjacency_matrix[i] = (int *)calloc(vertices, sizeof(int));
    }

    return;
}

void add_edge(Graph *graph, int source, int destination, int weight){
    graph->adjacency_matrix[source][destination] = weight;
    graph->adjacency_matrix[destination][source] = weight;
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
                add_edge(graph, i, j, temp);
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

    while(!is_empty_queue(queue)){
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

void iterative_depth_first_search(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));

    Stack stack;
    init_stack(&stack);
    push(&stack, start_vertex);

    while(!is_empty_stack(stack)){
        int current_vertex = pop(&stack);
        if(!visited[current_vertex]){
            printf("%d ", current_vertex);
            visited[current_vertex] = 1;
        }

        for(int i = 0; i < vertices; i++){
            if(graph.adjacency_matrix[current_vertex][i] && !visited[i]){
                push(&stack, i);
            }
        }
    }

    printf("\n");
    free(visited);
    return;
}

int detect_cycle(Graph graph){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));
    int *parent = (int *) calloc(vertices, sizeof(int));
    Stack stack;

    for(int start_vertex = 0; start_vertex < vertices; start_vertex++){
        if(!visited[start_vertex]){
            init_stack(&stack);
            push(&stack, start_vertex);
            parent[start_vertex] = -1;

            while(!is_empty_stack(stack)){
                int current_vertex = pop(&stack);
                if(!visited[current_vertex]) visited[current_vertex] = 1;

                for(int i = vertices - 1; i >= 0; i--){
                    if(graph.adjacency_matrix[current_vertex][i] && !visited[i]){
                        push(&stack, i);
                        parent[i] = current_vertex;
                    }else if(visited[i] &&  i != parent[current_vertex]){
                        free(visited);
                        free(parent);

                        return 1;
                    }
                }
            }
        }
    }
    
    free(visited);
    free(parent);
    return 0;
}

Edge *minimum_spanning_tree(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));

    Edge *edges = (Edge *)malloc((vertices - 1) * sizeof(Edge));
    int edge_count = 0, min_weight = INT_MAX;

    visited[start_vertex] = 1;
    int total_weight = 0;
    Edge edge;


    while(edge_count < vertices - 1){
        min_weight = INT_MAX;
        for(int i = 0; i < vertices; i++){
            if(visited[i]){
                for(int j = 0; j < vertices; j++){
                    if(graph.adjacency_matrix[i][j] && !visited[j] && graph.adjacency_matrix[i][j] < min_weight){
                        min_weight = graph.adjacency_matrix[i][j];
                        edge.start_vertex = i;
                        edge.end_vertex = j;
                    }
                }
            }
        }

        if(min_weight == INT_MAX){
            break;
        }
        total_weight += min_weight;
        visited[edge.end_vertex] = 1;
        edges[edge_count++] = edge;
    }

    free(visited);
    printf("Total weight of the minimum spanning tree is %d when started from %d\n", total_weight, start_vertex);
    return edges;
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