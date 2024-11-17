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
    graph->edges++;
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

Edge *minimum_spanning_tree_prims_algorithm(Graph graph, int start_vertex){
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
                        edge.weight = min_weight;
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

void swap_edges(Edge *edge1, Edge *edge2){
    Edge temp = *edge1;
    *edge1 = *edge2;
    *edge2 = temp;
}

void partion(Edge *edges, int edge_count, int *pivot){
    int i = 0, j = edge_count - 1;
    Edge p = edges[0];
    while(i < j){
        while(i < edge_count && edges[i].weight <= p.weight) i++;
        while(j > 0 && edges[j].weight > p.weight) j--;
        if(i < j) swap_edges(edges + i, edges + j);
    }
    swap_edges(edges, edges + j);
    *pivot = j;
}

void sort_edges(Edge *edges, int edge_count){
    if(edge_count <= 1) return;
    int pivot;
    partion(edges, edge_count, &pivot);
    sort_edges(edges, pivot);
    sort_edges(edges + pivot + 1, edge_count - pivot - 1);
}

int get_parent(int *parent, int vertex){
    if(parent[vertex] == vertex) return vertex;

    return parent[vertex] = get_parent(parent, parent[vertex]);
}

void union_set(int *parent, int *rank, int vertex1, int vertex2){
    int parent1 = get_parent(parent, vertex1);
    int parent2 = get_parent(parent, vertex2);

    if(parent1 != parent2){
        if(rank[parent1] < rank[parent2]){
            parent[parent1] = parent2;
        }else if(rank[parent1] > rank[parent2]){
            parent[parent2] = parent1;
        }else{
            parent[parent1] = parent2;
            rank[parent2]++;
        }
    }

    return;
}

Edge *minimum_spanning_tree_kruskals_algorithm(Graph graph){
    int vertices = graph.vertices;
    int total_edges = graph.edges;
    Edge *edges = (Edge *)malloc(total_edges * sizeof(Edge));
    int edge_count = 0;

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            if(graph.adjacency_matrix[i][j] && i <= j){
                edges[edge_count].start_vertex = i;
                edges[edge_count].end_vertex = j;
                edges[edge_count].weight = graph.adjacency_matrix[i][j];
                edge_count++;
            }
        }
    }


    sort_edges(edges, edge_count);

    int *parent = (int *)malloc(vertices * sizeof(int));
    for(int i = 0; i < vertices; i++){
        parent[i] = i;
    }
    int *rank = (int *)calloc(vertices, sizeof(int));


    int edge_count_mst = 0;
    int total_weight = 0;
    Edge *mst = (Edge *)malloc((vertices - 1) * sizeof(Edge));
    
    for(int i = 0; i < edge_count && edge_count_mst < vertices - 1; i++){
        Edge current_edge = edges[i];
        int start_vertex = current_edge.start_vertex;
        int end_vertex = current_edge.end_vertex;
        int weight = current_edge.weight;

        if(get_parent(parent, start_vertex) != get_parent(parent, end_vertex)){
            mst[edge_count_mst++] = current_edge;
            total_weight += weight;
            union_set(parent, rank, start_vertex, end_vertex);
        }
    }

    if(edge_count_mst < vertices - 1){
        printf("Graph is not connected\n");
        free(mst);
        mst = NULL;
    } else{
        printf("Total weight of the minimum spanning tree using Kruskal's algorithm is %d\n", total_weight);
    }

    free(parent);
    free(rank);
    free(edges);
    return mst;
}

Edge **shortest_path_from_source_dijkstras_algorithm(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));
    int *distance = (int *)malloc(vertices * sizeof(int));
    int *parent = (int *)malloc(vertices * sizeof(int));

    for(int i = 0; i < vertices; i++){
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[start_vertex] = 0;


    for(int i = 0; i < vertices; i++){
        int min_distance = INT_MAX;
        int current_vertex = -1;

        for(int j = 0; j < vertices; j++){
            if(!visited[j] && distance[j] < min_distance){
                min_distance = distance[j];
                current_vertex = j;
            }
        }

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
    


void free_graph(Graph *graph) {
    int vertices = graph->vertices;
    for (int i = 0; i < vertices; i++) {
        free(graph->adjacency_matrix[i]);
    }
    free(graph->adjacency_matrix);
    graph->adjacency_matrix = NULL; 
    graph->vertices = 0;
} 