#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function to check if the current vertex can be added to the Hamiltonian Cycle
bool isSafe(int v, int graph[V][V], int path[], int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex.
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included.
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Utility function to print the solution
void printSolution(int path[]) {
    printf("Solution Exists: Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
    printf(" %d\n", path[0]);
}

// Recursive function to solve the Hamiltonian Cycle problem
bool hamCycleUtil(int graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the cycle
    if (pos == V) {
        // And if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate in the cycle
    for (int v = 1; v < V; v++) {
        // Check if this vertex can be added to the Hamiltonian Cycle
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // If adding vertex v doesn't lead to a solution, remove it
            path[pos] = -1;
        }
    }

    return false;
}

// Function to solve the Hamiltonian Cycle problem
void hamCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Let the first vertex in the path be 0
    path[0] = 0;

    if (!hamCycleUtil(graph, path, 1)) {
        printf("Solution does not exist\n");
        return;
    }

    printSolution(path);
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };

    // Function call
    hamCycle(graph);

    return 0;
}
