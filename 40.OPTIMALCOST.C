#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4
#define INF INT_MAX

// Function to find the minimum cost using the Hungarian Algorithm
void hungarianAlgorithm(int costMatrix[N][N], int *assignment, int *minCost) {
    int u[N] = {0}, v[N] = {0}; // Potential values
    int ind[N] = {0}; // Matchings
    int minCostMatrix[N][N]; // Reduced cost matrix

    // Initialize the minimum cost matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            minCostMatrix[i][j] = costMatrix[i][j];
        }
    }

    // Reduce rows
    for (int i = 0; i < N; i++) {
        int minRow = INF;
        for (int j = 0; j < N; j++) {
            if (minRow > minCostMatrix[i][j]) {
                minRow = minCostMatrix[i][j];
            }
        }
        for (int j = 0; j < N; j++) {
            minCostMatrix[i][j] -= minRow;
        }
    }

    // Reduce columns
    for (int j = 0; j < N; j++) {
        int minCol = INF;
        for (int i = 0; i < N; i++) {
            if (minCol > minCostMatrix[i][j]) {
                minCol = minCostMatrix[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            minCostMatrix[i][j] -= minCol;
        }
    }

    // Use a greedy method to find an initial matching
    for (int i = 0; i < N; i++) {
        int j = 0;
        while (j < N && minCostMatrix[i][j] != 0) {
            j++;
        }
        if (j < N) {
            ind[i] = j;
        }
    }

    // Calculate the total cost based on the initial matching
    *minCost = 0;
    for (int i = 0; i < N; i++) {
        *minCost += costMatrix[i][ind[i]];
    }

    // Output the assignment
    for (int i = 0; i < N; i++) {
        assignment[i] = ind[i];
    }
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int assignment[N]; // Array to store the optimal assignment
    int minCost;

    // Find the optimal assignment and minimum cost
    hungarianAlgorithm(costMatrix, assignment, &minCost);

    // Print the results
    printf("The optimal assignment is:\n");
    for (int i = 0; i < N; i++) {
        printf("Task %d -> Agent %d\n", i, assignment[i]);
    }
    printf("The minimum cost is: %d\n", minCost);

    return 0;
}
