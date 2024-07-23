#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compareItems(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;

    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;

    if (ratioA > ratioB) {
        return -1;
    } else if (ratioA < ratioB) {
        return 1;
    }
    return 0;
}

double fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)items[i].value * remainingCapacity / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity;
    int n;

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    double maxValue = fractionalKnapsack(capacity, items, n);

    printf("Maximum value that can be obtained: %.2lf\n", maxValue);

    return 0;
}