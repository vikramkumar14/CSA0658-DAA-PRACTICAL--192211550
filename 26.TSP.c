#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

int n, dist[MAX][MAX], memo[MAX][1 << MAX];

int tsp(int pos, int mask) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    if (memo[pos][mask] != -1)
        return memo[pos][mask];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city)))
            ans = ans < dist[pos][city] + tsp(city, mask | (1 << city)) ? ans : dist[pos][city] + tsp(city, mask | (1 << city));
    }

    return memo[pos][mask] = ans;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < (1 << MAX); j++)
            memo[i][j] = -1;

    printf("The minimum cost of the tour is %d\n", tsp(0, 1));

    return 0;
}