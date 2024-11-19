typedef struct Node{
    int vertex;
    int weight;
    struct Node *next;
} Node;

typedef struct Edge{
    int start_vertex;
    int end_vertex;
    int weight;
} Edge;

typedef struct Graph{
    int vertices;
    int edges;
    Node **adjacency_list;
} Graph;

void init(Graph *graph, int vertices);
void add_edge(Graph *graph, int start_vertex, int end_vertex, int weight);
void remove_edge(Graph *graph, int start_vertex, int end_vertex);
void create_graph_from_file(Graph * g, char *filename);
void print_adjacency_matrix(Graph graph);
void breadth_first_search(Graph graph, int start_vertex);
void depth_first_search(Graph graph, int start_vertex);
void iterative_depth_first_search(Graph graph, int start_vertex);
Edge *minimum_spanning_tree_prims_algorithm(Graph graph, int start_vertex);
Edge *minimum_spanning_tree_kruskals_algorithm(Graph graph);

Edge **shortest_path_from_source_dijkstras_algorithm(Graph graph, int start_vertex);
int detect_cycle(Graph graph);
void free_graph(Graph *graph);