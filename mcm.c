#include <stdio.h>
#include <limits.h>
int matrixChainMultiplication(int p[], int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 1000;
        }
    }
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];
}
int main() {
    int p[] = {3, 4, 7, 8, 2};
    int n = sizeof(p) / sizeof(p[0]);
    printf("Minimum number of scalar multiplications: %d\n", matrixChainMultiplication(p, n));
    return 0;
}
