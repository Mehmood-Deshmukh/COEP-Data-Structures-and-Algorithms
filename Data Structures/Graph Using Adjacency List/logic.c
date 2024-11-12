#include "header.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "./Queue Implementation using Singly LinkedList/header.h"
#include "./Stack Implementation Using Singly LinkedList/header.h" 

void init(Graph *graph, int vertices){
    graph->vertices = vertices;
    
    graph->adjacency_list = (Node **)malloc(vertices * sizeof(Node *));
    for(int i = 0; i < vertices; i++){
        graph->adjacency_list[i] = NULL;
    }
}

Node * create_node(int vertex, int weight){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->vertex = vertex;
    new_node->weight = weight;
    new_node->next = NULL;

    return new_node;
}

void add_edge(Graph *graph, int source, int destination, int weight){
    Node *new_node = create_node(destination, weight);
    new_node->next = graph->adjacency_list[source];
    graph->adjacency_list[source] = new_node;

    new_node = create_node(source, weight);
    new_node->next = graph->adjacency_list[destination];
    graph->adjacency_list[destination] = new_node;
}

void remove_edge(Graph *graph, int source, int destination){
    Node *temp = graph->adjacency_list[source];
    Node *prev = NULL;

    while(temp && temp->vertex != destination){
        prev = temp;
        temp = temp->next;
    }

    if(!temp) return;

    if(!prev){
        graph->adjacency_list[source] = temp->next;
    }else{
        prev->next = temp->next;
    }

    free(temp);

    temp = graph->adjacency_list[destination];
    prev = NULL;

    while(temp && temp->vertex != source){
        prev = temp;
        temp = temp->next;
    }

    if(!temp) return;

    if(!prev){
        graph->adjacency_list[destination] = temp->next;
    }else{
        prev->next = temp->next;
    }

    free(temp);
}

void print_adjacency_matrix(Graph graph){
    int vertices = graph.vertices;
    for(int i = 0; i < vertices; i++){
        Node *temp = graph.adjacency_list[i];
        printf("%d: ", i);
        while(temp){
            printf("%d(%d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

void create_graph_from_file(Graph *graph, char *filename){
    FILE *file = fopen(filename, "r");
    if(!file) return;

    int vertices;
    fscanf(file, "%d", &vertices);

    init(graph, vertices);

    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            int weight;
            fscanf(file, "%d", &weight);
            if(weight && i <= j){
                add_edge(graph, i, j, weight);
            }
        }
    }

    fclose(file);

    return;
}


void breadth_first_search(Graph graph, int start_vertex){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));

    Queue queue;
    init_queue(&queue);
    enqueue(&queue, start_vertex);

    while(!is_empty_queue(queue)){
        int current_vertex = dequeue(&queue);
        if(!visited[current_vertex]){
            printf("%d ", current_vertex);
            visited[current_vertex] = 1;
        }

        Node *temp = graph.adjacency_list[current_vertex];
        while(temp){
            if(!visited[temp->vertex]){
                enqueue(&queue, temp->vertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(visited);
    return;
}

void depth_first_search_helper(Graph graph, int *visited, int current_vertex){
    if(!visited[current_vertex]){
        printf("%d ", current_vertex);
        visited[current_vertex] = 1;
    }

    Node *temp = graph.adjacency_list[current_vertex];
    while(temp){
        if(!visited[temp->vertex]){
            depth_first_search_helper(graph, visited, temp->vertex);
        }
        temp = temp->next;
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
    free(visited);
    return;
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

        Node *temp = graph.adjacency_list[current_vertex];
        while(temp){
            if(!visited[temp->vertex]){
                push(&stack, temp->vertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(visited);
    return;
}

int detect_cycle(Graph graph){
    int vertices = graph.vertices;
    int *visited = (int *)calloc(vertices, sizeof(int));
    int *parent = (int *)calloc(vertices, sizeof(int));

    Stack stack;
    init_stack(&stack);

    for(int i = 0; i < vertices; i++){
        if(!visited[i]){
            push(&stack, i);
            parent[i] = -1;
            while(!is_empty_stack(stack)){
                int current_vertex = pop(&stack);
                if(visited[current_vertex]){
                    free(visited);
                    free(parent);
                    return 1;
                }
                visited[current_vertex] = 1;

                Node *temp = graph.adjacency_list[current_vertex];
                while(temp){
                    if(!visited[temp->vertex]){
                        push(&stack, temp->vertex);
                        parent[temp->vertex] = current_vertex;
                    }else if(parent[current_vertex] != temp->vertex){
                        return 1;
                    }
                    temp = temp->next;
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

    Edge edge;

    int total_weight = 0;

    while(edge_count < vertices - 1){
        min_weight = INT_MAX;
        for(int i = 0; i < vertices; i++){
            if(visited[i]){
                Node *temp = graph.adjacency_list[i];
                while(temp){
                    if(!visited[temp->vertex] && temp->weight < min_weight){
                        min_weight = temp->weight;
                        edge.start_vertex = i;
                        edge.end_vertex = temp->vertex;
                    }
                    temp = temp->next;
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
    for (int i = 0; i < graph->vertices; i++) {
        Node *temp = graph->adjacency_list[i];
        while (temp) {
            Node *prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(graph->adjacency_list);
    graph->vertices = 0;
}