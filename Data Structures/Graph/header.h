typedef struct Graph{
    int vertices;
    int **adjacency_matrix;
} Graph;

void init(Graph *graph, int vertices);

void add_edge(Graph *graph, int start_vertex, int end_vertex);
void remove_edge(Graph *graph, int start_vertex, int end_vertex);

void create_graph_from_file(Graph * g, char *filename);
void print_adjacency_matrix(Graph graph);

void breadth_first_search(Graph graph, int start_vertex);
void depth_first_search(Graph graph, int start_vertex);

void free_graph(Graph *graph);
