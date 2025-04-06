#include <stdio.h>

#define MAX 100

void createAdjMatrix(int adjMatrix[MAX][MAX], int vertices, int edges) {
    int i, src, dest;
    for (i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1; // Directed graph
    }
}

void displayAdjMatrix(int adjMatrix[MAX][MAX], int vertices) {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void calculateDegrees(int adjMatrix[MAX][MAX], int vertices) {
    int i, j, indegree, outdegree, totalDegree;

    printf("\nVertex\tIndegree\tOutdegree\tTotal Degree\n");
    for (i = 0; i < vertices; i++) {
        indegree = outdegree = 0;
        for (j = 0; j < vertices; j++) {
            if (adjMatrix[j][i] == 1) {
                indegree++;
            }
            if (adjMatrix[i][j] == 1) {
                outdegree++;
            }
        }
        totalDegree = indegree + outdegree;
        printf("%d\t%d\t\t%d\t\t%d\n", i, indegree, outdegree, totalDegree);
    }
}

int main() {
    int adjMatrix[MAX][MAX] = {0};
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    createAdjMatrix(adjMatrix, vertices, edges);
    displayAdjMatrix(adjMatrix, vertices);
    calculateDegrees(adjMatrix, vertices);

    return 0;
}