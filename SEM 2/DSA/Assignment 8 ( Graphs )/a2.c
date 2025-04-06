#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* indegree;
    int* outdegree;
} Graph;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->indegree = (int*)calloc(vertices, sizeof(int));
    graph->outdegree = (int*)calloc(vertices, sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    graph->outdegree[src]++;
    graph->indegree[dest]++;
}

// Function to print the outdegree of a given vertex
void printOutdegree(Graph* graph, int vertex) {
    if (vertex < 0 || vertex >= graph->numVertices) {
        printf("Invalid vertex.\n");
        return;
    }
    printf("Outdegree of vertex %d: %d\n", vertex, graph->outdegree[vertex]);
}

// Function to find and print the vertex with maximum indegree
void printMaxIndegree(Graph* graph) {
    int maxIndegree = -1, vertex = -1;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->indegree[i] > maxIndegree) {
            maxIndegree = graph->indegree[i];
            vertex = i;
        }
    }
    printf("Vertex with maximum indegree: %d (Indegree: %d)\n", vertex, maxIndegree);
}

// Function to find and print the vertex with minimum outdegree
void printMinOutdegree(Graph* graph) {
    int minOutdegree = __INT_MAX__, vertex = -1;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->outdegree[i] < minOutdegree) {
            minOutdegree = graph->outdegree[i];
            vertex = i;
        }
    }
    printf("Vertex with minimum outdegree: %d (Outdegree: %d)\n", vertex, minOutdegree);
}

// Function to free the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->indegree);
    free(graph->outdegree);
    free(graph);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int vertex;
    printf("Enter a vertex to find its outdegree: ");
    scanf("%d", &vertex);
    printOutdegree(graph, vertex);

    printMaxIndegree(graph);
    printMinOutdegree(graph);

    freeGraph(graph);
    return 0;
}