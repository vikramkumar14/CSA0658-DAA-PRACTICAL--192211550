#include <stdio.h>
#include <limits.h>

// Number of tasks and agents
#define N 4

// Function to find the minimum cost using Branch and Bound
void findMinCost(int costMatrix[N][N], int assigned[N], int agent, int *minCost, int currentCost) {
    // If all agents have been assigned tasks
    if (agent == N) {
        if (currentCost < *minCost) {
            *minCost = currentCost;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        // If the task is not already assigned
        if (!assigned[i]) {
            // Mark the task as assigned
            assigned[i] = 1;
            // Recursively assign the next agent
            findMinCost(costMatrix, assigned, agent + 1, minCost, currentCost + costMatrix[agent][i]);
            // Backtrack and unassign the task
            assigned[i] = 0;
        }
    }
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    // Array to keep track of assigned tasks
    int assigned[N] = {0};

    // Initialize minimum cost to a large value
    int minCost = INT_MAX;

    // Start the branch and bound process
    findMinCost(costMatrix, assigned, 0, &minCost, 0);

    // Print the minimum cost
    printf("The minimum cost is: %d\n", minCost);

    return 0;
}
