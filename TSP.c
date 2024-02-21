#include <stdio.h>

#define N 4 

int graph[N][N] = {
    {0, 10, 18, 7},
    {5, 0, 15, 9},
    {20, 10, 0, 15},
    {6, 8, 12, 0}
};

int visited[N];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int current, int count, int n) {
    if (count == n && graph[current][0] != 0) {
        return graph[current][0];
    }

    int ans = 999999;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[current][i] != 0) {
            visited[i] = 1;
            int temp = graph[current][i] + tsp(i, count + 1, n);
            ans = min(ans, temp);
            visited[i] = 0;
        }
    }

    return ans;
}

int main() {
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    visited[0] = 1; 

    int result = tsp(0, 1, N);

    printf("Minimum cost: %d\n", result);

    return 0;
}
