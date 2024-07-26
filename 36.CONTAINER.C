#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Function to find the first bin that can accommodate weight
int find_bin(int *bin_rem, int n_bins, int weight, int bin_capacity) {
    for (int i = 0; i < n_bins; i++) {
        if (bin_rem[i] >= weight) {
            return i;
        }
    }
    return -1;
}

// Function to solve the container loader problem
int container_loader(int *weights, int n_items, int bin_capacity) {
    qsort(weights, n_items, sizeof(int), compare);

    int *bin_rem = (int *)malloc(n_items * sizeof(int));
    int n_bins = 0;

    for (int i = 0; i < n_items; i++) {
        int bin_index = find_bin(bin_rem, n_bins, weights[i], bin_capacity);
        if (bin_index == -1) {
            bin_rem[n_bins] = bin_capacity - weights[i];
            n_bins++;
        } else {
            bin_rem[bin_index] -= weights[i];
        }
    }

    free(bin_rem);
    return n_bins;
}

int main() {
    int weights[] = {4, 8, 1, 4, 2, 1};
    int n_items = sizeof(weights) / sizeof(weights[0]);
    int bin_capacity = 10;

    int n_bins = container_loader(weights, n_items, bin_capacity);
    printf("Minimum number of bins required: %d\n", n_bins);

    return 0;
}
