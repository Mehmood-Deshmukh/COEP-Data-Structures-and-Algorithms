#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "./Queue Implementation using Singly LinkedList/header.h"
#include "./Stack Implementation Using Singly LinkedList/header.h"
#include "./Heap/header.h"

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
    graph->edges--;
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
    free_stack(&stack);
}

int detect_cycle_depth_first_search_helper(Graph graph, int *visited,  int current_vertex, int parent){
    int vertices = graph.vertices;
    visited[current_vertex] = 1;
    
    for(int i = 0; i < vertices; i++){
        if(graph.adjacency_matrix[current_vertex][i]){
            if(!visited[i]){
                if(detect_cycle_depth_first_search_helper(graph, visited, i, current_vertex)) return 1;
            }else if(i != parent) return 1;
        }
    }

    return 0;
}

int detect_cycle_depth_first_search(Graph graph){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));
    if(!visited) return -1;

    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            if(detect_cycle_depth_first_search_helper(graph, visited, i, -1)){
                free(visited);
                return 1;
            }
        }
    }

    free(visited);
    return 0;
}

int detect_cycle_iterative_depth_first_search(Graph graph){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));
    if(!visited) return -1;
    int *parent = (int *)malloc(vertices * sizeof(int));
    if(!parent){
        free(visited);
        return -1;
    }

    for(int i = 0; i < vertices; i++){
        parent[i] = -1;
    }

    Stack stack;
    init_stack(&stack);
    for(int start = 0; start < vertices; start++){
        if(!visited[start]){
            push(&stack, start);

            while(!is_empty_stack(stack)){
                int current_vertex = pop(&stack);
                if(!visited[current_vertex]) visited[current_vertex] = 1;

                for(int i = 0; i < vertices; i++){
                    if(graph.adjacency_matrix[current_vertex][i]){
                        if(!visited[i]){
                            parent[i] = current_vertex;
                            push(&stack, i);
                        }
                        else if(i != parent[current_vertex]){
                            free(visited);
                            free(parent);
                            free_stack(&stack);
                            return 1;
                        }
                    }
                }
            }
        }
    }

    free(parent);
    free(visited);
    free_stack(&stack);
    return 0;
}

detect_cycle_breadth_first_search(Graph graph){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));
    if(!visited) return -1;
    int *parent = (int *)malloc(vertices * sizeof(int));
    if(!parent){
        free(visited);
        return -1;
    }

    for(int i = 0; i < vertices; i++){
        parent[i] = -1;
    }

    Queue queue;
    init_queue(&queue);
    for(int start = 0; start < vertices; start++){
        if(!visited[start]){
            enqueue(&queue, start);
            visited[start] = 1;

            while(!is_empty_queue(queue)){
                int current_vertex = dequeue(&queue);

                for(int i = 0; i < vertices; i++){
                    if(graph.adjacency_matrix[current_vertex][i]){
                        if(!visited[i]){
                            parent[i] = current_vertex;
                            enqueue(&queue, i);
                            visited[i] = 1;
                        }
                        else if(i != parent[current_vertex]){
                            free(visited);
                            free(parent);
                            free_queue(&queue);
                            return 1;
                        }
                    }
                }
            }
        }
    }

    free(parent);
    free(visited);
    free_queue(&queue);
    return 0;
}

Edge find_minimum_edge_iteratively(Graph graph, int *visited){
    int vertices = graph.vertices;
    int min_weight = INT_MAX;
    Edge edge = {-1, -1, -1};
    for(int i = 0; i < vertices; i++){
        if(visited[i]){
            for(int j = 0; j < vertices; j++){
                if(graph.adjacency_matrix[i][j] && !visited[j] && graph.adjacency_matrix[i][j] < min_weight){
                    min_weight = graph.adjacency_matrix[i][j];
                    edge.start_vertex = i;
                    edge.end_vertex = j;
                    edge.weight = min_weight;
                }
            }
        }
    }

    return edge;
}

Edge *minimum_spanning_tree_prims_algorithm(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));
    if(!visited) return NULL;

    Edge *edges = (Edge *)malloc((vertices - 1) * sizeof(Edge));
    if(!edges){
        free(visited);
        return NULL;
    }

    int edge_count = 0, total_weight = 0;
    Edge edge;

    visited[start_vertex] = 1;

    while (edge_count < vertices - 1){
        edge = find_minimum_edge_iteratively(graph, visited);
        if (edge.weight == -1) {
            free(visited);
            free(edges);
            return NULL;
        }
        total_weight += edge.weight;
        visited[edge.end_vertex] = 1;
        edges[edge_count++] = edge;
    }

    free(visited);
    printf("Total weight of the minimum spanning tree is %d when started from %d\n", total_weight, start_vertex);
    return edges;
    
}

Edge *minimum_spanning_tree_prims_algorithm_using_min_heap(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));
    if(!visited) return NULL;

    Edge *edges = (Edge *)malloc((vertices - 1) * sizeof(Edge));
    if(!edges){
        free(visited);
        return NULL;
    }

    int total_edges = graph.edges;
    MinHeap min_heap;
    init_min_heap(&min_heap, total_edges);

    visited[start_vertex] = 1;
    for(int i = 0; i < vertices; i++){
        if(graph.adjacency_matrix[start_vertex][i]){
            Edge edge;
            edge.start_vertex = start_vertex;
            edge.end_vertex = i;
            edge.weight = graph.adjacency_matrix[start_vertex][i];
            insert_min_heap(&min_heap, edge);
        }
    }



    int edge_count = 0, total_weight = 0;
    Edge edge;

    while(!is_empty_min_heap(min_heap)){
        edge = remove_min_heap(&min_heap);
        if(visited[edge.end_vertex]) continue;

        visited[edge.end_vertex] = 1;
        total_weight += edge.weight;
        edges[edge_count++] = edge;
        for(int i = 0; i < vertices; i++){
            if(graph.adjacency_matrix[edge.end_vertex][i]){
                Edge new_edge;
                new_edge.start_vertex = edge.end_vertex;
                new_edge.end_vertex = i;
                new_edge.weight = graph.adjacency_matrix[edge.end_vertex][i];
                insert_min_heap(&min_heap, new_edge);
            }
        }

    }


    free(visited);
    free_min_heap(&min_heap);

    if (edge_count != vertices - 1) {
        free(edges);
        return NULL;
    }

    printf("Total weight of the minimum spanning tree is %d when started from %d\n", total_weight, start_vertex);
    return edges;
}

int get_minimum_distanced_vertex_dijkstras_algorithm(int *visited, int *distance, int vertices){
    int min_distance = INT_MAX;
    int min_vertex = -1;

    for(int i = 0; i < vertices; i++){
        if(!visited[i] && distance[i] < min_distance){
            min_distance = distance[i];
            min_vertex = i;
        }
    }

    return min_vertex;
}


Edge **shortest_path_from_source_dijkstras_algorithm(Graph graph, int start_vertex){
    int vertices = graph.vertices;

    int *visited = (int *)calloc(vertices, sizeof(int));
    if(!visited) return NULL;

    int *distance = (int *)malloc(vertices * sizeof(int));
    if(!distance){
        free(visited);
        return NULL;
    }

    int *parent = (int *)malloc(vertices * sizeof(int));
    if(!parent){
        free(visited);
        free(distance);
        return NULL;
    }

    for(int i = 0; i < vertices; i++){
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[start_vertex] = 0;

    for(int i = 0; i < vertices; i++){
        int current_vertex = get_minimum_distanced_vertex_dijkstras_algorithm(visited, distance, vertices);

        if(current_vertex == -1) break;

        visited[current_vertex] = 1;

        for(int j = 0; j < vertices; j++){
            if(graph.adjacency_matrix[current_vertex][j] && !visited[j]){
                int new_distance = distance[current_vertex] + graph.adjacency_matrix[current_vertex][j];
                if(new_distance < distance[j]){
                    distance[j] = new_distance;
                    parent[j] = current_vertex;
                }
            }
        }        
    }

    Edge **shortest_paths = (Edge **)malloc(vertices * sizeof(Edge *));
    for(int i = 0; i < vertices; i++){
        shortest_paths[i] = (Edge *)malloc(vertices * sizeof(Edge));
    }

    for(int i = 0; i < vertices; i++){
        int current_vertex = i;
        int j = 0;
        while(current_vertex != start_vertex){
            shortest_paths[i][j].start_vertex = parent[current_vertex];
            shortest_paths[i][j].end_vertex = current_vertex;
            shortest_paths[i][j].weight = graph.adjacency_matrix[parent[current_vertex]][current_vertex];
            current_vertex = parent[current_vertex];
            j++;
        }
        shortest_paths[i][j].start_vertex = -1;
    }

    free(visited);
    free(distance);
    free(parent);
    return shortest_paths;

}